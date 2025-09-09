#include<iostream>
#include<bits/stdc++.h>
using namespace std;

int recursion(int i, int j,string&s1, string&s2){
    //base case
    if(i<0 || j<0) return 0;

    //if match
    if(s1[i] == s2[j]){
        return 1 + recursion(i-1,j-1,s1,s2);
    }

    //if no match
    return 0 + max(recursion(i-1,j,s1,s2), recursion(i,j-1,s1,s2));
}

int memoization(int i, int j, string&s1, string&s2, vector<vector<int>>&dp){
    //base case
    if(i<0 || j<0) return 0;

    if(dp[i][j] != -1) return dp[i][j];

    //if match
    if(s1[i] == s2[j]){
        return dp[i][j] = 1 + recursion(i-1,j-1,s1,s2);
    }

    //if no match
    return dp[i][j] = 0 + max(recursion(i-1,j,s1,s2), recursion(i,j-1,s1,s2));
}

int tabulation(string&s1, string&s2){
    int n = s1.size();
    int m = s2.size();

    //right shift indexes by 1
    //new base case of recursion
    //if(i==0 || j==0) return 0;

    vector<vector<int>>dp(n+1,vector<int>(m+1,0));
    //base case
    for (int j = 0; j <= m; j++)
    {
        dp[0][j] = 0;
    }
    for (int i = 0; i <= n; i++)
    {
        dp[i][0] = 0;
    }
    
    //for loop for states in recerse of recursion
    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= m; j++)
        {
            if(s1[i-1] == s2[j-1]) dp[i][j] = 1 + dp[i-1][j-1];
            else dp[i][j] = 0 + max(dp[i-1][j], dp[i][j-1]);
        }
        
    }
    return dp[n][m];
}

int spaceopt(string&s1, string&s2){
    int n = s1.size();
    int m = s2.size();

    //right shift indexes by 1
    //new base case of recursion
    //if(i==0 || j==0) return 0;

    vector<int>prev(m+1,0);
    //base case
    for (int j = 0; j <= m; j++)
    {
        prev[j] = 0;
    }
    
    //for loop for states in recerse of recursion
    for (int i = 1; i <= n; i++)
    {
        vector<int>curr(m+1,0);
        for (int j = 1; j <= m; j++)
        {
            if(s1[i-1] == s2[j-1]) curr[j] = 1 + prev[j-1];
            else curr[j] = 0 + max(prev[j], curr[j-1]);
        }
        prev = curr;
    }
    return prev[m];
}

int main()
{
    string s1,s2;
    cin>>s1>>s2;

    int n = s1.size();
    int m = s2.size();

    // cout<<recursion(n-1,m-1,s1,s2);
    // vector<vector<int>>dp(n,vector<int>(m,-1));
    // cout<<memoization(n-1,m-1,s1,s2,dp);
    cout<<tabulation(s1,s2);
    // cout<<spaceopt(s1,s2);
    
    return 0;
}