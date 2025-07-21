#include<iostream>
#include<bits/stdc++.h>
using namespace std;

class solution{
    public:
        void fun(int index, int target, vector<int>&ds, vector<vector<int>>&ans,vector<int>&arr, int n){
            //for optimization
            //if(target==0) ans.push_back(ds);
            if(index == n){
                if(target == 0){
                    ans.push_back(ds);
                }
                return;
            }

            //for take
            if(arr[index] <= target){
                ds.push_back(arr[index]);
                fun(index, target-arr[index], ds,ans,arr,n);
                //while returning
                ds.pop_back();
            }

            //for not take
            fun(index+1,target, ds,ans,arr,n);

        }
    public:
        vector<vector<int>> fun1(vector<int>&arr,int n, int target){
            vector<vector<int>>ans;
            vector<int>ds;
            fun(0,target,ds,ans,arr,n);
            return ans;
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
    vector<vector<int>>output =  obj.fun1(arr,n,target);
    for(auto it : output){
        for(int num : it){
            cout<<num<<" ";
        }
        cout<<endl;
    }
    
    return 0;
}