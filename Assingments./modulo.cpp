#include<bits/stdc++.h>
using namespace std;

// int mod()
// {
//         remainder=dividend - (divisor*quotient);
// }

int max_subarraysumModulo(int arr[], int n, int m)
{
    int prefix=0;
    int maxSum=0;

    for(int i=0;i<n;i++)
    {
        prefix=(prefix+arr[i])% m;
        maxSum=max(maxSum, prefix);

        int j=upper_bound(arr,arr+i, arr[i])-arr;
        if(j>0)
        {
            maxSum=max(maxSum, (prefix-arr[j-1]+m)%m);
        }
    }
    return maxSum;
}

int main()
{
    int n;
    cout<<"Enter the size of the array : ";
    cin>>n;
    int arr[n];

    for(int i=0;i<n;i++)
    {
        cout<<"Enter the elements of the array: ";
        cin>>arr[i];
    }

    int m=10;

    int result=max_subarraysumModulo(arr, n,m);
    cout<<endl;
    cout<<"-----------------------------------------------------------------------------------------------------------------------------------------------------------------"<<endl;
    cout<<"The maximum subarray sum modulo "<<m<<" is : "<<result<<endl;

    return 0;
}


