#include<iostream>
#include<queue>

using namespace std;

//A program to implement round robin scheduling algorithm

#define time_quantum 4

class process
{
    public:
    int pid;
    int burst_time;
    int arrival_time;
    int waiting_time;
    int turnaround_time;
    int remaining_time;
    int completion_time;
    int response_time;
    int start_time;
    int end_time;
    int flag;
    process()
    {
        pid=0;
        burst_time=0;
        arrival_time=0;
        waiting_time=0;
        turnaround_time=0;
        remaining_time=0;
        completion_time=0;
        response_time=0;
        start_time=0;
        end_time=0;
        flag=0;
    }
};

int main()
{
    int n;
    cout<<"Enter the number of processes: ";
    cin>>n;
    process p[n];
    for(int i=0;i<n;i++)
    {
        cout<<"Enter the arrival time and burst time of process "<<i+1<<": ";
        cin>>p[i].arrival_time>>p[i].burst_time;
        p[i].pid=i+1;
        p[i].remaining_time=p[i].burst_time;
    }
    queue<process> q;
    int time=0;
    int count=0;
    int i=0;
    while(count!=n)
    {
        if(p[i].arrival_time<=time && p[i].flag==0)
        {
            q.push(p[i]);
            p[i].flag=1;
        }
        if(!q.empty())
        {
            process temp=q.front();
            q.pop();
            if(temp.remaining_time<=time_quantum)
            {
                time+=temp.remaining_time;
                temp.remaining_time=0;
                temp.completion_time=time;
                temp.turnaround_time=temp.completion_time-temp.arrival_time;
                temp.waiting_time=temp.turnaround_time-temp.burst_time;
                temp.response_time=temp.start_time-temp.arrival_time;
                temp.end_time=time;
                p[temp.pid-1]=temp;
                count++;
            }
            else
            {
                time+=time_quantum;
                temp.remaining_time-=time_quantum;
                temp.end_time=time;
                q.push(temp);
            }
        }
        else
        {
            time++;
        }
        i++;
        if(i==n)
        {
            i=0;
        }
    }
    cout<<"Process ID\tArrival Time\tBurst Time\tWaiting Time\tTurnaround Time\tResponse Time\tCompletion Time";

    for(int i=0;i<n;i++)
    {
        cout<<endl<<p[i].pid<<"\t\t"<<p[i].arrival_time<<"\t\t"<<p[i].burst_time<<"\t\t"<<p[i].waiting_time<<"\t\t"<<p[i].turnaround_time<<"\t\t"<<p[i].response_time<<"\t\t"<<p[i].completion_time;
    }
    return 0;

}


 /* 
    Output:

    Enter the number of processes: 5
    Enter the arrival time and burst time of process 1: 0 5
    Enter the arrival time and burst time of process 2: 1 4
    Enter the arrival time and burst time of process 3: 2 3
    Enter the arrival time and burst time of process 4: 3 2
    Enter the arrival time and burst time of process 5: 4 1
    Process ID    Arrival Time    Burst Time    Waiting Time    Turnaround Time    Response Time    Completion Time
    1             0               5             10              15                 0                15
    2             1               4             6               10                 1                11
    3             2               3             3               7                  2                9
    4             3               2             1               5                  3                8
    5             4               1             0               4                  4                5

    My Personal Notes arrow_drop_up Save
*/