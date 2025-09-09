#include<iostream>
#include<bits/stdc++.h>
using namespace std;

int recursion(int index, int N,vector<int>&price){
    int n = price.size();

    //base case
    if(index == 0){
        if(N >= index+1){
            return (N/1)*price[index];
        }
        else return -1e9;
    }

    int notpick = 0 + recursion(index-1,N,price);
    int pick = -1e9;
    int rodlength = index+1;
    if(N >= rodlength){
        pick = price[index] + recursion(index,N-rodlength,price);
    }

    return max(pick, notpick);
}

int memoization(int index, int N,vector<int>&price,vector<vector<int>>&dp){
    int n = price.size();

    //base case
    if(index == 0){
        if(N >= index+1){
            return (N/1)*price[index];
        }
        else return -1e9;
    }

    if(dp[index][N] != -1) return dp[index][N];

    int notpick = 0 + memoization(index-1,N,price,dp);
    int pick = -1e9;
    int rodlength = index+1;
    if(N >= rodlength){
        pick = price[index] + memoization(index,N-rodlength,price,dp);
    }

    return dp[index][N] = max(pick, notpick);
}

int tabulation(int N,vector<int>&price){
    int n = price.size();

    vector<vector<int>>dp(n,vector<int>(N+1,0));
    //base case
    for (int i = 0; i <= N; i++)
    {
        if(i >= 1){
            dp[0][i] = (i/1)*price[0];
        }
        else dp[0][i] = -1e9;
    }

    //for loop for the states in reverse of recursion
    for (int i = 1; i < n; i++) //for index
    {
        for (int j = 0; j <= N; j++) //for len N
        {
            int notpick = 0 + dp[i-1][j];
            int pick = -1e9;
            int rodlength = i+1;
            if(j >= rodlength){
                pick = price[i] + dp[i][j-rodlength];
            }

            dp[i][j] = max(pick, notpick);
        }
        
    }
    return dp[n-1][N];   
}

int spaceopt1(int N,vector<int>&price){
    int n = price.size();

    vector<int>prev(N+1,0);
    //base case
    for (int i = 0; i <= N; i++)
    {
        if(i >= 1){
            prev[i] = (i/1)*price[0];
        }
        else prev[i] = -1e9;
    }

    //for loop for the states in reverse of recursion
    for (int i = 1; i < n; i++) //for index
    {
        vector<int>curr(N+1,0);
        for (int j = 0; j <= N; j++) //for len N
        {
            int notpick = 0 + prev[j];
            int pick = -1e9;
            int rodlength = i+1;
            if(j >= rodlength){
                pick = price[i] + curr[j-rodlength];
            }

            curr[j] = max(pick, notpick);
        }
        prev = curr;
    }
    return prev[N];   
}

int spaceopt2(int N,vector<int>&price){
    int n = price.size();

    vector<int>prev(N+1,0);
    //base case
    for (int i = 0; i <= N; i++)
    {
        if(i >= 1){
            prev[i] = (i/1)*price[0];
        }
        else prev[i] = -1e9;
    }

    //for loop for the states in reverse of recursion
    for (int i = 1; i < n; i++) //for index
    {
        // vector<int>curr(N+1,0);
        for (int j = 0; j <= N; j++) //for len N
        {
            int notpick = 0 + prev[j];
            int pick = -1e9;
            int rodlength = i+1;
            if(j >= rodlength){
                pick = price[i] + prev[j-rodlength];
            }

            prev[j] = max(pick, notpick);
        }
        // prev = curr;
    }
    return prev[N];   
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
    int N;
    cin>>N;

    // cout<<recursion(n-1,N,arr);
    // vector<vector<int>>dp(n,vector<int>(N+1,-1));
    // cout<<memoization(n-1,N,arr,dp);
    // cout<<tabulation(N,arr);
    cout<<spaceopt2(N,arr);
    
    return 0;
}