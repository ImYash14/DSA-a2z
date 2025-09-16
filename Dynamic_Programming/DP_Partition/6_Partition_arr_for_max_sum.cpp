#include<iostream>
#include<bits/stdc++.h>
using namespace std;

int recursion(int index, int k,vector<int>&arr){
    int n = arr.size();

    //base case
    if(index == n) return 0;//no arr left

    //try front partitioning on the index
    int len =0;
    int ans = -1e9;
    int maxi = -1e9;
    for (int p = index; p < min(index+k,n); p++)
    {
        len++;
        maxi = max(maxi,arr[p]);
        int sum = (len*maxi) + recursion(p+1,k,arr);

        ans = max(ans,sum);
    }
    return ans;
}

int memoization(int index, int k,vector<int>&arr,vector<int>&dp){
    int n = arr.size();

    //base case
    if(index == n) return 0;//no arr left

    if(dp[index] != -1) return dp[index];

    //try front partitioning on the index
    int len =0;
    int ans = -1e9;
    int maxi = -1e9;
    for (int p = index; p < min(index+k,n); p++)
    {
        len++;
        maxi = max(maxi,arr[p]);
        int sum = (len*maxi) + memoization(p+1,k,arr,dp);

        ans = max(ans,sum);
    }
    return dp[index] = ans;
}

int tabulation(int k,vector<int>&arr){
    int n = arr.size();

    vector<int>dp(n+1,0);
    //base case
    dp[n] =0;

    //for loop for states in rev of recursion
    for (int index = n-1; index >=0; index--)
    {
        int len =0;
        int ans = -1e9;
        int maxi = -1e9;
        for (int p = index; p < min(index+k,n); p++)
        {
            len++;
            maxi = max(maxi,arr[p]);
            int sum = (len*maxi) + dp[p+1];

            ans = max(ans,sum);
        }
        dp[index] = ans;
    }
    return dp[0];
}

int main()
{
    int n;
    cin>>n;
    vector<int>arr(n);
    for (int i = 0; i < n; i++)
    {
        cin>>arr[i];
    }
    int k;
    cin>>k;
    
    // cout<<recursion(0,k,arr);
    // vector<int>dp(n,-1);
    // cout<<memoization(0,k,arr,dp);
    cout<<tabulation(k,arr);
    
    return 0;
}