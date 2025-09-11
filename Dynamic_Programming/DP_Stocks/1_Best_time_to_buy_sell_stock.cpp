#include<iostream>
#include<bits/stdc++.h>
using namespace std;

int maxProfit(vector<int>&arr){
    int n = arr.size();

    int mini = arr[0];
    int profit = 0;
    for (int i = 1; i < n; i++)
    {
        int cost = arr[i] - mini;
        profit = max(profit, cost);
        mini = min(mini,arr[i]);
    }
    return profit;
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
    
    cout<<maxProfit(arr);
    
    return 0;
}