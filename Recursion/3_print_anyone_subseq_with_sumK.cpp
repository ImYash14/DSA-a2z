#include<iostream>
#include<bits/stdc++.h>
using namespace std;

bool fun(int index, int sum, vector<int>&ds, vector<int>&arr, int n, int k){
    if(index == n){
        if(sum == k){
            for(auto it: ds) cout<<it<<" ";
            return true; //sum=k was found
        }
        return false; //sum=k was not found
    }

    //for take
    ds.push_back(arr[index]);
    sum = sum+ arr[index];
    if(fun(index+1,sum,ds,arr,n,k) == true){
        return true;
    }

    ds.pop_back();
    sum = sum- arr[index];

    //for not take
    if(fun(index+1,sum,ds,arr,n,k) == true){
        return true;
    }

    return false;
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
    
    fun(0,0,ds,arr,n,k);
    
    return 0;
}