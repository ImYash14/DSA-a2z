#include<iostream>
#include<bits/stdc++.h>
using namespace std;

int recursion(int index, vector<int>&arr){
    if(index == 0) return arr[index];
    if(index < 0) return 0;

    int pick = arr[index] + recursion(index-2, arr);//for non adjacent
    int notpick = 0 + recursion(index-1,arr);

    return max(pick, notpick);
}

int memoization(int index, vector<int>&dp, vector<int>&arr){
    if(index == 0) return arr[index];
    if(index < 0) return 0;

    if(dp[index] != -1) return dp[index];

    //else
    int pick = arr[index] + recursion(index-2, arr);//for non adjacent
    int notpick = 0 + recursion(index-1,arr);

    return max(pick, notpick);
}

int tabulation(int n,vector<int>&dp, vector<int>&arr){
    dp[0] = arr[0];
    int neg = 0;

    for (int i = 1; i <= n-1; i++)
    {
        int pick = arr[i];
        if(i >1) pick += dp[i-2];
        int notpick = 0 + dp[i-1];

        dp[i] = max(pick, notpick);
    }
    return dp[n-1];
}

int spaceopt(int n, vector<int>&arr){
    int prev = arr[0]; //dp[i-1]
    int prev2 = 0; //dp[i-2]

    for (int i = 1; i <= n-1; i++)
    {
        int pick = arr[i];
        if(i >1) pick += prev2;
        int notpick = 0 + prev;

        int curr = max(pick, notpick);
        prev2 = prev;
        prev = curr;
    }
    return prev;
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
    
    cout<<recursion(n-1,arr);
    
    return 0;
}