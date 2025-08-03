#include<iostream>
#include<bits/stdc++.h>
using namespace std;

vector<vector<int>>greedy(vector<vector<int>>&arr, vector<int>&newint, int n){
    vector<vector<int>>ans;
    int i =0;

    //for the left half
    while(i<n && arr[i][1] < newint[0]){
        ans.push_back(arr[i]);
        i++;
    }

    //for the mid half
    while(i<n && arr[i][0] <= newint[1]){
        newint[0] = min(newint[0],arr[i][0]);
        newint[1] = max(newint[1],arr[i][1]);
        i++;
    }
    ans.push_back(newint);

    //for the right half
    while(i<n){
        ans.push_back(arr[i]);
        i++;
    }
    return ans;
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

    cout<<"enter the new interval to be inserted: ";
    vector<int>newint(2);
    cin>>newint[0];
    cin>>newint[1];

    vector<vector<int>>output = greedy(arr,newint,n);
    for(auto it: output){
        for(int num : it){
            cout<<num<<" ";
        }
    }

    return 0;
}