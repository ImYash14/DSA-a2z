#include<iostream>
#include<bits/stdc++.h>
using namespace std;

int recursion(int index, int previndex, vector<int>&arr){
    //base case
    if(index == arr.size()) return 0;

    int nottake = 0 + recursion(index+1,previndex,arr);
    int take = -1e9;
    if(previndex == -1 || arr[index] > arr[previndex]){
        take = 1 + recursion(index+1,index,arr);
    }

    return max(take,nottake);
}

int memoization(int index, int previndex, vector<int>&arr,vector<vector<int>>&dp){
    //base case
    if(index == arr.size()) return 0;

    if(dp[index][previndex + 1] != -1) return dp[index][previndex + 1];

    int nottake = 0 + memoization(index+1,previndex,arr,dp);
    int take = -1e9;
    if(previndex == -1 || arr[index] > arr[previndex]){
        take = 1 + memoization(index+1,index,arr,dp);
    }

    return dp[index][previndex + 1] = max(take,nottake);
}

int tabulation(vector<int>&arr){
    int n = arr.size();

    vector<vector<int>>dp(n+1,vector<int>(n+1,0));
    //skip base case bc already assigned 0

    //for loops for states in rev of recursion
    for (int index = n-1; index >=0; index--)
    {
        for (int prev = index-1; prev >= -1; prev--)
        {
            //remember to do coordinate shifting
            //in second parameter add +1
            int nottake = 0 + dp[index+1][prev+1];
            int take = -1e9;
            if(prev == -1 || arr[index] > arr[prev]){
                take = 1 + dp[index+1][index+1];
            }

            dp[index][prev+1] = max(take,nottake);
        }
        
    }
    return dp[0][-1+1];
}

int spaceopt(vector<int>&arr){
    int n = arr.size();

    vector<int>front(n+1,0);
    vector<int>curr(n+1,0);
    //skip base case bc already assigned 0

    //for loops for states in rev of recursion
    for (int index = n-1; index >=0; index--)
    {
        for (int prev = index-1; prev >= -1; prev--)
        {
            //remember to do coordinate shifting
            //in second parameter add +1
            int nottake = 0 + front[prev+1];
            int take = -1e9;
            if(prev == -1 || arr[index] > arr[prev]){
                take = 1 + front[index+1];
            }

            curr[prev+1] = max(take,nottake);
        }
        front = curr;
    }
    return front[-1+1];
}

int anotherMethod(vector<int>&arr){
    int n = arr.size();

    vector<int>dp(n,1);
    int maxi = 1;
    for (int i = 0; i < n; i++)
    {
        for (int prev = 0; prev < i; prev++)
        {
            if(arr[prev] < arr[i]){
                dp[i] = max(dp[i], 1 + dp[prev]);
            }
        }
        maxi = max(maxi,dp[i]);
    }
    return maxi;
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
    
    // cout<<recursion(0,-1,arr);
    // vector<vector<int>>dp(n,vector<int>(n+1,-1));
    // cout<<memoization(0,-1,arr,dp);
    // cout<<tabulation(arr);
    // cout<<spaceopt(arr);
    cout<<anotherMethod(arr);
    
    return 0;
}