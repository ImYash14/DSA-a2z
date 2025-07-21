#include<iostream>
#include<bits/stdc++.h>
using namespace std;

void fun(int index,vector<int>&ds, vector<int>&arr, int n){
    //base case
    if(index == n){
        for(auto it : ds){
            cout<<it<<" ";
        }
        if(ds.size() == 0){
            cout<<"[]";
        }
        cout<<endl;
        return;
    }

    //for take->the element will be added in subsequence
    ds.push_back(arr[index]);
    fun(index+1,ds,arr,n);
    ds.pop_back();

    //for not-take->the element will not be added in subsequence
    fun(index+1,ds,arr,n);

    //we can also reverse the conditions of take and not-take
    //the ans will be same but in reversed order
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
    vector<int>ds;
    
    fun(0,ds,arr,n);
    
    return 0;
}