#include<iostream>
#include<bits/stdc++.h>
using namespace std;

int recursion(int index, int W,vector<int>&wt,vector<int>&price){
    int n = wt.size();

    //base case
    if(W == 0) return price[index];
    if(index == 0){
        if(wt[index] <= W) return price[index];
        else return 0;
    }

    //all possiblities
    int nottake = 0 + recursion(index-1,W,wt,price);
    int take = INT_MIN;
    if(wt[index] <= W){
        take = price[index] + recursion(index-1,W-wt[index],wt,price);
    }

    return max(take, nottake);
}

int memoization(int index, int W,vector<int>&wt,vector<int>&price,vector<vector<int>>&dp){
    int n = wt.size();

    //base case
    if(W == 0) return price[index];
    if(index == 0){
        if(wt[index] <= W) return price[index];
        else return 0;
    }

    if(dp[index][W] != -1) return dp[index][W];

    //all possiblities
    int nottake = 0 + recursion(index-1,W,wt,price);
    int take = INT_MIN;
    if(wt[index] <= W){
        take = price[index] + recursion(index-1,W-wt[index],wt,price);
    }

    return dp[index][W] = max(take, nottake);
}

int tabulation(int W,vector<int>&wt,vector<int>&price){
    int n = wt.size();

    vector<vector<int>>dp(n,vector<int>(W+1,0));
    //base case
    for (int i = 0; i < n; i++)
    {
        dp[i][0] = price[i];
    }
    for (int i = wt[0]; i <= W; i++)
    {
        dp[0][i] = price[0];
    }
    

    //for loop for states in reverse of recursion
    for (int i = 1; i < n; i++) //for index
    {
        for (int j = 1; j <= W; j++) //for W
        {
            int nottake = 0 + dp[i-1][j];
            int take = INT_MIN;
            if(wt[i] <= j){
                take = price[i] + dp[i-1][j-wt[i]];
            }

            dp[i][j] = max(take,nottake);
        }
        
    }
    return dp[n-1][W];
    
}

int spaceopt1(int W,vector<int>&wt,vector<int>&price){
    int n = wt.size();

    vector<int>prev(W+1,0);
    for (int i = wt[0]; i <= W; i++)
    {
        prev[i] = price[0];
    }
    
    //for loop for states in reverse of recursion
    for (int i = 1; i < n; i++) //for index
    {
        vector<int>curr(W+1,0);
        for (int j = 0; j <= W; j++) //for W
        {
            int nottake = 0 + prev[j];
            int take = INT_MIN;
            if(wt[i] <= j){
                take = price[i] + prev[j-wt[i]];
            }

            curr[j] = max(take,nottake);
        }
        prev = curr;
    }
    return prev[W];
}

int spaceopt2(int W,vector<int>&wt,vector<int>&price){
    int n = wt.size();

    vector<int>prev(W+1,0);
    for (int i = wt[0]; i <= W; i++)
    {
        prev[i] = price[0];
    }
    
    //for loop for states in reverse of recursion
    for (int i = 1; i < n; i++) //for index
    {
        // vector<int>curr(W+1,0);
        for (int j = W; j >=0 ; j--) //for W
        {
            int nottake = 0 + prev[j];
            int take = INT_MIN;
            if(wt[i] <= j){
                take = price[i] + prev[j-wt[i]];
            }

            prev[j] = max(take,nottake);
        }
        
    }
    return prev[W];
}

int main()
{
    int n;
    cin>>n;
    vector<int>wt(n),price(n);
    for (int i = 0; i < n; i++)
    {
        cin>>wt[i]>>price[i];
    }
    int W;
    cin>>W;
    
    // cout<<recursion(n-1,W,wt,price);
    // vector<vector<int>>dp(n,vector<int>(W+1,-1));
    // cout<<memoization(n-1,W,wt,price,dp);
    // cout<<tabulation(W,wt,price);
    // cout<<spaceopt1(W,wt,price);
    cout<<spaceopt2(W,wt,price);
    
    return 0;
}