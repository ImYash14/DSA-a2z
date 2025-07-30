#include<iostream>
#include<bits/stdc++.h>
using namespace std;

int brute(vector<int>&arr, int n, int k){
    int maxlen =0;
    for (int i = 0; i < n; i++)
    {
        int zeros =0;
        for (int j = i; j < n; j++)
        {
            if(arr[j] == 0) zeros++;
            if(zeros <= k){
                maxlen = max(maxlen, j-i+1);
            }
            else break;
        }
        
    }
    return maxlen;
}

int better(vector<int>&arr, int n, int k){
    int maxlen =0;
    int zeros =0;
    int l =0;
    int r =0;
    while(r<n){
        if(arr[r] == 0) zeros++;

        while(zeros > k){
            if(arr[l]==0) zeros--;
            l++;
        }

        if(zeros<=k){
            maxlen = max(maxlen,r-l+1);
        }
        r++;
    }
    return maxlen;
}

int optimal(vector<int>&arr, int n, int k){
    int maxlen =0;
    int zeros =0;
    int l =0;
    int r =0;
    while(r<n){
        if(arr[r] == 0) zeros++;

        if(zeros > k){
            if(arr[l]==0) zeros--;
            l++; //it will only shift one place regardless of validity of zeros
        }

        if(zeros<=k){
            maxlen = max(maxlen,r-l+1);
        }
        r++;
    }
    return maxlen;
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
    cout<<"enter the no. of atmost zeros to be flipped: ";
    cin>>k;

    // cout<<brute(arr,n,k);
    // cout<<better(arr,n,k);
    cout<<optimal(arr,n,k);

    return 0;
}