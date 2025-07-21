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

int fun(vector<int> &arr, int n, int capacity){
    int day =1;
    int load =0;
    for (int i = 0; i < n; i++)
    {
        if(load + arr[i] > capacity){
            day++;
            load = arr[i];
        }
        else{
            load += arr[i];
        }
    }
    return day;
    
}

int brute(vector<int> &arr, int n, int days){
    for (int i = maxArray(arr,n); i <= sumArray(arr,n); i++)
    {
        if(fun(arr,n,i) <= days){
            return i;
        }
    }
    return -1;
}

int optimal(vector<int> &arr, int n, int days){
    int low = maxArray(arr,n);
    int high = sumArray(arr,n);
    while(low<=high){
        int mid = (low+high)/2;
        if(fun(arr,n,mid) <= days){
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
    cout<<"enter the size of array of item weights: ";
    cin>>n;
    vector<int> arr(n);
    for (int i = 0; i < n; i++)
    {
        cin>>arr[i];
    }

    int days;
    cout<<"enter the no. of days: ";
    cin>>days;

    // cout<<brute(arr,n,days);
    cout<<optimal(arr,n,days);
    
    return 0;
}