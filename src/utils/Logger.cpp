#include <Logger.h>
#include <chrono>
#include <ctime>
#include <fstream>
#include <iomanip>
#include <sstream>
#include <stdexcept>
#include <string>
#include <thread>
#include <filesystem> // Include filesystem library

Logger::Logger()
    : _exit(false)
{
    auto now = std::chrono::system_clock::now();
    auto in_time_t = std::chrono::system_clock::to_time_t(now);
    std::stringstream ss;
    ss << std::put_time(std::localtime(&in_time_t), "%Y-%m-%d_%H-%M-%S");
    _folder = "logs/" + ss.str();
    
    // Create the directory if it doesn't exist
    std::filesystem::create_directories(_folder);

    _filename = _folder + "/log.csv";
    _file.open(_filename, std::ios::out | std::ios::app);
    if (!_file.is_open())
    {
        throw std::runtime_error("Error: Could not open file " + _filename + " for writing.");
    }

    _loggingThread = std::thread(&Logger::processQueue, this);
}

Logger::~Logger()
{
    {
        std::lock_guard<std::mutex> lock(_mutex);
        _exit = true;
    }
    _cv.notify_all();
    _loggingThread.join();
    if (_file.is_open())
    {
        _file.close();
    }
}

void Logger::saveState(const std::vector<double>& state, double time)
{
    if (state.size() != 3)
    {
        throw std::invalid_argument("State vector must contain exactly 3 elements: position, velocity, and acceleration.");
    }

    std::stringstream ss;
    ss << time << "," << state[0] << "," << state[1] << "," << state[2] << "\n";
    log(ss.str());
}

void Logger::log(const std::string& message)
{
    {
        std::lock_guard<std::mutex> lock(_mutex);
        _logQueue.push(message);
    }
    _cv.notify_one();
}

void Logger::processQueue()
{
    while (true)
    {
        std::unique_lock<std::mutex> lock(_mutex);
        _cv.wait(lock, [this] { return !_logQueue.empty() || _exit; });

        while (!_logQueue.empty())
        {
            _file << _logQueue.front();
            _logQueue.pop();
        }

        if (_exit && _logQueue.empty())
        {
            break;
        }
    }
}