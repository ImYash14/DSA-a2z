#include<iostream>
#include<bits/stdc++.h>
using namespace std;

int recursion(int i, int j1, int j2, vector<vector<int>>&mat){
    int n = mat.size();
    int m = mat[0].size();

    //base case -> out of bound
    if(j1<0 || j1>=m || j2<0 || j2>=m) return -1e9; //so that this path can never be considered

    //base case -> destination
    if(i == n-1){
        if(j1 == j2) return mat[i][j1]; //or mat[i][j2]
        else return mat[i][j1] + mat[i][j2];
    }

    //explore all paths
    int maxi =0;
    for (int dA = -1; dA <= 1; dA++)
    {
        for (int dB = -1; dB <= 1; dB++)
        {
            if(j1 == j2){
                maxi = max(maxi,mat[i][j1] + recursion(i+1,j1 + dA,j2 + dB, mat));
            }
            else{
                maxi = max(maxi,mat[i][j1] + mat[i][j2] + recursion(i+1,j1 + dA,j2 + dB, mat));
            }
        }
        
    }
    return maxi;
}

int memoization(int i, int j1, int j2, vector<vector<int>>&mat,
    vector<vector<vector<int>>>&dp){
    int n = mat.size();
    int m = mat[0].size();

    //base case -> out of bound
    if(j1<0 || j1>=m || j2<0 || j2>=m) return -1e9; //so that this path can never be considered

    //base case -> destination
    if(i == n-1){
        if(j1 == j2) return mat[i][j1]; //or mat[i][j2]
        else return mat[i][j1] + mat[i][j2];
    }

    if(dp[i][j1][j2] != -1) return dp[i][j1][j2];

    //explore all paths
    int maxi = INT_MIN;
    for (int dA = -1; dA <= 1; dA++)
    {
        for (int dB = -1; dB <= 1; dB++)
        {
            if(j1 == j2){
                maxi = max(maxi,mat[i][j1] + memoization(i+1,j1 + dA,j2 + dB, mat,dp));
            }
            else{
                maxi = max(maxi,mat[i][j1] + mat[i][j2] + memoization(i+1,j1 + dA,j2 + dB, mat,dp));
            }
        }
        
    }
    return dp[i][j1][j2] = maxi;
}

int tabulation(vector<vector<int>>&mat){
    int n = mat.size();
    int m = mat[0].size();

    vector<vector<vector<int>>>dp(n,vector<vector<int>>(m,vector<int>(m,0)));
    //base cases
    for (int j1 = 0; j1 < m; j1++)
    {
        for (int j2 = 0; j2 < m; j2++)
        {
            if(j1 == j2){
                dp[n-1][j1][j2] = mat[n-1][j1];
            }
            else{
                dp[n-1][j1][j2] = mat[n-1][j1] + mat[n-1][j2];
            }
        }        
    }
    
    //states using for loop
    //i,j1,j2 so three loops
    for (int i = n-2; i >=0; i--)
    {
        for (int j1 = 0; j1 < m; j1++)
        {
            for (int j2 = 0; j2 < m; j2++)
            {
                //explore all paths
                int maxi = -1e9;
                for (int dA = -1; dA <= 1; dA++)
                {
                    for (int dB = -1; dB <= 1; dB++)
                    {
                        // if(j1 == j2){
                        //     if(j1+dA>=0 && j1+dA<m && j2+dB>=0 && j2+dB<m)
                        //     {
                        //         maxi = max(maxi,mat[i][j1] + dp[i+1][j1 + dA][j2 + dB]);
                        //     }
                        //     else maxi = -1e9;
                        // }
                        // else{
                        //     if(j1+dA>=0 && j1+dA<m && j2+dB>=0 && j2+dB<m)
                        //     {
                        //         maxi = max(maxi,mat[i][j1] + mat[i][j2] + dp[i+1][j1 + dA][j2 + dB]);
                        //     }
                        //     else maxi = -1e9;
                        // }
                        int value =0;
                        if(j1 == j2) value = mat[i][j1];
                        else value = mat[i][j1] + mat[i][j2];

                        if(j1+dA>=0 && j1+dA<m && j2+dB>=0 && j2+dB<m){
                            value += dp[i+1][j1 + dA][j2 + dB];
                        }
                        else{
                            value += -1e9;
                        }
                        maxi = max(maxi, value);
                    }
                    
                }
                dp[i][j1][j2] = maxi;
            }
            
        }
        
    }
    return dp[0][0][m-1];

}

int spaceopt(vector<vector<int>>&mat){
    int n = mat.size();
    int m = mat[0].size();

    vector<vector<int>>front(m,vector<int>(m,0));
    //base cases
    for (int j1 = 0; j1 < m; j1++)
    {
        for (int j2 = 0; j2 < m; j2++)
        {
            if(j1 == j2){
                front[j1][j2] = mat[n-1][j1];
            }
            else{
                front[j1][j2] = mat[n-1][j1] + mat[n-1][j2];
            }
        }        
    }
    
    //states using for loop
    //i,j1,j2 so three loops
    for (int i = n-2; i >=0; i--)
    {
        vector<vector<int>>curr(m,vector<int>(m,0));
        for (int j1 = 0; j1 < m; j1++)
        {
            for (int j2 = 0; j2 < m; j2++)
            {
                //explore all paths
                int maxi = -1e9;
                for (int dA = -1; dA <= 1; dA++)
                {
                    for (int dB = -1; dB <= 1; dB++)
                    {
                        int value =0;
                        if(j1 == j2) value = mat[i][j1];
                        else value = mat[i][j1] + mat[i][j2];

                        if(j1+dA>=0 && j1+dA<m && j2+dB>=0 && j2+dB<m){
                            value += front[j1 + dA][j2 + dB];
                        }
                        else{
                            value += -1e9;
                        }
                        maxi = max(maxi, value);
                    }
                    
                }
                curr[j1][j2] = maxi;
            }
        }
        front = curr;
        
    }
    return front[0][m-1];

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
    
    // cout<<recursion(0,0,m-1,mat);
    // vector<vector<vector<int>>>dp(n,vector<vector<int>>(m,vector<int>(m,-1)));
    // cout<<memoization(0,0,m-1,mat,dp);
    // cout<<tabulation(mat);
    cout<<spaceopt(mat);
    
    return 0;
}