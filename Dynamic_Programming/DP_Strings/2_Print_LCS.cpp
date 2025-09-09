#include<iostream>
#include<bits/stdc++.h>
using namespace std;

int tabulation(string&s1, string&s2,vector<vector<int>>&dp){
    int n = s1.size();
    int m = s2.size();

    //right shift indexes by 1
    //new base case of recursion
    //if(i==0 || j==0) return 0;

    // vector<vector<int>>dp(n+1,vector<int>(m+1,0));
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

    // for (int i = 0; i < n+1; i++)
    // {
    //     for (int j = 0; j < m+1; j++)
    //     {
    //         cout<<dp[i][j];
    //     }
    //     cout<<endl;
    // }
    
    return dp[n][m];
}

string printLCS(string&s1, string&s2){
    int n = s1.size();
    int m = s2.size();

    vector<vector<int>>dp(n+1,vector<int>(m+1,0));
    tabulation(s1,s2,dp);

    int len = dp[n][m];
    string ans = "";
    for (int i = 0; i < len; i++)
    {
        ans += '#';
    }
    int index = len-1;

    int i =n, j=m;
    while(i>0 && j>0){
        if(s1[i-1] == s2[j-1]){
            ans[index] = s1[i-1];
            index--;

            //move to diagonal
            i--;
            j--;
        }
        else if(dp[i-1][j] > dp[i][j-1]){
            i = i-1;
        }
        else j = j-1;
    }
    return ans;
}

int main()
{
    string s1,s2;
    cin>>s1>>s2;

    cout<<printLCS(s1,s2);
    
    return 0;
}