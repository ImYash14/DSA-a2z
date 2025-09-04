#include<iostream>
#include<bits/stdc++.h>
using namespace std;

//Recursion
int recursion(int index){
    if(index == 0) return 1; //top to bottom
    if(index == 1) return 1; //edge case

    int left = recursion(index-1); //if we climb one step
    int right = recursion(index-2); //if we climb two step

    return left+right;
}

int memoization(int index, vector<int>&dp){
    if(index == 0) return 1;
    if(index == 1) return 1;

    if(dp[index] != -1) return dp[index];

    return dp[index] = memoization(index-1,dp) + memoization(index-2,dp);
}

int tabulation(int index, vector<int>&dp){
    dp[0] = 1;
    dp[1] = 1;

    for (int i = 2; i <= index; i++)
    {
        dp[i] = dp[i-1] + dp[i-2];
    }
    return dp[index];
}

int spaceOpt(int index){
    int prev = 1;
    int prev2 = 1;

    for (int i = 2; i <= index; i++)
    {
        int curr = prev + prev2;
        prev2 = prev;
        prev = curr;
    }
    return prev;
}

int main()
{
    int stairs;
    cin>>stairs;

    vector<int>dp(stairs+1,-1);
    // cout<<recursion(stairs);
    // cout<<memoization(stairs,dp);
    // cout<<tabulation(stairs,dp);
    cout<<spaceOpt(stairs);
    
    return 0;
}