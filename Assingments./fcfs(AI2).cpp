#include <iostream>
#include <queue>
#include <vector>

using namespace std;

struct Process {
    int pid;
    int burst_time;
    int priority;
};

// comparator function for the priority queue
class Compare {
public:
    bool operator() (const Process& p1, const Process& p2) {
        return p1.priority < p2.priority;
    }
};

int main() {
    int n; // number of processes
    int quantum; // time quantum for Round Robin
    cout << "Enter the number of processes: ";
    cin >> n;
    cout << "Enter the time quantum for Round Robin: ";
    cin >> quantum;
    
    // input the burst time and priority of each process
    vector<Process> processes(n);
    for (int i = 0; i < n; i++) {
        cout << "Enter the burst time and priority of process " << i << ": ";
        cin >> processes[i].burst_time >> processes[i].priority;
        processes[i].pid = i;
    }
    
    // sort the processes by priority
    priority_queue<Process, vector<Process>, Compare> pq;
    for (int i = 0; i < n; i++) {
        pq.push(processes[i]);
    }
    
    // run the Round Robin algorithm
    int time = 0;
    while (!pq.empty()) {
        Process p = pq.top();
        pq.pop();
        
        cout << "Running process " << p.pid << " for " << min(quantum, p.burst_time) << " units" << endl;
        time += min(quantum, p.burst_time);
        p.burst_time -= min(quantum, p.burst_time);
        
        if (p.burst_time > 0) {
            pq.push(p);
        }
    }
    
    cout << "Total time taken: " << time << endl;
    
    return 0;
}
