#include<iostream>
#include<bits/stdc++.h>
using namespace std;

int longestBitonic(vector<int>&arr){
    int n = arr.size();

    //from front
    vector<int>dp1(n,1);
    for (int i = 0; i < n; i++)
    {
        for (int prev = 0; prev < i; prev++)
        {
            if(arr[prev] < arr[i]){
                dp1[i] = max(dp1[i], 1 + dp1[prev]);
            }
        }        
    }

    //from back
    vector<int>dp2(n,1);
    for (int i = n-1; i >=0; i--)
    {
        for (int prev = n-1; prev > i; prev--)
        {
            if(arr[prev] < arr[i]){
                dp2[i] = max(dp2[i], 1 + dp2[prev]);
            }
        }        
    }

    //for bitonic
    int ans =0;
    for (int i = 0; i < n; i++)
    {
        ans = max(ans, dp1[i] + dp2[i] - 1);
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
    
    cout<<longestBitonic(arr);
    
    return 0;
}