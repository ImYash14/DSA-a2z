#include<iostream>
#include<bits/stdc++.h>
using namespace std;

bool isPalindrome(string &s){
    int n = s.size();

    int low =0;
    int high = n-1;
    while(low < high){
        if(s[low] != s[high]) return false;
        low++;
        high--;
    }
    return true;
}

int recursion(int i, string &s){
    int n = s.size();

    //base case
    if(i == n) return 0; //no strings left

    //try front partitioning
    int mini = 1e9;
    string temp = "";
    for (int k = i; k < n; k++)
    {
        temp += s[k];
        if(isPalindrome(temp)){
            int count = 1 + recursion(k+1,s);
            mini = min(mini, count);
        }
    }
    return mini;
}

int memoization(int i, string &s,vector<int>&dp){
    int n = s.size();

    //base case
    if(i == n) return 0; //no strings left

    if(dp[i] != -1) return dp[i];

    //try front partitioning
    int mini = 1e9;
    string temp = "";
    for (int k = i; k < n; k++)
    {
        temp += s[k];
        if(isPalindrome(temp)){
            int count = 1 + memoization(k+1,s,dp);
            mini = min(mini, count);
        }
    }
    return dp[i] = mini;
}

int tabulation(string &s){
    int n = s.size();

    vector<int>dp(n+1,0);
    //base case
    dp[n] =0;

    //for loop for states in rev of recursion
    for (int i = n-1; i >=0; i--)
    {
        int mini = 1e9;
        string temp = "";
        for (int k = i; k < n; k++)
        {
            temp += s[k];
            if(isPalindrome(temp)){
                int count = 1 + dp[k+1];
                mini = min(mini, count);
            }
        }
        dp[i] = mini;
    }
    return dp[0];
}

int main()
{
    string s;
    cin>>s;

    // cout<<recursion(0,s)-1;//bc our code also does partition at the end
    // vector<int>dp(s.size(),-1);
    // cout<<memoization(0,s,dp) - 1;
    cout<<tabulation(s) - 1;
    
    return 0;
}