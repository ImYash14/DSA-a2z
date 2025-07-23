#include<iostream>
#include<bits/stdc++.h>
using namespace std;

int fun(vector<int>&arr, int n){
    int ans =0;
    for (int i = 0; i < n; i++)
    {
        ans = ans^arr[i];
    }
    return ans;
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
    
    cout<<fun(arr,n);

    return 0;
}