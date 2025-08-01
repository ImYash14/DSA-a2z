#include<iostream>
#include<bits/stdc++.h>
using namespace std;

int fun(vector<int>&arr,int n,int index, int jumps){
    if(index >= n-1) return jumps;//this is our base case and return only once

    int mini = INT_MAX;
    for (int i = 1; i <= arr[index]; i++)//no. of all possible jumps from a index
    {
        mini = min(mini, fun(arr,n,index+i,jumps+1));
    }
    return mini;//this will be recursively return for each call
}

int greedy(vector<int>&arr, int n){
    //using recursion we will find all possible paths 
    //and return that takes minimum no. of jumps
    return fun(arr,n,0,0);
}

int main()
{
    int n;
    cout<<"enter the size of arr: ";
    cin>>n;
    vector<int>arr(n);
    for (int i = 0; i < n; i++)
    {
        cin>>arr[i];
    }

    cout<<greedy(arr,n);
    return 0;
}