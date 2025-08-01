#include<iostream>
#include<bits/stdc++.h>
using namespace std;

int greedy(vector<int>&arr, int n){
    sort(arr.begin(),arr.end());
    int t=0;
    int wt =0;
    for (int i = 0; i < n; i++)
    {
        //how much time the current process has to wait before its execution
        wt = wt + t;
        //how much time the current process will take to excecute
        t = t + arr[i];
    }
    return (wt/n); //avg waiting time
}

int main()
{
    int n;
    cout<<"enter the no. of processes: ";
    cin>>n;
    vector<int>arr(n);
    for (int i = 0; i < n; i++)
    {
        cin>>arr[i];
    }

    cout<<greedy(arr,n);
    
    return 0;
}