#include<iostream>
#include<bits/stdc++.h>
using namespace std;

class solution{
    public:
    void fun3(int index, int target, vector<int>&ds, vector<vector<int>>&ans, vector<int>&arr, int n){
        if(target == 0){
            ans.push_back(ds);
            return;
        }
        for (int i = index; i < n; i++)
        {
            if(i>index && arr[i]==arr[i-1]) continue; //to avoid duplicate
            if(arr[i] > target) return; //or break

            ds.push_back(arr[i]);
            fun3(i+1,target-arr[i], ds,ans,arr,n);
            //while returning
            ds.pop_back();
        }
        
    }
    public:
    void fun2(int index,int target,vector<int>&ds,set<vector<int>>&ans,vector<int>&arr,int n ){
        if(index == n){
            if(target ==0){
                ans.insert(ds);
            }
            return;
        }
        //for take
        if(arr[index] <= target){
            ds.push_back(arr[index]);
            fun2(index+1,target-arr[index],ds,ans,arr,n);
            //while returning
            ds.pop_back();
        }
        //for not take
        fun2(index+1,target,ds,ans,arr,n);

    }
    public:
    void fun1(int index,int sum,int target,vector<int>&ds,set<vector<int>>&ans,vector<int>&arr,int n){
        if(index == n){
            if(sum == target){
                sort(ds.begin(),ds.end());
                ans.insert(ds);
            }
            return;
        }
        //for take
        ds.push_back(arr[index]);
        sum = sum+ arr[index];
        fun1(index+1,sum,target,ds,ans,arr,n);
        //while returning
        ds.pop_back();
        sum = sum- arr[index];

        //for not take
        fun1(index+1,sum,target,ds,ans,arr,n);
    }
    public:
    vector<vector<int>> fun(vector<int>&arr, int n, int target){
        sort(arr.begin(),arr.end());
        vector<vector<int>>ans;
        vector<int>ds;
        // fun1(0,0,target,ds,ans,arr,n);
        // fun2(0,target,ds,ans,arr,n);
        fun3(0,target,ds,ans,arr,n);
        
        vector<vector<int>>finalans(ans.begin(),ans.end());
        return finalans;
    }
};
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
    int target;
    cout<<"enter the target: ";
    cin>>target;

    solution obj;
    vector<vector<int>>output = obj.fun(arr,n,target);
    for(auto it : output){
        for(int num : it){
            cout<<num<<" ";
        }
        cout<<endl;
    }
    
    return 0;
}