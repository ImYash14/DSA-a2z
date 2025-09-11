#include<iostream>
#include<bits/stdc++.h>
using namespace std;

int recursion(int index, int buy,int cap,vector<int>&arr){
    //base case
    if(cap == 0) return 0;
    if(index == arr.size()) return 0;

    //all possibilities to buy and sell
    int profit = 0;
    if(buy){
        int buying = -arr[index] + recursion(index+1,0,cap,arr);
        int notbuying = 0 + recursion(index+1,1,cap,arr);
        profit = max(profit,max(buying,notbuying));
    }
    else{
        int selling = arr[index] + recursion(index+1,1,cap-1,arr);
        int notselling = 0 + recursion(index+1,0,cap,arr);
        profit = max(profit,max(selling,notselling));
    }
    return profit;
}

int memoization(int index, int buy,int cap,vector<int>&arr,
    vector<vector<vector<int>>>&dp){
    //base case
    if(cap == 0) return 0;
    if(index == arr.size()) return 0;

    if(dp[index][buy][cap] != -1) return dp[index][buy][cap];

    //all possibilities to buy and sell
    int profit = 0;
    if(buy){
        int buying = -arr[index] + memoization(index+1,0,cap,arr,dp);
        int notbuying = 0 + memoization(index+1,1,cap,arr,dp);
        profit = max(profit,max(buying,notbuying));
    }
    else{
        int selling = arr[index] + memoization(index+1,1,cap-1,arr,dp);
        int notselling = 0 + memoization(index+1,0,cap,arr,dp);
        profit = max(profit,max(selling,notselling));
    }
    return dp[index][buy][cap] = profit;
}

int tabulation(vector<int>&arr){
    int n = arr.size();

    vector<vector<vector<int>>>dp(n+1,vector<vector<int>>(2,vector<int>(3,0)));
    //base case
    for (int i = 0; i <= n-1; i++)
    {
        for (int buy = 0; buy <= 1; buy++)
        {
            dp[i][buy][0] = 0;
        }
        
    }
    for (int buy = 0; buy <= 1; buy++)
    {
        for (int cap = 0; cap <= 2; cap++)
        {
            dp[n][buy][cap] = 0;
        }
        
    }
    //we can skip the base case bc already dp initialized with 0

    //for loop for states in rev of recursion
    for (int i = n-1; i >=0; i--)
    {
        for (int buy = 0; buy <= 1; buy++)
        {
            for (int cap = 1; cap <= 2; cap++)
            {
                int profit =0;
                if(buy){
                    int buying = -arr[i] + dp[i+1][0][cap];
                    int notbuying = 0 + dp[i+1][1][cap];
                    profit = max(profit,max(buying,notbuying));
                }
                else{
                    int selling = arr[i] + dp[i+1][1][cap-1];
                    int notselling = 0 + dp[i+1][0][cap];
                    profit = max(profit,max(selling,notselling));
                }
                dp[i][buy][cap] = profit;
            }
            
        }
        
    }
    return dp[0][1][2];    
}

int spaceopt(vector<int>&arr){
    int n = arr.size();

    vector<vector<int>>front(2,vector<int>(3,0));
    vector<vector<int>>curr(2,vector<int>(3,0));
    //base case
    //we can skip the base case bc already dp initialized with 0

    //for loop for states in rev of recursion
    for (int i = n-1; i >=0; i--)
    {
        for (int buy = 0; buy <= 1; buy++)
        {
            for (int cap = 1; cap <= 2; cap++)
            {
                int profit =0;
                if(buy){
                    int buying = -arr[i] + front[0][cap];
                    int notbuying = 0 + front[1][cap];
                    profit = max(profit,max(buying,notbuying));
                }
                else{
                    int selling = arr[i] + front[1][cap-1];
                    int notselling = 0 + front[0][cap];
                    profit = max(profit,max(selling,notselling));
                }
                curr[buy][cap] = profit;
            }
            
        }
        front = curr;
    }
    return front[1][2];    
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
    
    // cout<<recursion(0,1,2,arr);
    // vector<vector<vector<int>>>dp(n,vector<vector<int>>(2,vector<int>(3,-1)));
    // cout<<memoization(0,1,2,arr,dp);
    // cout<<tabulation(arr);
    cout<<spaceopt(arr);
    
    return 0;
}