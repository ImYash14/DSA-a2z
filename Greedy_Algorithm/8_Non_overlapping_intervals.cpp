#include<iostream>
#include<bits/stdc++.h>
using namespace std;

bool comp(vector<int>&a, vector<int>&b){//sort the arr based on end index
    return a[1] < b[1];
}

int greedy(vector<vector<int>>&arr, int n){
    //sort the arr based on end index
    sort(arr.begin(),arr.end(),comp);

    int count =1;
    int lastindex = arr[0][1];
    for (int i = 1; i < n; i++)
    {
        if(arr[i][0] >= lastindex){//for not overlapping intervals
            count = count+1;
            lastindex = arr[i][1];
        }
    }
    return n-count; //total-taken = removals
}

int main()
{
    int n;
    cout<<"enter the no. of intervals: ";
    cin>>n;
    vector<vector<int>>arr(n,vector<int>(2));
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j <= 1; j++)
        {
            cin>>arr[i][j];
        }
        
    }

    cout<<greedy(arr,n);
    
    return 0;
}