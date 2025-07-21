#include<iostream>
#include<bits/stdc++.h>
using namespace std;

//we can also right this code without using extra ds
int fun(int index, int sum, vector<int>&ds,vector<int>&arr, int n, int k){
    if(index == n){
        if(sum == k){
            return 1; //if sum=k was found
        }
        return 0; //if sum=k was not found
    }
    
    //for take
    ds.push_back(arr[index]);
    sum = sum + arr[index];
    int left = fun(index+1, sum,ds,arr,n,k);

    //while returning
    ds.pop_back();
    sum = sum - arr[index];

    //for not take
    int right = fun(index+1, sum,ds,arr,n,k);

    return left+right;
}
int main()
{
    int n;
    cout<<"enter the size of arr: ";
    cin>>n;
    vector<int>arr(n);
    for (int i = 0; i < n; i++)
    {
        cin>>arr[i];
    }
    int k;
    cout<<"enter the sum: ";
    cin>>k;
    vector<int>ds;
    
    cout<<fun(0,0,ds,arr,n,k);
    return 0;
}