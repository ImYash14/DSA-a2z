#include<iostream>
#include<bits/stdc++.h>
using namespace std;

int recursion(int i, int j, vector<int>&arr){
    //base case
    if(i == j) return 0; //single matrix

    //try all partitions
    int mini = 1e9;
    for (int k = i; k <= j-1; k++)
    {
        int steps = arr[i-1]*arr[k]*arr[j] + recursion(i,k,arr) 
                    + recursion(k+1,j,arr);
        mini = min(mini,steps);
    }
    return mini;
}

int memoization(int i, int j, vector<int>&arr,vector<vector<int>>&dp){
    //base case
    if(i == j) return 0; //single matrix

    if(dp[i][j] != -1) return dp[i][j];

    //try all partitions
    int mini = 1e9;
    for (int k = i; k <= j-1; k++)
    {
        int steps = arr[i-1]*arr[k]*arr[j] + memoization(i,k,arr,dp) 
                    + memoization(k+1,j,arr,dp);
        mini = min(mini,steps);
    }
    return dp[i][j] = mini;
}

int tabulation(vector<int>&arr){
    int n = arr.size();

    vector<vector<int>>dp(n,vector<int>(n,0));
    //base case
    for (int i = 1; i < n; i++)
    {
        dp[i][i] = 0;
    }

    //for loop for states in rev of recursion
    for (int i = n-1; i >= 1; i--)
    {
        for (int j = i+1; j <= n-1; j++)
        {
            int mini = 1e9;
            for (int k = i; k <= j-1; k++)
            {
                int steps = arr[i-1]*arr[k]*arr[j] + dp[i][k] 
                            + dp[k+1][j];
                mini = min(mini,steps);
            }
            dp[i][j] = mini;
        }
        
    }
    return dp[1][n-1];   
}

int main()
{
    int n;
    cin>>n;
    vector<int>arr(n);
    for (int i = 0; i < n; i++)
    {
        cin>>arr[i];
    }
    
    // cout<<recursion(1,n-1,arr);
    // vector<vector<int>>dp(n,vector<int>(n,-1));
    // cout<<memoization(1,n-1,arr,dp);
    cout<<tabulation(arr);
    
    return 0;
}