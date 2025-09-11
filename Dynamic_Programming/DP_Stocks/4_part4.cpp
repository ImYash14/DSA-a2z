#include<iostream>
#include<bits/stdc++.h>
using namespace std;

int recursion(int index, int trans,vector<int>&arr, int k){
    //base case
    if(index == arr.size() || trans == 2*k) return 0;

    int profit = 0;
    if(trans%2 == 0){//buy
        int buy = -arr[index] + recursion(index+1,trans+1,arr,k);
        int notbuy = 0 + recursion(index+1,trans,arr,k);
        profit = max(profit,max(buy,notbuy));
    }
    else{//sell
        int sell = arr[index] + recursion(index+1,trans+1,arr,k);
        int notsell = 0 + recursion(index+1,trans,arr,k);
        profit = max(profit,max(sell,notsell));
    }
    return profit;
}

int memoization(int index,int trans,vector<int>&arr,int k,vector<vector<int>>&dp){
    //base case
    if(index == arr.size() || trans == 2*k) return 0;

    if(dp[index][trans] != -1) return dp[index][trans];

    int profit = 0;
    if(trans%2 == 0){//buy
        int buy = -arr[index] + memoization(index+1,trans+1,arr,k,dp);
        int notbuy = 0 + memoization(index+1,trans,arr,k,dp);
        profit = max(profit,max(buy,notbuy));
    }
    else{//sell
        int sell = arr[index] + memoization(index+1,trans+1,arr,k,dp);
        int notsell = 0 + memoization(index+1,trans,arr,k,dp);
        profit = max(profit,max(sell,notsell));
    }
    return dp[index][trans] = profit;
}

int tabulation(int k, vector<int>&arr){
    int n = arr.size();

    vector<vector<int>>dp(n+1,vector<int>(2*k+1,0));
    //ignore base case bc already initialized 0

    //for loop for states in rev of recursion
    for (int i = n-1; i >=0; i--)//for index
    {
        for (int j = 0; j <= 2*k-1; j++)//for trans
        {
            int profit = 0;
            if(j%2 == 0){//buy
                int buy = -arr[i] + dp[i+1][j+1];
                int notbuy = 0 + dp[i+1][j];
                profit = max(profit,max(buy,notbuy));
            }
            else{//sell
                int sell = arr[i] + dp[i+1][j+1];
                int notsell = 0 + dp[i+1][j];
                profit = max(profit,max(sell,notsell));
            }
            dp[i][j] = profit;
        }
        
    }
    return dp[0][0];
}

int spaceopt(int k, vector<int>&arr){
    int n = arr.size();

    vector<int>front(2*k+1,0);
    vector<int>curr(2*k+1,0);
    //ignore base case bc already initialized 0

    //for loop for states in rev of recursion
    for (int i = n-1; i >=0; i--)//for index
    {
        for (int j = 0; j <= 2*k-1; j++)//for trans
        {
            int profit = 0;
            if(j%2 == 0){//buy
                int buy = -arr[i] + front[j+1];
                int notbuy = 0 + front[j];
                profit = max(profit,max(buy,notbuy));
            }
            else{//sell
                int sell = arr[i] + front[j+1];
                int notsell = 0 + front[j];
                profit = max(profit,max(sell,notsell));
            }
            curr[j] = profit;
        }
        front = curr;
    }
    return front[0];
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
    int k;
    cin>>k;

    // cout<<recursion(0,0,arr,k);
    // vector<vector<int>>dp(n,vector<int>(2*k,-1));
    // cout<<memoization(0,0,arr,k,dp);
    // cout<<tabulation(k,arr);
    cout<<spaceopt(k,arr);
    
    
    return 0;
}