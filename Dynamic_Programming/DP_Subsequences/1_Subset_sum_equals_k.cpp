#include<iostream>
#include<bits/stdc++.h>
using namespace std;

bool recursion(int index,int target,vector<int>&arr){
    int n = arr.size();

    //base case
    if(target == 0) return true;
    if(index == 0){
        if(arr[index] == target) return true;
    }

    bool nottake = recursion(index-1,target,arr);
    bool take = false;
    if(target >= arr[index]){
        take = recursion(index-1,target-arr[index],arr);
    }

    return (take | nottake);

}

bool memoization(int index,int target,vector<vector<int>>&dp,vector<int>&arr){
    int n = arr.size();

    //base case
    if(target == 0) return true;
    if(index == 0){
        if(arr[index] == target) return true;
    }

    if(dp[index][target] != -1) return dp[index][target];

    bool nottake = recursion(index-1,target,arr);
    bool take = false;
    if(target >= arr[index]){
        take = recursion(index-1,target-arr[index],arr);
    }

    return dp[index][target] = (take | nottake);
}

bool tabulation(vector<int>&arr,int target){
    int n = arr.size();

    vector<vector<bool>>dp(n,vector<bool>(target+1,0));

    //base case
    for (int i = 0; i < n; i++)
    {
        dp[i][0] = true;
    }
    dp[0][arr[0]] = true;

    //for loop for states
    for (int index = 1; index < n; index++)
    {
        for (int k = 1; k <= target; k++)
        {
            bool nottake = dp[index-1][k];
            bool take = false;
            if(target >= arr[index]){
                take = dp[index-1][k-arr[index]];
            }
            dp[index][k] = (take | nottake);
        }
    }
    return dp[n-1][target];    
}

bool spaceopt(vector<int>&arr, int target){
    int n = arr.size();

    vector<bool>prev(target+1,0);
    prev[0] = true;

    //for loop for states
    for (int index = 1; index < n; index++)
    {
        vector<bool>curr(target+1,0);
        curr[0] = true;
        for (int k = 1; k <= target; k++)
        {
            bool nottake = prev[k];
            bool take = false;
            if(target >= arr[index]){
                take = prev[k-arr[index]];
            }
            curr[k] = (take | nottake);
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
    // cout<<recursion(n-1,4,arr);
    // vector<vector<int>>dp(n,vector<int>(target+1,-1));
    // cout<<memoization(n-1,target,dp,arr);
    cout<<tabulation(arr,target);
    
    return 0;
}