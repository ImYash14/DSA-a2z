#include<iostream>
#include<bits/stdc++.h>
using namespace std;

int recursion(int index, int target, vector<int>&arr){
    int n = arr.size();

    //base case
    if(index == 0){
        if((target % arr[index]) == 0) return 1;
        else return 0;
    }

    int notpick = recursion(index-1,target,arr);
    int pick = 0;
    if(target >= arr[index]){
        pick = recursion(index, target - arr[index], arr);
    }

    return pick + notpick;
}

int memoization(int index, int target, vector<int>&arr, vector<vector<int>>&dp){
    int n = arr.size();

    //base case
    if(index == 0){
        if((target % arr[index]) == 0) return 1;
        else return 0;
    }

    if(dp[index][target] != -1) return dp[index][target];

    int notpick = memoization(index-1,target,arr,dp);
    int pick = 0;
    if(target >= arr[index]){
        pick = memoization(index, target - arr[index], arr,dp);
    }

    return dp[index][target] = pick + notpick;
}

int tabulation(int target, vector<int>&arr){
    int n = arr.size();

    vector<vector<int>>dp(n,vector<int>(target+1,0));
    //base case
    for (int i = 0; i <= target; i++)
    {
        if((i % arr[0]) == 0){
            dp[0][i] = 1;
        }
        else dp[0][i] = 0;
    }

    //for loop for states in reverse of recursion
    for (int i = 1; i < n; i++) //for index
    {
        for (int j = 0; j <= target; j++) //for target
        {
            int notpick = dp[i-1][j];
            int pick = 0;
            if(j >= arr[i]){
                pick = dp[i][j-arr[i]];
            }

            dp[i][j] = pick + notpick;
        }
        
    }
    return dp[n-1][target];
}

int spaceopt(int target, vector<int>&arr){
    int n = arr.size();

    vector<int>prev(target+1,0);
    //base case
    for (int i = 0; i <= target; i++)
    {
        if((i % arr[0]) == 0){
            prev[i] = 1;
        }
        else prev[i] = 0;
    }

    //for loop for states in reverse of recursion
    for (int i = 1; i < n; i++) //for index
    {
        vector<int>curr(target+1,0);
        for (int j = 0; j <= target; j++) //for target
        {
            int notpick = prev[j];
            int pick = 0;
            if(j >= arr[i]){
                pick = curr[j-arr[i]];
            }

            curr[j] = pick + notpick;
        }
        prev = curr;
    }
    return prev[target];
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
    int target;
    cin>>target;

    // cout<<recursion(n-1,target,arr);
    // vector<vector<int>>dp(n,vector<int>(target+1,-1));
    // cout<<memoization(n-1,target,arr,dp);
    // cout<<tabulation(target,arr);
    cout<<spaceopt(target,arr);
    
    return 0;
}