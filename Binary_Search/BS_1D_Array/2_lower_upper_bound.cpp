#include<iostream>
#include<bits/stdc++.h>
using namespace std;

int lowerBound(vector<int>&arr, int n, int target){
    int low =0;
    int high = n-1;
    int ans = n;
    while(low <= high){
        int mid = (low + high)/2;
        if(arr[mid] >= target){ 
            ans = mid; //may or may not be the ans
            high = mid-1;
        }
        else{
            low = mid+1;
        }
    }
    return ans; //can also return low as well
}

int upperBound(vector<int>&arr, int n, int target){
    int low =0;
    int high = n-1;
    int ans = -1;
    while(low <= high){
        int mid = (low + high)/2;
        if(arr[mid] > target){ 
            ans = mid; //may or may not be the ans
            high = mid-1;
        }
        else{
            low = mid+1;
        }
    }
    return ans; //can also return low as well
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
    cin>>target;

    // cout<<lowerBound(arr,n,target);
    // cout<<upperBound(arr,n,target);

    //shortcut
    int lower = lower_bound(arr.begin(), arr.end(), target) - arr.begin();
    cout<<lower;
    int upper = upper_bound(arr.begin(), arr.end(), target) - arr.begin();
    cout<<upper;
    
    return 0;
}