#include<iostream>
#include<bits/stdc++.h>
using namespace std;

bool tabulation(vector<int>&arr,int target,vector<vector<bool>>&dp){
    int n = arr.size();

    // vector<vector<bool>>dp(n,vector<bool>(target+1,0));

    //base case
    for (int i = 0; i < n; i++)
    {
        dp[i][0] = true;
    }
    if(arr[0] <= target) dp[0][arr[0]] = true;

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

int minAbsDifference(vector<int>&arr,int D){
    int n = arr.size();

    int sum = accumulate(arr.begin(),arr.end(),0);

    vector<vector<bool>>dp(n,vector<bool>(sum+1,0));
    tabulation(arr,sum,dp);

    // int mini = INT_MAX;
    int count =0;
    for (int i = 0; i <= sum; i++)
    {
        if(dp[n-1][i] == true){
            int s1 = i;
            int s2 = sum - s1;
            if(s1 > s2 && s1-s2 == D) count++;
            // mini = min(mini, abs(s1-s2));
        }
    }
    return count;
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
    
    cout<<minAbsDifference(arr,3);
    
    return 0;
}