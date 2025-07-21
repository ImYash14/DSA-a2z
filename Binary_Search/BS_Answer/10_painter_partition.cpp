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

int fun(vector<int>&arr, int n, int unitTime){
    int painters =1;
    int timeTaken =0;
    for (int i = 0; i < n; i++)
    {
        if(timeTaken + arr[i] > unitTime){
            painters++;
            timeTaken = arr[i];
        }
        else{
            timeTaken += arr[i];
        }
    }
    return painters;
}

int brute(vector<int> &arr, int n, int k){
    if(k>n) return -1;
    for (int unitTime = maxArray(arr,n); unitTime <= sumArray(arr,n); unitTime++)
    {
        if(fun(arr,n,unitTime) <= k){
            return unitTime;
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
    cout<<"enter the no. of boards to be painted: ";
    cin>>n;

    //take the lengths of each board
    vector<int> arr(n);
    for (int i = 0; i < n; i++)
    {
        cin>>arr[i];
    }

    int k;
    cout<<"enter the no. of painters: ";
    cin>>k;
    
    // cout<<brute(arr,n,k);
    cout<<optimal(arr,n,k);

    return 0;
}