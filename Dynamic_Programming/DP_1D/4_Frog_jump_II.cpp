#include<iostream>
#include<bits/stdc++.h>
using namespace std;

int recursion(int index, int k, vector<int>&arr){
    if(index == 0) return 0;

    int minEnergy = INT_MAX;
    for (int i = 1; i <= k; i++)
    {
        if(index > i-1){
            int jump = recursion(index-i,k,arr) + abs(arr[index] - arr[index-i]);
            minEnergy = min(minEnergy, jump);
        }
    }
    return minEnergy;
}

int memoization(int index,int k,vector<int>&dp,vector<int>&arr){
    if(index == 0) return 0;

    if(dp[index] != -1) return dp[index];

    //else
    int minEnergy = INT_MAX;
    for (int i = 1; i <= k; i++)
    {
        if(index > i-1){
            int jump = recursion(index-i,k,arr) + abs(arr[index] - arr[index-i]);
            minEnergy = min(minEnergy, jump);
        }
    }
    return dp[index] = minEnergy;
}

int tabulation(int n,int k,vector<int>&dp,vector<int>&arr){
    dp[0] = 0;

    for (int i = 1; i <= n-1; i++)
    {
        int minEnergy = INT_MAX;
        for (int j = 1; j <= k; j++)
        {
            if(i-j >=0){
                int jump = dp[i-j] + abs(arr[i] - arr[i-j]);
                minEnergy = min(minEnergy, jump);
            }
        }
        dp[i] = minEnergy;
    }
    return dp[n-1];
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
    cout<<recursion(n-1,k,arr);
    
    return 0;
}