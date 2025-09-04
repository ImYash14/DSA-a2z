#include<iostream>
#include<bits/stdc++.h>
using namespace std;

int recursion(int i, int j,vector<vector<int>>&mat){
    if(i>=0 && j>=0 && mat[i][j] == -1) return 0;
    if(i == 0 && j == 0) return 1;
    if(i < 0 || j <0) return 0;

    int up = recursion(i-1,j,mat);
    int left = recursion(i,j-1,mat);
    return up + left;
}

int memoization(int i, int j,vector<vector<int>>&dp,vector<vector<int>>&mat){
    if(i>=0 && j>=0 && mat[i][j] == -1) return 0;
    if(i == 0 && j == 0) return 1;
    if(i < 0 || j <0) return 0;

    if(dp[i][j] != -1) return dp[i][j];

    int up = recursion(i-1,j,mat);
    int left = recursion(i,j-1,mat);
    return dp[i][j] = up + left;
}

int tabulation(vector<vector<int>>&mat){
    int m = mat.size();
    int n = mat[0].size();

    vector<vector<int>>dp(m,vector<int>(n,0));
    for (int i = 0; i < m; i++)
    {
        for (int j = 0; j < n; j++)
        {
            if(mat[i][j] == -1) dp[i][j] = 0;
            else if(i == 0 && j == 0) dp[i][j] = 1;

            else{
                int up =0, left =0;
                if(i>0) up = dp[i-1][j];
                if(j>0) left = dp[i][j-1];

                dp[i][j] = up + left;
            }
        }
        
    }
    return dp[m-1][n-1];
}

int spaceopt(vector<vector<int>>&mat){
    int m = mat.size();
    int n = mat[0].size();

    vector<int>prev(n,0);

    for (int i = 0; i < m; i++)
    {
        vector<int>curr(n,0);
        for (int j = 0; j < n; j++)
        {
            if(mat[i][j] == -1) curr[j] = 0;
            else if(i == 0 && j == 0) curr[j] = 1;

            else{
                int up = 0;
                int left = 0;
                if(i>0) up = prev[j];
                if(j>0) left = curr[j-1];

                curr[j] = up + left;
            }
        }
        prev = curr;
    }
    return prev[n-1];
}

int main()
{
    int m,n;
    cin>>m>>n;
    vector<vector<int>>mat(m,vector<int>(n));
    for (int i = 0; i < m; i++)
    {
        for (int j = 0; j < n; j++)
        {
            cin>>mat[i][j];
        }
        
    }

    // cout<<recursion(m-1,n-1,mat);
    // vector<vector<int>>dp(m,vector<int>(n,-1));
    // cout<<memoization(m-1,n-1,dp,mat);
    // cout<<tabulation(mat);
    cout<<spaceopt(mat);
    
    return 0;
}