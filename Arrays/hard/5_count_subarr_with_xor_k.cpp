#include<iostream>
#include<bits/stdc++.h>
using namespace std;

void brute(vector<int> &arr, int n, int k){
    int count =0;
    for (int i = 0; i < n; i++)
    {
        for (int j = i; j < n; j++)
        {
            int xor1 = 0;
            for (int x = i; x <= j; x++)
            {
                xor1 = xor1 ^ arr[x];
            }
            if(xor1 == k) count++;
            
        }
        
    }
    cout<<count;
    
}

void better(vector<int> &arr, int n, int k){
    int count =0;
    for (int i = 0; i < n; i++)
    {
        int xor1 = 0;
        for (int j = i; j < n; j++)
        {
            xor1 = xor1 ^ arr[j];            
            if(xor1 == k) count++;
        }
        
    }
    cout<<count;
    
}

void optimal(vector<int> &arr, int n, int k){
    int xr =0;
    int count =0;
    int x;
    map<int,int> mpp;
    mpp[xr]++;//{0,1}
    
    for (int i = 0; i < n; i++)
    {
        xr = xr ^ arr[i];
        x = xr ^ k;
        if(mpp.find(x) != mpp.end()){
            count = count + mpp[x];
        }
        mpp[xr]++;
    
    }
    cout<<count;
    
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
    cout<<"enter the xor: ";
    cin>>k;

    // brute(arr,n,k);
    // better(arr,n,k);
    optimal(arr,n,k);
    
    return 0;
}