#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

struct Process {
    int pid;
    int arrival_time;
    int burst_time;
    int completion_time;
    int waiting_time;
    int turnaround_time;
};

bool compare_arrival_time(Process p1, Process p2) {
    return p1.arrival_time < p2.arrival_time;
}

void print_table(vector<Process> processes) {
    int n = processes.size();
    cout << "PID\tAT\tBT\tCT\tWT\tTAT" << endl;
    for (int i = 0; i < n; i++) {
        cout << processes[i].pid << "\t" << processes[i].arrival_time << "\t" << processes[i].burst_time << "\t" << processes[i].completion_time << "\t" << processes[i].waiting_time << "\t" << processes[i].turnaround_time << endl;
    }
}

void fcfs_scheduling(vector<Process> processes) {
    int n = processes.size();
    int current_time = 0;
    for (int i = 0; i < n; i++) {
        if (current_time < processes[i].arrival_time) {
            current_time = processes[i].arrival_time;
        }
        current_time += processes[i].burst_time;
        processes[i].completion_time = current_time;
        processes[i].turnaround_time = processes[i].completion_time - processes[i].arrival_time;
        processes[i].waiting_time = processes[i].turnaround_time - processes[i].burst_time;
    }
    print_table(processes);
}

int main() {
    int n;
    cout << "Enter the number of processes: ";
    cin >> n;

    vector<Process> processes(n);
    for (int i = 0; i < n; i++) {
        processes[i].pid = i + 1;
        cout << "Enter the arrival time of process " << i + 1 << ": ";
        cin >> processes[i].arrival_time;
        cout << "Enter the burst time of process " << i + 1 << ": ";
        cin >> processes[i].burst_time;
    }

    sort(processes.begin(), processes.end(), compare_arrival_time);

    fcfs_scheduling(processes);

    return 0;
}
