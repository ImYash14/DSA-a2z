#include<iostream>
#include<bits/stdc++.h>
using namespace std;

int fun(vector<int>&arr, int n, int k){
    int l=0,r=0;
    int count =0;
    int sum =0;
    while(r<n){
        sum = sum + (arr[r]%2);

        while(sum > k){
            sum = sum - (arr[l]%2);
            l++;
        }

        count = count + (r-l+1);
        r++;
    }
    return count;
}

int optimal(vector<int>&arr, int n, int k){
    return fun(arr,n,k)-fun(arr,n,k-1);
}

int main()
{
    int n;
    cout<<"enter the size of array: ";
    cin>>n;
    vector<int>arr(n);
    for (int i = 0; i < n; i++)
    {
        cin>>arr[i];
    }

    int k;
    cout<<"enter the no. of odd nums: ";
    cin>>k;

    cout<<optimal(arr,n,k);
    
    return 0;
}