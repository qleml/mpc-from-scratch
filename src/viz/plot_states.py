import csv
import argparse
import glob
import os
import matplotlib.pyplot as plt

def get_latest_log_file(logs_dir):
    log_files = glob.glob(os.path.join(logs_dir, '**', 'log.csv'), recursive=True)
    if not log_files:
        raise FileNotFoundError("No log files found in the specified directory.")
    latest_log_file = max(log_files, key=os.path.getmtime)
    return latest_log_file

def plot_states(log_file):
    times = []
    positions = []
    velocities = []
    accelerations = []

    with open(log_file, 'r') as file:
        reader = csv.reader(file)
        next(reader)  # Skip header row

        for row in reader:
            times.append(float(row[0]))
            positions.append(float(row[1]))
            velocities.append(float(row[2]))
            accelerations.append(float(row[3]))

    plt.figure(figsize=(10, 6))
    plt.plot(times, positions, label='Position')
    plt.plot(times, velocities, label='Velocity')
    plt.plot(times, accelerations, label='Acceleration')
    plt.xlabel('Time')
    plt.ylabel('Value')
    plt.title('States Plot')
    plt.legend()
    plt.grid(True)
    plt.show()

def main():
    parser = argparse.ArgumentParser(description='Plot states from a log file.')
    parser.add_argument('--log_file', type=str, help='Path to the log file.')
    args = parser.parse_args()

    if args.log_file:
        log_file = args.log_file
    else:
        logs_dir = '/Users/clemenschristoph/dev/mpc-from-scratch/build/logs'
        log_file = get_latest_log_file(logs_dir)

    plot_states(log_file)

if __name__ == '__main__':
    main()