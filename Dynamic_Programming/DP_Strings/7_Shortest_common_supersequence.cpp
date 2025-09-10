#include<iostream>
#include<bits/stdc++.h>
using namespace std;

int LCS(string&s1, string&s2,vector<vector<int>>&dp){
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
    return dp[n][m];
}

pair<int,string> shortestCommonSupersequence(string &s1, string &s2){
    int n = s1.size();
    int m = s2.size();

    //for finding the length of shortest common subsequence
    vector<vector<int>>dp(n+1,vector<int>(m+1,0));
    LCS(s1,s2,dp);
    int len = n + m - dp[n][m];

    //for finding the shortest common subsequence string
    string ans = "";
    int i =n, j =m;
    while(i>0 && j>0){
        if(s1[i-1] == s2[j-1]){//move diagonal
            ans += s1[i-1];
            i--;
            j--;
        }
        else if(dp[i-1][j] > dp[i][j-1]){//move upwards
            ans += s1[i-1];
            i--;
        }
        else{//move leftwards
            ans += s2[j-1];
            j--;
        }
    }
    //if one of the string gets exhausted
    while(i>0){
        ans += s1[i-1];
        i--;
    }
    while(j>0){
        ans += s2[j-1];
        j--;
    }

    reverse(ans.begin(),ans.end());

    return {len,ans};
}

int main()
{
    string s1,s2;
    cin>>s1>>s2;

    pair<int,string>output = shortestCommonSupersequence(s1,s2);
    cout<<output.first<<" "<<output.second;
    
    return 0;
}