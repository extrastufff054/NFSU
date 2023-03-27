    //Implementing longest job first in cpp
    #include<iostream>
    using namespace std;
    int main()
{
    int n;
    cout<<"Enter the number of processes: ";
    cin>>n;
    int bt[n],wt[n],tat[n],p[n],i,j;
    float awt=0,atat=0;
    for(i=0;i<n;i++)
    {
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
    cout<<" Process Burst Time Waiting Time Turnaround Time "<<endl;
    for(i=0;i<n;i++)
    {
        tat[i]=bt[i]+wt[i];
        atat+=tat[i];
        cout<<" P"<<p[i]<<"\t\t"<<bt[i]<<"\t\t"<<wt[i]<<"\t\t"<<tat[i]<<endl;
    }
    awt/=i;
    atat/=i;
    cout<<"Average Waiting Time: "<<awt<<endl;
    cout<<"Average Turnaround Time: "<<atat<<endl;
    return 0;
}
