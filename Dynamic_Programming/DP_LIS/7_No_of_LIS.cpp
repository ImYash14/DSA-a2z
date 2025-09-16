#include<iostream>
#include<bits/stdc++.h>
using namespace std;

int noOfLIS(vector<int>&arr){
    int n = arr.size();

    vector<int>dp(n,1);
    vector<int>count(n,1);

    int maxi =0;
    for (int i = 0; i < n; i++)
    {
        for (int prev = 0; prev < i; prev++)
        {
            if(arr[prev] < arr[i] && 1 + dp[prev] > dp[i]){
                dp[i] = 1 + dp[prev];
                count[i] = count[prev]; //inherit
            }
            else if(arr[prev] < arr[i] && 1 + dp[prev] == dp[i]){
                count[i] += count[prev]; //increase
            }
        }
        maxi = max(maxi,dp[i]);
    }
    
    //count all subsequences whose length is maxi
    int ans =0;
    for (int i = 0; i < n; i++)
    {
        if(dp[i] == maxi){
            ans += count[i];
        }
    }
    return ans;
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
    
    cout<<noOfLIS(arr);
    
    return 0;
}