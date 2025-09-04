#include<iostream>
#include<bits/stdc++.h>
using namespace std;

int recursion(int i, int j, vector<vector<int>>&mat){
    int n = mat.size();
    int m = mat[0].size();

    if(j<0 || j>=m) return -1e9;
    if(i == 0) return mat[i][j];

    int up = mat[i][j] + recursion(i-1,j,mat);
    int upleft = mat[i][j] + recursion(i-1,j-1,mat);
    int upright = mat[i][j] + recursion(i-1,j+1,mat);

    return max(up,max(upleft,upright));
}

int memoization(int i, int j,vector<vector<int>>&dp, vector<vector<int>>&mat){
    int n = mat.size();
    int m = mat[0].size();

    if(j<0 || j>=m) return -1e9;
    if(i == 0) return mat[i][j];

    if(dp[i][j] != -1) return dp[i][j];

    int up = mat[i][j] + recursion(i-1,j,mat);
    int upleft = mat[i][j] + recursion(i-1,j-1,mat);
    int upright = mat[i][j] + recursion(i-1,j+1,mat);

    return dp[i][j] = max(up,max(upleft,upright));
}

int findMaxPath(vector<vector<int>>&mat){
    int n = mat.size();
    int m = mat[0].size();

    int maxi = INT_MIN;
    vector<vector<int>>dp(n,vector<int>(m,-1));
    for (int i = 0; i < m; i++)
    {
        // maxi = max(maxi, recursion(n-1,i,mat));
        maxi = max(maxi, memoization(n-1,i,dp,mat));
    }
    return maxi;
}

int tabulation(vector<vector<int>>&mat){
    int n = mat.size();
    int m = mat[0].size();

    vector<vector<int>>dp(n,vector<int>(m,0));
    //base case
    for (int j = 0; j < m; j++)
    {
        dp[0][j] = mat[0][j];
    }
    
    for (int i = 1; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            int up = mat[i][j] + dp[i-1][j];

            int upleft = -1e9;
            if(j-1 >=0) upleft = mat[i][j] + dp[i-1][j-1];

            int upright = -1e9;
            if(j+1 < m) upright = mat[i][j] + dp[i-1][j+1];

            dp[i][j] = max(up,max(upleft,upright));
        }
        
    }
    
    //recursion calls were for f(n-1,0), f(n-1,1), ....., f(n-1,m-1)
    int maxi = dp[n-1][0];
    for (int i = 0; i < m; i++)
    {
        maxi = max(maxi, dp[n-1][i]);
    }
    return maxi;
    
}

int spaceopt(vector<vector<int>>&mat){
    int n = mat.size();
    int m = mat[0].size();

    vector<int>prev(m,0);
    //base case
    for (int j = 0; j < m; j++)
    {
        prev[j] = mat[0][j];
    }
    
    for (int i = 1; i < n; i++)
    {
        vector<int>curr(m,0);
        for (int j = 0; j < m; j++)
        {
            int up = mat[i][j] + prev[j];

            int upleft = -1e9;
            if(j-1 >=0) upleft = mat[i][j] + prev[j-1];

            int upright = -1e9;
            if(j+1 < m) upright = mat[i][j] + prev[j+1];

            curr[j] = max(up,max(upleft,upright));
        }
        prev = curr;
    }

    int maxi = INT_MIN;
    for (int i = 0; i < m; i++)
    {
        maxi = max(maxi, prev[i]);
    }
    return maxi;
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
    
    // cout<<findMaxPath(mat);
    // cout<<tabulation(mat);
    cout<<spaceopt(mat);
    
    return 0;
}