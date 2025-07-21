#include<iostream>
#include<bits/stdc++.h>
using namespace std;

void brute(vector<int> &arr, int n, int k){
    int count =0;
    for (int i = 0; i < n; i++)
    {
        for (int j = i; j < n; j++)
        {
            int sum =0;
            for (int x = i; x <= j; x++)
            {
                sum = sum + arr[x];
            }
            if(sum== k){
                count++;
            }
            
        }
        
    }
    cout<<count;
    
}

void better(vector<int> &arr, int n, int k){
    int count =0;
    for (int i = 0; i < n; i++)
    {
        int sum =0;
        for (int j = i; j < n; j++)
        {
            sum = sum + arr[j];
            
            if(sum== k){
                count++;
            }
            
        }
        
    }
    cout<<count;
    
}

void optimal(vector<int> &arr, int n, int k){
    map<int, int> mpp;// <prefsum,count>
    mpp[0] =1;
    int prefSum =0;
    int count = 0;

    for (int i = 0; i < n; i++)
    {
        prefSum += arr[i];
        int remove = prefSum-k;
        count += mpp[remove];
        mpp[prefSum] += 1;
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
    cout<<"enter the sum: ";
    cin>>k;

    optimal(arr,n,k);
    
    return 0;
}