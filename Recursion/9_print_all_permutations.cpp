#include<iostream>
#include<bits/stdc++.h>
using namespace std;

void fun2(int index, vector<vector<int>>&ans,vector<int>&arr, int n){
    if(index == n){
        ans.push_back(arr);
    }

    for (int i = index; i < n; i++)
    {
        swap(arr[index],arr[i]); 
        // ex-> swap 1->1, 1->2, 1->3
        //swap 2->2, 2->3 etc;
        fun2(index+1,ans,arr,n);

        //while returning
        swap(arr[index], arr[i]);
    }
    
}

void fun1(vector<int>&ds,vector<int>&hasharr,vector<vector<int>>&ans,vector<int>&arr, int n){
    if(ds.size() == n){
        ans.push_back(ds);
        return;
    }

    for (int i = 0; i < n; i++) //for all possible indexes
    {
        if(!hasharr[i]){ //if i is not marked in hash
            ds.push_back(arr[i]);
            hasharr[i] =1;

            fun1(ds,hasharr,ans,arr,n);

            //while returning
            hasharr[i] =0;
            ds.pop_back();
        }
    }
    
}

vector<vector<int>> fun(vector<int>&arr, int n){
    vector<int>ds;
    vector<vector<int>>ans;
    vector<int>hasharr(n,0);
    // fun1(ds,hasharr,ans,arr,n);
    fun2(0,ans,arr,n);
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

    vector<vector<int>>output = fun(arr,n);
    for(auto it: output){
        for(int num : it){
            cout<<num<<" ";
        }
        cout<<endl;
    }
    
    return 0;
}