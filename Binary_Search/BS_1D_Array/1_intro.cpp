#include<iostream>
#include<bits/stdc++.h>
using namespace std;

int iterativeBS(vector<int>&arr, int n, int target){
    int low = 0;
    int high = n-1;
    while(low <= high){
        int mid = (low+high)/2;
        if(target == arr[mid]) return mid;
        else if(target > arr[mid]) low = mid+1; //we go right
        else high = mid-1;  //we go left
    }
    return -1;
}

int recursiveBS(vector<int>&arr, int n, int target, int low, int high){
    if(low > high) return -1;
    int mid = (low+high)/2;
    if(target == arr[mid]) return mid;
    else if(target > arr[mid]){
        return recursiveBS(arr,n,target,mid+1,high);  //we go right
    }
    else{
        return recursiveBS(arr,n,target,low,mid-1);   //we go left
    }
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

    int target;
    cout<<"enter the target: ";
    cin>> target;

    // cout<<iterativeBS(arr,n,target);
    cout<<recursiveBS(arr,n,target,0,n-1);
    
    return 0;
}