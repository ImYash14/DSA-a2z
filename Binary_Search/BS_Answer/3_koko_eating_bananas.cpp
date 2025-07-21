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

int fun(vector<int>&arr, int n, int i){
    int totalHrs =0;
    for (int x = 0; x < n; x++)
    {
        totalHrs = totalHrs + ceil((double)arr[x]/i);
    }
    return totalHrs;
    
}

int brute(vector<int> &arr, int n, int h){
    for (int i = 1; i <= maxArray(arr,n); i++)
    {
        int reqTime = fun(arr,n,i);
        if(reqTime <= h) return i;
    }
    return -1;
    
}

int optimal(vector<int>&arr, int n, int h){
    int low =1;
    int high = maxArray(arr,n);
    while(low<=high){
        int mid = (low+high)/2;
        if(fun(arr,n,mid) <= h){
            high = mid -1;
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
    cout<<"enter the size of array of piles: ";
    cin>>n;

    vector<int> arr(n);
    for (int i = 0; i < n; i++)
    {
        cin>>arr[i];
    }

    int h;
    cout<<"enter the total min hour: ";
    cin>>h;

    // cout<<brute(arr,n,h);
    cout<<optimal(arr,n,h);
    
    return 0;
}