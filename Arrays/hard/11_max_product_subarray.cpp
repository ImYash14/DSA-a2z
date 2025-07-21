#include<iostream>
#include<bits/stdc++.h>
using namespace std;

void brute(vector<int>&arr, int n){
    int maxi = INT_MIN;
    for (int i = 0; i < n; i++)
    {
        for (int j = i; j < n; j++)
        {
            int prod =1;
            for (int k = i; k < j; k++)
            {
                prod = prod * arr[k];
            }
            maxi = max(maxi, prod);
        }
        
    }
    cout<<maxi;
    
}

void better(vector<int>&arr, int n){
    int maxi = INT_MIN;
    for (int i = 0; i < n; i++)
    {
        int prod =1;
        for (int j = i; j < n; j++)
        {
            prod = prod * arr[j];
            maxi = max(maxi, prod);           
        }
        
    }
    cout<<maxi;
    
}

void optimal(vector<int> &arr, int n){
    int maxi = INT_MIN;
    int prefix = 1;
    int suffix =1;
    for (int i = 0; i < n; i++)
    {
        if(prefix == 0) prefix =1;
        else if (suffix == 0) suffix =1;

        prefix = prefix*arr[i];
        suffix = suffix*arr[n-i-1];

        maxi = max(maxi, max(prefix, suffix));
    }
    cout<<maxi;
    
}
int main()
{
    int n;
    cout<<"enter the size of aray: ";
    cin>>n;
    vector<int> arr(n);
    for (int i = 0; i < n; i++)
    {
        cin>>arr[i];
    }

    // brute(arr,n);
    // better(arr,n);
    optimal(arr,n);
    
    return 0;
}