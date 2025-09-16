#include<iostream>
#include<bits/stdc++.h>
using namespace std;

int recursion(int i,int j,int isTrue,string &s){
    //base case
    if(i>j) return 0;//no partitions left
    if(i == j){
        if(isTrue == 1) return (s[i] == 'T'); //if we are looking for T
        else return (s[i] == 'F'); //if we are looking for F
    }

    //try to make all possible partitions on operators
    int ways =0;
    for (int k = i+1; k <= j-1; k+=2)
    {
        //no. of ways in which left or right partition gives T or F
        int leftTrue = recursion(i,k-1,1,s);
        int leftFalse = recursion(i,k-1,0,s);
        int rightTrue = recursion(k+1,j,1,s);
        int rightFalse = recursion(k+1,j,0,s);

        if(s[k] == '&'){
            if(isTrue == 1){
                ways += (leftTrue*rightTrue);
            }
            else{
                ways += (leftTrue*rightFalse)+(leftFalse*rightTrue)+(leftFalse*rightFalse);
            }
        }
        else if(s[k] == '|'){
            if(isTrue == 1){
                ways += (leftTrue*rightTrue)+(leftTrue*rightFalse)+(leftFalse*rightTrue);
            }
            else{
                ways += (leftFalse*rightFalse);
            }
        }
        else{//s[k] == '^'
            if(isTrue == 1){
                ways += (leftTrue*rightFalse) + (leftFalse*rightTrue);
            }
            else{
                ways += (leftTrue*rightTrue) + (leftFalse*rightFalse);
            }
        }
    }
    return ways;
}

int memoization(int i,int j,int isTrue,string &s,vector<vector<vector<int>>>&dp){
    //base case
    if(i>j) return 0;//no partitions left
    if(i == j){
        if(isTrue == 1) return (s[i] == 'T'); //if we are looking for T
        else return (s[i] == 'F'); //if we are looking for F
    }

    if(dp[i][j][isTrue] != -1) return dp[i][j][isTrue];

    //try to make all possible partitions on operators
    int ways =0;
    for (int k = i+1; k <= j-1; k+=2)
    {
        //no. of ways in which left or right partition gives T or F
        int leftTrue = memoization(i,k-1,1,s,dp);
        int leftFalse = memoization(i,k-1,0,s,dp);
        int rightTrue = memoization(k+1,j,1,s,dp);
        int rightFalse = memoization(k+1,j,0,s,dp);

        if(s[k] == '&'){
            if(isTrue == 1){
                ways += (leftTrue*rightTrue);
            }
            else{
                ways += (leftTrue*rightFalse)+(leftFalse*rightTrue)+(leftFalse*rightFalse);
            }
        }
        else if(s[k] == '|'){
            if(isTrue == 1){
                ways += (leftTrue*rightTrue)+(leftTrue*rightFalse)+(leftFalse*rightTrue);
            }
            else{
                ways += (leftFalse*rightFalse);
            }
        }
        else{//s[k] == '^'
            if(isTrue == 1){
                ways += (leftTrue*rightFalse) + (leftFalse*rightTrue);
            }
            else{
                ways += (leftTrue*rightTrue) + (leftFalse*rightFalse);
            }
        }
    }
    return dp[i][j][isTrue] = ways;
}

int main()
{
    string s;
    cin>>s;

    int n = s.size();

    // cout<<recursion(0,n-1,1,s);
    vector<vector<vector<int>>>dp(n,vector<vector<int>>(n,vector<int>(2,-1)));
    cout<<memoization(0,n-1,1,s,dp);
    
    return 0;
}