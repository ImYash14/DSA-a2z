#include<iostream>
#include<bits/stdc++.h>
using namespace std;

void brute(vector<int> &arr, int n){
    for (int i = 0; i < n; i++)
    {
        int leader = true;
        for (int j = i+1; j < n; j++)
        {
            if(arr[i] < arr[j]){
                leader = false;
                break;
            }
        }
        if(leader == true){
            cout<<arr[i]<<" ";
        }
        
    }
    
}

void optimal(vector<int> &arr, int n){
    int maxi = INT_MIN;
    vector<int> ans;
    for (int i = n-1; i >=0; i--)
    {
        if(arr[i] > maxi){
            maxi = arr[i];
            ans.push_back(maxi);
        }
    }

    for (int i = 0; i < ans.size(); i++)
    {
        cout<<ans[i]<<" ";
    }
       
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

    optimal(arr,n);    
    return 0;
}