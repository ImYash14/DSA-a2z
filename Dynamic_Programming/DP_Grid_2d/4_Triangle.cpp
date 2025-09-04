#include<iostream>
#include<bits/stdc++.h>
using namespace std;

int recursion(int i, int j, vector<vector<int>>&arr){
    int n = arr.size();

    if(i == n-1) return arr[n-1][j];

    int down = arr[i][j] + recursion(i+1,j,arr);
    int diagonal = arr[i][j] + recursion(i+1,j+1,arr);

    return min(down, diagonal);
}

int memoization(int i, int j, vector<vector<int>>&dp, vector<vector<int>>&arr){
    int n = arr.size();

    if(i == n-1) return arr[n-1][j];

    if(dp[i][j] != -1) return dp[i][j];

    int down = arr[i][j] + recursion(i+1,j,arr);
    int diagonal = arr[i][j] + recursion(i+1,j+1,arr);

    return dp[i][j] = min(down, diagonal);
}

int tabulation(vector<vector<int>>&arr){
    int n = arr.size();

    //base case
    vector<vector<int>>dp(n,vector<int>(n,0));
    for (int j = 0; j < n; j++)
    {
        dp[n-1][j] = arr[n-1][j];
    }

    for (int i = n-2; i >=0; i--)
    {
        for (int j = i; j >= 0; j--)
        {
            int down = arr[i][j] + dp[i+1][j];
            int diagonal = arr[i][j] + dp[i+1][j+1];

            dp[i][j] = min(down, diagonal);
        }
        
    }
    return dp[0][0];    
}

int spaceopt(vector<vector<int>>&arr){
    int n = arr.size();
    
    vector<int>front(n,0);
    for (int j = 0; j < n; j++)
    {
        front[j] = arr[n-1][j];
    }

    for (int i = n-2; i >=0; i--)
    {
        vector<int>curr(n,0);
        for (int j = i; j >= 0; j--)
        {
            int down = arr[i][j] + front[j];
            int diagonal = arr[i][j] + front[j+1];

            curr[j] = min(down, diagonal);
        }
        front = curr;
    }
    return front[0];    
}

int main()
{
    int n;
    cin>>n;
    vector<vector<int>>arr;
    for (int i = 0; i < n; i++)
    {
        vector<int>temp(i+1);
        for (int j = 0; j < temp.size(); j++)
        {
            cin>>temp[j];
        }
        arr.push_back(temp);
    }
    
    // cout<<recursion(0,0,arr);
    // vector<vector<int>>dp(n,vector<int>(n,-1));
    // cout<<memoization(0,0,dp,arr);
    // cout<<tabulation(arr);
    cout<<spaceopt(arr);
    
    return 0;
}