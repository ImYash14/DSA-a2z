#include<iostream>
#include<bits/stdc++.h>
using namespace std;

int recursion(int index, vector<int>&arr){
    if(index == 0) return 0; //energy req to reach 0 from 0 will be 0

    //energy req to jump from index tp index-1
    //and the recursion will tell us for index-1 to 0
    int left = recursion(index-1, arr) + abs(arr[index] - arr[index-1]);

    //energy req to from index to index-2
    int right = INT_MAX;
    if(index > 1)
    {
        right = recursion(index-2, arr) + abs(arr[index] - arr[index-2]);
    }

    return min(left, right);
}

int memoization(int index, vector<int>&arr, vector<int>&dp){
    if(index == 0) return 0;

    //if this subproblem is already solved
    if(dp[index] != -1) return dp[index];

    //else
    int left = memoization(index-1,arr,dp) + abs(arr[index] - arr[index-1]);
    int right = INT_MAX;
    if(index > 1){
        right = memoization(index-2,arr,dp) + abs(arr[index] - arr[index-2]);
    }

    return dp[index] = min(left,right);
}

int tabulation(int n,vector<int>&arr, vector<int>&dp){
    dp[0] = 0;

    for (int i = 1; i <= n-1; i++)
    {
        int left = dp[i-1] + abs(arr[i] - arr[i-1]);
        int right = INT_MAX;
        if(i > 1){
            right = dp[i-2] + abs(arr[i] - arr[i-2]);
        }
        dp[i] = min(left,right);
    }
    return dp[n-1];
}

int spaceopt(int n, vector<int>&arr){
    int prev = 0; //dp[i-1]
    int prev2 = 0; //dp[i-2]

    for (int i = 1; i <= n-1; i++)
    {
        int left = prev + abs(arr[i] - arr[i-1]);
        int right = INT_MAX;
        if(i > 1){
            right = prev2 + abs(arr[i] - arr[i-2]);
        }

        int curr = min(left,right);
        prev2 = prev;
        prev = curr;
    }
    return prev;
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

    // cout<<recursion(n-1,arr); //min energy req to reach (n-1)th step from 0
    vector<int>dp(n,-1);
    cout<<memoization(n-1,arr,dp);
    
    return 0;
}