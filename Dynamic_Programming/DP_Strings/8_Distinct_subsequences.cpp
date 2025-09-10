#include<iostream>
#include<bits/stdc++.h>
using namespace std;

int recursion(int i, int j, string &s1,string &s2){
    //base case
    if(j<0) return 1;
    if(i<0) return 0;

    //if matching
    if(s1[i] == s2[j]){
        return recursion(i-1,j-1,s1,s2) + recursion(i-1,j,s1,s2);
    }

    //if not matching
    return recursion(i-1,j,s1,s2);
}

int memoization(int i, int j, string&s1, string &s2,vector<vector<int>>&dp){
    //base case
    if(j<0) return 1;
    if(i<0) return 0;

    if(dp[i][j] != -1) return dp[i][j];

    //if matching
    if(s1[i] == s2[j]){
        return dp[i][j] = recursion(i-1,j-1,s1,s2) + recursion(i-1,j,s1,s2);
    }

    //if not matching
    return dp[i][j] = recursion(i-1,j,s1,s2);
}

int tabulation(string &s1, string &s2){
    int n = s1.size();
    int m = s2.size();

    //base case
    //similar to LCS here we will do the 1 based indexing(right shift index by 1)
    //new base case for recursion->
    //if(j==0) return 1;
    //if(i==0) return 0;
    vector<vector<int>>dp(n+1,vector<int>(m+1,0));
    for (int i = 0; i <= n; i++)
    {
        dp[i][0] = 1;
    }
    //here j will start from 1
    //else it will rewrite the prev for loop's 0 column
    for (int j = 1; j <= m; j++)
    {
        dp[0][j] = 0;
    }
    
    //for loop for the states in reverse of recursion
    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= m; j++)
        {
            if(s1[i-1] == s2[j-1]){ //for strings do 0 based and for all other do 1 based
                dp[i][j] = dp[i-1][j-1] + dp[i-1][j];
            }
            else dp[i][j] = dp[i-1][j];
        }
        
    }
    return dp[n][m];
}

int spaceopt1(string &s1, string &s2){
    int n = s1.size();
    int m = s2.size();

    vector<int>prev(m+1,0);
    vector<int>curr(m+1,0);
    
    prev[0] = 1;
    curr[0] = 1;
    
    //for loop for the states in reverse of recursion
    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= m; j++)
        {
            if(s1[i-1] == s2[j-1]){ //for strings do 0 based and for all other do 1 based
                curr[j] = prev[j-1] + prev[j];
            }
            else curr[j] = prev[j];
        }
        prev = curr;
    }
    return prev[m];
}

int spaceopt2(string &s1, string &s2){
    int n = s1.size();
    int m = s2.size();

    vector<int>prev(m+1,0);
    // vector<int>curr(m+1,0);
    
    prev[0] = 1;
    // curr[0] = 1;
    
    //for loop for the states in reverse of recursion
    for (int i = 1; i <= n; i++)
    {
        for (int j = m; j >=1; j--)
        {
            if(s1[i-1] == s2[j-1]){ //for strings do 0 based and for all other do 1 based
                prev[j] = prev[j-1] + prev[j];
            }
            // else curr[j] = prev[j];
        }
        // prev = curr;
    }
    return prev[m];
}

int main()
{
    string s1, s2;
    cin>>s1>>s2;

    int n = s1.size();
    int m = s2.size();

    // cout<<recursion(n-1,m-1,s1,s2);
    // vector<vector<int>>dp(n,vector<int>(m,-1));
    // cout<<memoization(n-1,m-1,s1,s2,dp);
    // cout<<tabulation(s1,s2);
    // cout<<spaceopt1(s1,s2);
    cout<<spaceopt2(s1,s2);
    
    return 0;
}