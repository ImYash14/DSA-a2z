#include<iostream>
#include<bits/stdc++.h>
using namespace std;

vector<vector<int>> fun(vector<int>&arr,int n){
    vector<vector<int>>ans;
    int subsets = 1<<n; 
    for (int num = 0; num < subsets; num++)
    {
        vector<int>temp;
        for (int i = 0; i < n; i++)
        {
            if((num & (1<<i))){ //check the set bits
                temp.push_back(arr[i]);
            }
        }
        ans.push_back(temp);
    }
    return ans;
}

int main()
{
    int n;
    cout<<"enter the size of set: ";
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