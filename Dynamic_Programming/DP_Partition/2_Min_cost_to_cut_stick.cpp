#include<iostream>
#include<bits/stdc++.h>
using namespace std;

int recursion(int i, int j,vector<int>&cuts){
    //base case
    if(i>j) return 0;

    int mini = 1e9;
    for (int k = i; k <= j; k++)
    {
        int cost = cuts[j+1] - cuts[i-1] + recursion(i,k-1,cuts) + recursion(k+1,j,cuts);
        mini = min(mini,cost);
    }
    return mini;
}

int memoization(int i, int j,vector<int>&cuts,vector<vector<int>>&dp){
    //base case
    if(i>j) return 0;

    if(dp[i][j] != -1) return dp[i][j];

    int mini = 1e9;
    for (int k = i; k <= j; k++)
    {
        int cost = cuts[j+1] - cuts[i-1] + memoization(i,k-1,cuts,dp)
                 + memoization(k+1,j,cuts,dp);
        mini = min(mini,cost);
    }
    return dp[i][j] = mini;
}

int minCost(vector<int>&cuts,int length){
    int n = cuts.size();

    cuts.push_back(length);
    cuts.insert(cuts.begin(),0);

    sort(cuts.begin(),cuts.end());
    
    // return recursion(1,n,cuts);
    vector<vector<int>>dp(n+1,vector<int>(n+1,-1));
    return memoization(1,n,cuts,dp);

}

int tabulation(vector<int>&cuts,int length){
    int n = cuts.size();

    cuts.push_back(length);
    cuts.insert(cuts.begin(),0);

    sort(cuts.begin(),cuts.end());
    
    vector<vector<int>>dp(n+2,vector<int>(n+2,0));
    //skip base case as already 0

    //for loop for states in rev of recursion
    for (int i = n; i >=1; i--)
    {
        for (int j = 1; j <= n; j++)
        {
            if(i>j) continue; //base case already covered
            int mini = 1e9;
            for (int k = i; k <= j; k++)
            {
                int cost = cuts[j+1] - cuts[i-1] + dp[i][k-1]
                        + dp[k+1][j];
                mini = min(mini,cost);
            }
            dp[i][j] = mini;
        }
        
    }
    return dp[1][n];
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
    int length;
    cin>>length;
    
    // cout<<minCost(arr,length);
    cout<<tabulation(arr,length);
    
    return 0;
}