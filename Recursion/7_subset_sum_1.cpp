#include<iostream>
#include<bits/stdc++.h>
using namespace std;

void fun1(int index,int sum,vector<int>&ds,vector<int>&arr,int n){
    if(index == n){
        ds.push_back(sum);
        return;
    }
    //for take
    sum = sum + arr[index];
    fun1(index+1,sum,ds,arr,n); //fun1(index+1,sum+arr[index],ds,arr,n);
    //while returning
    sum = sum - arr[index];
    //for not take
    fun1(index+1,sum,ds,arr,n); //fun1(index+1,sum,ds,arr,n);
}

vector<int> fun(vector<int>&arr, int n){
    vector<int>ds;
    fun1(0,0,ds,arr,n);
    sort(ds.begin(),ds.end());
    return ds;
}
int main()
{
    int n;
    cout<<"enter the size of array: ";
    cin>>n;
    vector<int>arr(n);
    for (int  i = 0; i < n; i++)
    {
        cin>>arr[i];
    }

    vector<int>output = fun(arr,n);
    for(auto it : output){
        cout<<it<<" ";
    }
    
    return 0;
}