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

int fun(vector<int> &arr, int n, int divisor){
    int ans =0;
    for (int i = 0; i < n; i++)
    {
        ans = ans + ceil((double)arr[i]/divisor);
    }
    return ans;   
}

int brute(vector<int> &arr, int n, int threshold){
    if(n > threshold) return -1;
    for (int i = 1; i < maxArray(arr,n); i++)
    {
        if(fun(arr,n,i) <= threshold){
            return i;
        }
    }
    return -1;   
}

int optimal(vector<int>&arr, int n, int threshold){
    int low =1;
    int high = maxArray(arr,n);
    if(n > threshold) return -1;
    while(low<=high){
        int mid =(low+high)/2;
        if(fun(arr,n,mid) <= threshold){
            high = mid-1;
        }
        else low = mid+1;
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

    int threshold;
    cout<<"enter the threshold: ";
    cin>>threshold;

    // cout<<brute(arr,n,threshold);
    cout<<optimal(arr,n,threshold);
    
    return 0;
}