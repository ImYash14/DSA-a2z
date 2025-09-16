#include<iostream>
#include<bits/stdc++.h>
using namespace std;

vector<int> LBS(vector<int>&arr){
    int n = arr.size();

    int maxi = 1;
    int lastindex = 0;
    vector<int>dp(n,1);
    vector<int>hasharr(n);

    sort(arr.begin(),arr.end());
    for (int i = 0; i < n; i++)
    {
        hasharr[i] = i;
        for (int prev = 0; prev < i; prev++)
        {
            if(arr[i]%arr[prev] == 0 && 1+dp[prev] > dp[i]){
                dp[i] = 1+dp[prev];
                hasharr[i] = prev;
            }
        }
        if(dp[i] > maxi){
            maxi = dp[i];
            lastindex = i;
        }
    }

    //backtracking to find the ans
    vector<int>ans;
    ans.push_back(arr[lastindex]);
    while(hasharr[lastindex] != lastindex){
        lastindex = hasharr[lastindex];
        ans.push_back(arr[lastindex]);
    }
    
    reverse(ans.begin(),ans.end());
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

    vector<int>output = LBS(arr);
    for(auto it : output){
        cout<<it<<" ";
    }
    
    
    return 0;
}