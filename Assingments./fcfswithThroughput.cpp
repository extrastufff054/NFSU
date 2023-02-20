#include <iostream>
#include <algorithm>

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

void print_table(Process processes[], int n, float avg_waiting_time, float avg_turnaround_time,float throughput,float CPU) {
    cout << "PID\tAT\tBT\tCT\tWT\tTAT" << endl;
    for (int i = 0; i < n; i++) {
        cout << processes[i].pid << "\t" << processes[i].arrival_time << "\t" << processes[i].burst_time << "\t" << processes[i].completion_time << "\t" << processes[i].waiting_time << "\t" << processes[i].turnaround_time << endl;
    }

    cout<<endl;
    cout<<"--------------------------------------------------------------------------------------------------------------------------------"<<endl;
    cout << "Average waiting time: " << avg_waiting_time << endl;
    cout << "Average turnaround time: " << avg_turnaround_time << endl;
    cout<<"Throughput : "<<throughput<<endl;
    cout<<"CPU Utilisation : "<<CPU<<endl;
    cout<<"--------------------------------------------------------------------------------------------------------------------------------"<<endl;
}

int sumofBT(int burst_time,int n)
{
    for(int i=0;i<n;i++)
    {
        int sum=sum+burst_time;
    }
}

void fcfs_scheduling(Process processes[], int n) {
    int current_time = 0;
    float total_waiting_time = 0, total_turnaround_time = 0;
    for (int i = 0; i < n; i++) {
        if (current_time < processes[i].arrival_time) {
            current_time = processes[i].arrival_time;
        }
        current_time += processes[i].burst_time;
        processes[i].completion_time = current_time;
        processes[i].turnaround_time = processes[i].completion_time - processes[i].arrival_time;
        processes[i].waiting_time = processes[i].turnaround_time - processes[i].burst_time;
        total_waiting_time += processes[i].waiting_time;
        total_turnaround_time += processes[i].turnaround_time;
    }
    cout<<endl;
    cout<<"--------------------------------------------------------------------------------------------------------------------------------------";
    cout<<endl;
    float avg_waiting_time = total_waiting_time / n;
    float avg_turnaround_time = total_turnaround_time / n;

    float throughput = (float)n/current_time;

    float CPU=(sumofBT(processes[n].burst_time, n)%current_time)*100;

    print_table(processes, n, avg_waiting_time, avg_turnaround_time,throughput,CPU);
}

int main() {
    int n;
    cout << "Enter the number of processes: ";
    cin >> n;

    Process processes[n];
    for (int i = 0; i < n; i++) {
        processes[i].pid = i + 1;
        cout << "Enter the arrival time of process " << i + 1 << ": ";
        cin >> processes[i].arrival_time;
        cout << "Enter the burst time of process " << i + 1 << ": ";
        cin >> processes[i].burst_time;
    }

    sort(processes, processes + n, compare_arrival_time);

    fcfs_scheduling(processes, n);

    return 0;
}
