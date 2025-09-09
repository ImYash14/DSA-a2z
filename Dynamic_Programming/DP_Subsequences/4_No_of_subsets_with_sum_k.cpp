#include<iostream>
#include<bits/stdc++.h>
using namespace std;

int recursion(int index,int sum,vector<int>&arr){
    int n = arr.size();

    //base case
    if(sum == 0) return 1;
    if(index == 0){
        if(arr[index] == sum) return 1;
        else return 0;
    }

    int notpick = recursion(index-1,sum,arr);
    int pick = 0;
    if(arr[index] <= sum){
        pick = recursion(index-1, sum-arr[index],arr);
    }

    return pick + notpick;
}

int memoization(int index, int sum,vector<vector<int>>&dp, vector<int>&arr){
    int n = arr.size();

    //base case
    if(sum == 0) return 1;
    if(index == 0){
        if(arr[index] == sum) return 1;
        else return 0;
    }

    if(dp[index][sum] != -1) return dp[index][sum];

    int notpick = memoization(index-1,sum,dp,arr);
    int pick = 0;
    if(arr[index] <= sum){
        pick = memoization(index-1, sum-arr[index],dp,arr);
    }

    return dp[index][sum] = pick + notpick;
}

int tabulation(vector<int>&arr, int sum){
    int n = arr.size();

    vector<vector<int>>dp(n,vector<int>(sum+1,0));
    //base case
    for (int i = 0; i < n; i++)
    {
        dp[i][0] = 1;
    }
    if(arr[0] <= sum) dp[0][arr[0]] = 1;

    //for loop for states in reverse of recursion
    for (int i = 1; i < n; i++) //for index
    {
        for (int j = 1; j <= sum; j++) //for sum
        {
            int notpick = dp[i-1][j];
            int pick =0;
            if(arr[i] <= j){
                pick = dp[i-1][j-arr[i]];
            }
            dp[i][j] = pick + notpick;
        }
        
    }
    return dp[n-1][sum];    
}

int spaceopt(vector<int>&arr, int sum){
    int n = arr.size();

    vector<int>prev(sum+1,0);
    prev[0] = 1;
    vector<int>curr(sum+1,0);
    curr[0] = 1;
    if(arr[0] <= sum) curr[arr[0]] = 1;

    //for loop for states in reverse of recursion
    for (int i = 1; i < n; i++) //for index
    {
        for (int j = 0; j <= sum; j++) //for sum
        {
            int notpick = prev[j];
            int pick =0;
            if(arr[i] <= j){
                pick = prev[j-arr[i]];
            }
            curr[j] = pick + notpick;
        }
        prev = curr;
    }
    return prev[sum];
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
    int sum;
    cin>>sum;

    // cout<<recursion(n-1,sum,arr);
    // vector<vector<int>>dp(n,vector<int>(sum+1,-1));
    // cout<<memoization(n-1,sum,dp,arr);
    // cout<<tabulation(arr,sum);
    cout<<spaceopt(arr,sum);
    
    return 0;
}