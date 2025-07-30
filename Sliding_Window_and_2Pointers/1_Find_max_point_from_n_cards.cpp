#include<iostream>
#include<bits/stdc++.h>
using namespace std;

int brute(vector<int>&arr, int n, int k){
    int lsum =0;
    int rsum =0;
    int maxSum =0;
    for (int i = 0; i <= k-1; i++)
    {
        lsum = lsum + arr[i];
    }

    int rightIndex =n-1;
    for (int i = k-1; i>=0; i--)
    {
        lsum = lsum - arr[i];
        rsum = rsum + arr[rightIndex];
        rightIndex--;
        maxSum = max(maxSum, lsum + rsum);
    }
    return maxSum;   
}

int main()
{
    int n;
    cout<<"enter the no. of cards: ";
    cin>>n;
    vector<int>arr(n);
    for (int i = 0; i < n; i++)
    {
        cin>>arr[i];
    }

    int k;
    cout<<"enter the no. of cards to pick: ";
    cin>>k;

    cout<<brute(arr,n,k);
    
    return 0;
}