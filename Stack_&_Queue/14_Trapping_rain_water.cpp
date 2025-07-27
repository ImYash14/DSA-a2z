#include<iostream>
#include<bits/stdc++.h>
using namespace std;

int brute(vector<int>&arr, int n){
    int total =0;
    vector<int>prefixMax(n);
    prefixMax[0] = arr[0];
    for (int i = 1; i < n; i++)
    {
        prefixMax[i] = max(prefixMax[i-1],arr[i]);
    }
    vector<int>suffixMax(n);
    suffixMax[n-1] = arr[n-1];
    for (int i = n-2; i >=0; i--)
    {
        suffixMax[i] = max(suffixMax[i+1],arr[i]);
    }
    
    for (int i = 0; i < n; i++)
    {
        int leftMax = prefixMax[i];
        int rightMax = suffixMax[i];
        if(arr[i] < leftMax && arr[i]<rightMax){
            total += min(leftMax,rightMax)-arr[i];
        }
    }
    return total;
}

int main()
{
    int n;
    cout<<"enter the no. of buildings: ";
    cin>>n;
    cout<<"enter the building heights: ";
    vector<int>arr(n);
    for (int i = 0; i < n; i++)
    {
        cin>>arr[i];
    }

    cout<<brute(arr,n);
    
    return 0;
}