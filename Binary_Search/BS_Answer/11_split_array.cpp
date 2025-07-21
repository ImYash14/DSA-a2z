#include<iostream>
#include<bits/stdc++.h>
using namespace std;

int maxArray(vector<int>&arr, int n){
    int ans = arr[0];
    for (int i = 0; i < n; i++)
    {
        if(arr[i] > ans){
            ans = arr[i];
        }
    }
    return ans;   
}

int sumArray(vector<int>&arr, int n){
    int ans =0;
    for (int i = 0; i < n; i++)
    {
        ans = ans + arr[i];
    }
    return ans;   
}

int fun(vector<int>&arr, int n, int maxSum){
    int subArrays = 1;
    int totalSum =0;
    for (int i = 0; i < n; i++)
    {
        if(totalSum + arr[i] > maxSum){
            subArrays++;
            totalSum = arr[i];
        }
        else{
            totalSum += arr[i];
        }
    }
    return subArrays;
}

int brute(vector<int>&arr, int n, int k){
    if(k>n) return -1;
    for (int maxSum = maxArray(arr,n); maxSum <= sumArray(arr,n); maxSum++)
    {
        if(fun(arr,n,maxSum) <= k){
            return maxSum;
        }
    }
    return -1;
}

int optimal(vector<int>&arr, int n, int k){
    if(k>n) return -1;
    int low = maxArray(arr,n);
    int high = sumArray(arr,n);
    while(low<=high){
        int mid = (low+high)/2;
        if(fun(arr,n,mid) <= k){
            high = mid-1;
        }
        else{
            low = mid+1;
        }
    }
    return low;
}
int main()
{
    int n;
    cout<<"enter the size of array: ";
    cin>>n;

    vector<int> arr(n);
    for (int i = 0; i < n; i++)
    {
        cin>>arr[i];
    }

    int k;
    cout<<"enter the no. of subarrays: ";
    cin>>k;
    
    // cout<<brute(arr,n,k);
    cout<<optimal(arr,n,k);

    return 0;
}