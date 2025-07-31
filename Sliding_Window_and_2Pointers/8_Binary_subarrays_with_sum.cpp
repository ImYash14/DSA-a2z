#include<iostream>
#include<bits/stdc++.h>
using namespace std;

int fun(vector<int>&arr, int n, int goal){//for <=goal
    int l=0;
    int r=0;
    int count =0;
    int sum =0;
    while(r<n){
        sum = sum + arr[r];

        while(sum > goal){
            sum = sum-arr[l];
            l++;
        }

        count = count + (r-l+1);
        r++;
    }
    return count;
}

int optimal(vector<int>&arr,int n, int goal){
    return fun(arr,n,goal)-fun(arr,n,goal-1);
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

    int goal;
    cout<<"enter the goal: ";
    cin>>goal;

    cout<<optimal(arr,n,goal);
    
    return 0;
}