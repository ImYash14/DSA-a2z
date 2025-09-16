#include<iostream>
#include<bits/stdc++.h>
using namespace std;

int countSquares(vector<vector<int>>&mat){
    int n = mat.size();
    int m = mat[0].size();

    //same size dp arr
    vector<vector<int>>dp(n,vector<int>(m,0));

    //copy the 0th row and 0th col
    for (int i = 0; i < n; i++)
    {
        dp[i][0] = mat[i][0];
    }
    for (int j = 0; j < m; j++)
    {
        dp[0][j] = mat[0][j];
    }
    
    //fill dp
    for (int i = 1; i < n; i++)
    {
        for (int j = 1; j < m; j++)
        {
            if(mat[i][j] == 0) dp[i][j] =0;
            else{
                dp[i][j] = min(dp[i-1][j],min(dp[i-1][j-1],dp[i][j-1])) + 1;
            }
        }
        
    }
    
    //take sum of dp values
    int sum =0;
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            sum = sum + dp[i][j];
        }
        
    }
    return sum;
    
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
    
    cout<<countSquares(mat);
    
    return 0;
}