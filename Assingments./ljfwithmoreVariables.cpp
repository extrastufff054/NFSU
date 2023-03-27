//Implementing longest job first in cpp with AT, BT, CT,RT
#include<bits/stdc++.h>
using namespace std;
int main()
{
    int n;
    cout<<"Enter the no of processes: ";
    cin>>n;
    int bt[n],wt[n],tat[n],p[n],i,j,at[n],ct[n],rt[n];
    float awt=0,atat=0,art=0;
    for(i=0;i<n;i++)
    {
        cout<<"Enter the arrival time of process "<<i+1<<": ";
        cin>>at[i];
        cout<<"Enter the burst time of process "<<i+1<<": ";
        cin>>bt[i];
        p[i]=i+1;
    } 
    for(i=0;i<n;i++)
    {
        for(j=0;j<n;j++)
        {
            if(bt[i]>bt[j])
            {
                swap(bt[i],bt[j]);
                swap(p[i],p[j]);
                swap(at[i],at[j]);
            }
        }
    }
    wt[0]=0;
    for(i=1;i<n;i++)
    {
        wt[i]=0;
        for(j=0;j<i;j++)
        wt[i]+=bt[j];
        awt+=wt[i];
    }
    cout<<" Process Arrival Time\t Burst Time \tWaiting Time \tTurnaround Time\tCompletion Time "<<endl;
    for(i=0;i<n;i++)
    {
        tat[i]=bt[i]+wt[i];
        atat+=tat[i];
        ct[i]=tat[i]+at[i];
        cout<<" P"<<p[i]<<"\t\t"<<at[i]<<"\t\t"<<bt[i]<<"\t\t"<<wt[i]<<"\t\t"<<tat[i]<<"\t\t"<<ct[i]<<endl;
    }
    awt/=i;
    atat/=i;
    cout<<"Average Waiting Time: "<<awt<<endl;
    cout<<"Average Turnaround Time: "<<atat<<endl;
    return 0;
}
