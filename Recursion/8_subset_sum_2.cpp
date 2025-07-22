#include<iostream>
#include<bits/stdc++.h>
using namespace std;

void fun1(int index,vector<int>&ds, vector<vector<int>>&ans,vector<int>&arr, int n){
     ans.push_back(ds);
    //initially pushes the empty subset and later on all the subsets
    //here no need of base case
    //so no need to pop back because no returning
    //and we will be going level by level(level0,0-size subsets), (level1,1-size subsets),etc
    for (int i = index; i < n; i++)
    {
        if(i>index && arr[i] == arr[i-1]) continue;//for avoiding duplicate
        
        ds.push_back(arr[i]);
        
        fun1(i+1,ds,ans,arr,n);
        //this pop will be not for the returning
        //instead for moving from index to n for each level
        ds.pop_back();
    }
    
}

vector<vector<int>> fun(vector<int>&arr, int n){
    sort(arr.begin(),arr.end());
    vector<int>ds;
    vector<vector<int>>ans;
    fun1(0,ds,ans,arr,n);
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