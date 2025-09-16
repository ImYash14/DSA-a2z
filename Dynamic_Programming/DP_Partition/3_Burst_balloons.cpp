#include<iostream>
#include<bits/stdc++.h>
using namespace std;

int recursion(int i, int j,vector<int>&arr){
    //base case
    if(i>j) return 0; //no subproblems left

    int maxi = -1e9;
    for (int k = i; k <=j; k++)
    {
        int cost = (arr[i-1]*arr[k]*arr[j+1]) + recursion(i,k-1,arr) 
                    + recursion(k+1,j,arr);
        maxi = max(maxi,cost);
    }
    return maxi;
}

int memoization(int i, int j,vector<int>&arr,vector<vector<int>>&dp){
    //base case
    if(i>j) return 0; //no subproblems left

    if(dp[i][j] != -1) return dp[i][j];

    int maxi = -1e9;
    for (int k = i; k <=j; k++)
    {
        int cost = (arr[i-1]*arr[k]*arr[j+1]) + memoization(i,k-1,arr,dp) 
                    + memoization(k+1,j,arr,dp);
        maxi = max(maxi,cost);
    }
    return dp[i][j] = maxi;
}

int burstBalloons(vector<int>&arr){
    int n = arr.size();

    arr.push_back(1);
    arr.insert(arr.begin(),1);

    // return recursion(1,n,arr);
    vector<vector<int>>dp(n+1,vector<int>(n+1,-1));
    return memoization(1,n,arr,dp);
}

int tabulation(vector<int>&arr){
    int n = arr.size();

    arr.push_back(1);
    arr.insert(arr.begin(),1);

    vector<vector<int>>dp(n+2,vector<int>(n+2,0));
    //base case already covered as 0

    //for loop for states in rev of recursion
    for (int i = n; i >=1; i--)
    {
        for (int j = 1; j <=n; j++)
        {
            if(i>j) continue;
            int maxi = -1e9;
            for (int k = i; k <=j; k++)
            {
                int cost = (arr[i-1]*arr[k]*arr[j+1]) + dp[i][k-1] + dp[k+1][j];
                maxi = max(maxi,cost);
            }
            dp[i][j] = maxi;
        }
        
    }
    return dp[1][n];
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
    
    // cout<<burstBalloons(arr);
    cout<<tabulation(arr);
    
    return 0;
}