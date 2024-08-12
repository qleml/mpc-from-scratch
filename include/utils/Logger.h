#include <string>
#include <vector>
#include <mutex>
#include <thread>
#include <queue>
#include <condition_variable>
#include <fstream> 

class Logger
{
public:
    Logger();
    ~Logger();

    void saveState(const std::vector<double>& state, double time);
    void log(const std::string& message);

private:
    void processQueue();

    std::string _folder;
    std::string _filename;
    std::ofstream _file;
    std::mutex _mutex;
    std::thread _loggingThread;
    std::queue<std::string> _logQueue;
    std::condition_variable _cv;
    bool _exit;
};