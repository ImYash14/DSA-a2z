#include<iostream>
#include<bits/stdc++.h>
using namespace std;

int recursion(int index, int buy,vector<int>&arr){
    //base case
    if(index >= arr.size()) return 0;

    //all possibilities to buy and sell
    int profit = 0;
    //buy = 1 means can buy on that day
    //buy = 0 means cannot buy on that day
    if(buy){
        int buying = -arr[index] + recursion(index+1,0,arr);
        int notbuying = 0 + recursion(index+1,1,arr);
        profit = max(profit,max(buying,notbuying));
    }
    else{
        int selling = arr[index] + recursion(index+2,1,arr);
        int notselling = 0 + recursion(index+1,0,arr);
        profit = max(profit,max(selling,notselling));
    }
    return profit;
}

int memoization(int index, int buy,vector<int>&arr,vector<vector<int>>&dp){
    //base case
    if(index >= arr.size()) return 0;

    if(dp[index][buy] != -1) return dp[index][buy];

    //all possibilities to buy and sell
    int profit = 0;
    //buy = 1 means can buy on that day
    //buy = 0 means cannot buy on that day
    if(buy){
        int buying = -arr[index] + memoization(index+1,0,arr,dp);
        int notbuying = 0 + memoization(index+1,1,arr,dp);
        profit = max(profit,max(buying,notbuying));
    }
    else{
        int selling = arr[index] + memoization(index+2,1,arr,dp);
        int notselling = 0 + memoization(index+1,0,arr,dp);
        profit = max(profit,max(selling,notselling));
    }
    return dp[index][buy] = profit;
}

int tabulation(vector<int>&arr){
    int n = arr.size();

    vector<vector<int>>dp(n+2,vector<int>(2,0));
    //base case
    // dp[n][0] = 0;
    // dp[n][1] = 0;

    //for loop for states in revsers of recursion
    for (int i = n-1; i >=0; i--)//for index
    {
        for (int j = 0; j <= 1; j++)//for buy
        {
            int profit =0;
            if(j){
                int buying = -arr[i] + dp[i+1][0];
                int notbuying = 0 + dp[i+1][1];
                profit = max(profit,max(buying,notbuying));
            }
            else{
                int selling = arr[i] + dp[i+2][1];
                int notselling = 0 + dp[i+1][0];
                profit = max(profit,max(selling,notselling));
            }
            dp[i][j] = profit;
        }
        
    }
    return dp[0][1];
}

int spaceopt(vector<int>&arr){
    int n = arr.size();

    vector<int>front1(2,0);
    vector<int>front2(2,0);
    vector<int>curr(2,0);
    //base case
    // dp[n][0] = 0;
    // dp[n][1] = 0;

    //for loop for states in revsers of recursion
    for (int i = n-1; i >=0; i--)//for index
    {
        for (int j = 0; j <= 1; j++)//for buy
        {
            int profit =0;
            if(j){
                int buying = -arr[i] + front1[0];
                int notbuying = 0 + front1[1];
                profit = max(profit,max(buying,notbuying));
            }
            else{
                int selling = arr[i] + front2[1];
                int notselling = 0 + front1[0];
                profit = max(profit,max(selling,notselling));
            }
            curr[j] = profit;
        }
        front2 = front1;
        front1 = curr;
    }
    return front1[1];
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
    
    // cout<<recursion(0,1,arr);
    // vector<vector<int>>dp(n,vector<int>(2,-1));
    // cout<<memoization(0,1,arr,dp);
    // cout<<tabulation(arr);
    cout<<spaceopt(arr);
    
    return 0;
}