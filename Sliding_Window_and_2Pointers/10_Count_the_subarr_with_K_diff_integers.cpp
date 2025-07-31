#include<iostream>
#include<bits/stdc++.h>
using namespace std;

int brute(vector<int>&arr, int n, int k){
    int count =0;
    for (int i = 0; i < n; i++)
    {
        map<int,int>mpp;
        for (int j = i; j < n; j++)
        {
            mpp[arr[j]]++;
            if(mpp.size()==k){
                count++;
            }
            else if(mpp.size()>k) break;
        }
        
    }
    return count;
}

int fun(vector<int>&arr, int n, int k){
    int l=0;
    int r=0;
    int count =0;
    map<int,int>mpp;
    while(r<n){
        mpp[arr[r]]++;

        while(mpp.size() >k){
            mpp[arr[l]]--;
            if(mpp[arr[l]]==0) mpp.erase(arr[l]);
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
    cout<<"enter the no. of differnet integers: ";
    cin>>k;

    // cout<<brute(arr,n,k);
    cout<<optimal(arr,n,k);
    
    return 0;
}