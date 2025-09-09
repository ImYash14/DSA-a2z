#include<iostream>
#include<bits/stdc++.h>
using namespace std;

int recursion(int index, int target,vector<int>&arr){
    int n = arr.size();

    //base case
    // if(target == 0) return 1;
    if(index == 0){
        if((target % arr[index]) == 0){
            return target/arr[index];
        }
        else return 1e9;
    }

    int nottake = 0 + recursion(index-1,target,arr);
    int take = 1e9;
    if(target >= arr[index]){
        take = 1 + recursion(index,target-arr[index],arr);
    }

    return min(take,nottake);
}

int memoization(int index, int target,vector<int>&arr,vector<vector<int>>&dp){
    int n = arr.size();

    //base case
    // if(target == 0) return 1;
    if(index == 0){
        if((target % arr[index]) == 0){
            return target/arr[index];
        }
        else return 1e9;
    }

    if(dp[index][target] != -1) return dp[index][target];

    int nottake = 0 + recursion(index-1,target,arr);
    int take = 1e9;
    if(target >= arr[index]){
        take = 1 + recursion(index,target-arr[index],arr);
    }

    return dp[index][target] = min(take,nottake);
}

int tabulation(int target,vector<int>&arr){
    int n = arr.size();

    vector<vector<int>>dp(n,vector<int>(target+1,-1));
    //base case
    for (int i = 0; i <= target; i++)
    {
        if((i % arr[0]) == 0){
            dp[0][i] = i/arr[0];
        }
        else dp[0][i] = 1e9;
    }

    //for loop for the states in reverse of recursion
    for (int i = 1; i < n; i++) //for index
    {
        for (int j = 0; j <= target; j++) //for target
        {
            int nottake = 0 + dp[i-1][j];
            int take = 1e9;
            if(j >= arr[i]){
                take = 1 + dp[i][j-arr[i]];
            }

            dp[i][j] = min(take, nottake);
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
            prev[i] = i/arr[0];
        }
        else prev[i] = 1e9;
    }

    //for loop for the states in reverse of recursion
    for (int i = 1; i < n; i++) //for index
    {
        vector<int>curr(target+1,0);
        for (int j = 0; j <= target; j++) //for target
        {
            int nottake = 0 + prev[j];
            int take = 1e9;
            if(j >= arr[i]){
                take = 1 + curr[j-arr[i]];
            }

            curr[j] = min(take, nottake);
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
    cout<<tabulation(target,arr);
    // cout<<spaceopt(target,arr);
    
    return 0;
}