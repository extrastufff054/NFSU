//Implementing LJF algorithm with AT, BT, CT, TAT, WT,RT, and gaant chart
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
}