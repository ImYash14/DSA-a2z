#include<iostream>
#include<bits/stdc++.h>
using namespace std;

int recursion(int i, int j, string&s1, string &s2){
    //base case
    //if s1 gets exhausted
    if(i<0) return j+1; //j+1 insertions
    //if s2 gets exhausted
    if(j<0) return i+1; //i+1 deletions

    //if matching chars
    if(s1[i] == s2[j]){
        return 0 + recursion(i-1,j-1,s1,s2); //0 operations
    }

    //else if not matching chars
    return min(
        1 + recursion(i,j-1,s1,s2),min(1 + recursion(i-1,j,s1,s2),1 + recursion(i-1,j-1,s1,s2)));
            //insert                       //delete                    //replace
}

int memoization(int i, int j, string&s1, string &s2,vector<vector<int>>&dp){
    //base case
    //if s1 gets exhausted
    if(i<0) return j+1; //j+1 insertions
    //if s2 gets exhausted
    if(j<0) return i+1; //i+1 deletions

    if(dp[i][j] != -1) return dp[i][j];

    //if matching chars
    if(s1[i] == s2[j]){
        return dp[i][j] = 0 + memoization(i-1,j-1,s1,s2,dp); //0 operations
    }

    //else if not matching chars
    return dp[i][j] = min(
        1 + memoization(i,j-1,s1,s2,dp),min(1 + memoization(i-1,j,s1,s2,dp),1 + memoization(i-1,j-1,s1,s2,dp)));
            //insert                       //delete                                //replace
}

int tabulation(string&s1, string&s2){
    int n = s1.size();
    int m = s2.size();

    //base case
    //1 based indexing
    //new base case for recusrion
    //if(i==0) return j;
    //if(j==0) return i;
    vector<vector<int>>dp(n+1,vector<int>(m+1,0));
    for (int j = 0; j <= m; j++)
    {
        dp[0][j] = j;
    }
    for (int i = 1; i <= n; i++)
    {
        dp[i][0] = i;
    }
    
    //for loops for states in reverse of recursion
    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= m; j++)
        {
            if(s1[i-1] == s2[j-1]){
                dp[i][j] = 0 + dp[i-1][j-1];
            }
            else{
                dp[i][j] = min(1 + dp[i][j-1],min(1 + dp[i-1][j], 1+ dp[i-1][j-1]));
            }
        }
        
    }
    return dp[n][m];    
}

int spaceopt(string&s1, string&s2){
    int n = s1.size();
    int m = s2.size();

    vector<int>prev(m+1,0);
    vector<int>curr(m+1,0);
    for (int j = 0; j <= m; j++)
    {
        prev[j] = j;
    }
    // for (int i = 1; i <= n; i++)
    // {
    //     dp[i][0] = i;
    // }
    
    //for loops for states in reverse of recursion
    for (int i = 1; i <= n; i++)
    {
        curr[0] = i;
        for (int j = 1; j <= m; j++)
        {
            if(s1[i-1] == s2[j-1]){
                curr[j] = 0 + prev[j-1];
            }
            else{
                curr[j] = min(1 + curr[j-1],min(1 + prev[j], 1+ prev[j-1]));
            }
        }
        prev = curr;
    }
    return prev[m];    
}

//here we cannot space opt to 1 array because 
//we are depenedent on prev of curr and prev of prev

int main()
{
    string s1,s2;
    cin>>s1>>s2;

    int n = s1.size();
    int m = s2.size();

    // cout<<recursion(n-1,m-1,s1,s2);
    // vector<vector<int>>dp(n,vector<int>(m,-1));
    // cout<<memoization(n-1,m-1,s1,s2,dp);
    // cout<<tabulation(s1,s2);
    cout<<spaceopt(s1,s2);
    
    return 0;
}