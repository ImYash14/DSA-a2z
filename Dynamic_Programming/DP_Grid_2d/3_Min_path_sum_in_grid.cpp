#include<iostream>
#include<bits/stdc++.h>
using namespace std;

int recursion(int i,int j,vector<vector<int>>&mat){
    if(i == 0 && j == 0) return mat[0][0];
    if(i < 0 || j < 0) return 1e9;

    int up = mat[i][j] + recursion(i-1,j,mat);
    int left = mat[i][j] + recursion(i,j-1,mat);

    return min(up,left);
}

int memoization(int i,int j,vector<vector<int>>&dp,vector<vector<int>>&mat){
    if(i == 0 && j == 0) return mat[0][0];
    if(i < 0 || j < 0) return 1e9;

    if(dp[i][j] != -1) return dp[i][j];

    int up = mat[i][j] + recursion(i-1,j,mat);
    int left = mat[i][j] + recursion(i,j-1,mat);

    return dp[i][j] = min(up,left);
}

int tabulation(vector<vector<int>>&mat){
    int n = mat.size();
    int m = mat[0].size();

    vector<vector<int>>dp(n,vector<int>(m,0));
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            if(i == 0 && j == 0) dp[0][0] = mat[0][0];
            else{
                int up = 1e9, left = 1e9;
                if (i > 0) up = mat[i][j] + dp[i-1][j];
                if (j > 0) left = mat[i][j] + dp[i][j-1];

                dp[i][j] = min(up,left);
            }
        }
        
    }
    return dp[n-1][m-1];
}

int spaceopt(vector<vector<int>>&mat){
    int n = mat.size();
    int m = mat[0].size();

    vector<int>prev(m,0);
    for (int i = 0; i < n; i++)
    {
        vector<int>curr(m,0);
        for (int j = 0; j < m; j++)
        {
            if(i == 0 && j == 0) curr[j] = mat[0][0];
            else{
                int up = 1e9, left = 1e9;
                if (i > 0) up = mat[i][j] + prev[j];
                if (j > 0) left = mat[i][j] + curr[j-1];

                curr[j] = min(up,left);
            }
        }
        prev = curr;
    }
    return prev[m-1];
}

int main()
{
    int n,m;
    cin>>n>>m;
    vector<vector<int>>mat(n,vector<int>(m));
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            cin>>mat[i][j];
        }
        
    }
    
    // cout<<recursion(n-1,m-1,mat);
    // vector<vector<int>>dp(n,vector<int>(m,-1));
    // cout<<memoization(n-1,m-1,dp,mat);
    // cout<<tabulation(mat);
    cout<<spaceopt(mat);
    
    return 0;
}