#include<iostream>
#include<bits/stdc++.h>
using namespace std;

bool recursion(int i, int j,string&s1, string&s2){
    //base case
    //if s1 gets exhausted
    if(i<0 && j<0) return true;
    if(i<0 && j>=0) return false;
    //if s2 gets exhausted
    //then in order to match with s1 with s2 which is an empty string
    //s1 hast to contain all *
    if(j<0 && i>=0){
        for (int x = 0; x <= i; x++)
        {
            if(s1[x] != '*') return false;
        }
       return true; 
    }

    //all possibilities
    if(s1[i] == s2[j] || s1[i] == '?'){
        return recursion(i-1,j-1,s1,s2);
    }
    if(s1[i] == '*'){
        return (recursion(i-1,j,s1,s2) | recursion(i,j-1,s1,s2));
    }
    //else if it is neither ? nor * and not matching
    return false;
}

bool memoization(int i, int j, string&s1, string&s2,vector<vector<int>>&dp){
    //base case
    //if s1 gets exhausted
    if(i<0 && j<0) return true;
    if(i<0 && j>=0) return false;
    //if s2 gets exhausted
    //then in order to match with s1 with s2 which is an empty string
    //s1 hast to contain all *
    if(j<0 && i>=0){
        for (int x = 0; x <= i; x++)
        {
            if(s1[x] != '*') return false;
        }
       return true; 
    }

    if(dp[i][j] != -1) return dp[i][j];

    //all possibilities
    if(s1[i] == s2[j] || s1[i] == '?'){
        return dp[i][j] = memoization(i-1,j-1,s1,s2,dp);
    }
    if(s1[i] == '*'){
        return dp[i][j] = (memoization(i-1,j,s1,s2,dp) | memoization(i,j-1,s1,s2,dp));
    }
    //else if it is neither ? nor * and not matching
    return dp[i][j] = false;
}

int tabulation(string &s1, string &s2){
    int n = s1.size();
    int m = s2.size();

    //1 based indexing
    //new base case
    // if(i==0 && j==0) return true;
    // if(i==0 && j>0) return false;
    // if(j==0 && i>0){
    //     for (int x = 1; x <= i; x++)
    //     {
    //         if(s1[x-1] != '*') return false;
    //     }
    //    return true; 
    // }

    //base case
    vector<vector<bool>>dp(n+1,vector<bool>(m+1,0));
    dp[0][0] = true;
    for (int j = 1; j <=m; j++)
    {
        dp[0][j] = false;
    }
    for (int i = 1; i <=n; i++)
    {
        // bool flag = true;
        for (int x = 1; x <= i; x++)
        {
            if(s1[x-1] != '*'){
                dp[i][0] = false;                
            }
            else{
                dp[i][0] = true;
            }
        }
        // dp[i][0] = flag;
    }
    
    //for loop for states
    for (int i = 1; i <=n; i++)
    {
        for (int j = 1; j <=m; j++)
        {
            if(s1[i-1] == s2[j-1] || s1[i-1] == '?'){
                dp[i][j] = dp[i-1][j-1];
            }
            else if(s1[i-1] == '*'){
                dp[i][j] = (dp[i-1][j] | dp[i][j-1]);
            }
            else dp[i][j] = false;
        }
        
    }
    return dp[n][m];    
}

int spaceopt(string &s1, string &s2){
    int n = s1.size();
    int m = s2.size();

    //base case
    vector<bool>prev(m+1,0);
    vector<bool>curr(m+1,0);
    prev[0] = true;

    for (int j = 1; j <=m; j++)
    {
        prev[j] = false;
    }

    //for loop for states
    for (int i = 1; i <=n; i++)
    {
        //curr is current row's column
        //and for every row, it has to assigned
        bool flag = true;
        for (int x = 1; x <= i; x++)
        {
            if(s1[x-1] != '*'){
                flag = false; 
                break;               
            }
        }
        curr[0] = flag;

        for (int j = 1; j <=m; j++)
        {
            if(s1[i-1] == s2[j-1] || s1[i-1] == '?'){
                curr[j] = prev[j-1];
            }
            else if(s1[i-1] == '*'){
                curr[j] = (prev[j] | curr[j-1]);
            }
            else curr[j] = false;
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
    // cout<<tabulation(s1,s2);
    cout<<spaceopt(s1,s2);

    return 0;
}