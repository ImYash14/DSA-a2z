#include<iostream>
#include<bits/stdc++.h>
using namespace std;

vector<int>brute(vector<int>&arr, int n, int k){
    vector<int>ans;
    for (int i = 0; i <= n-k; i++)//for the array
    {
        int maxi = arr[i];
        for (int j = i; j <= i+k-1; j++)//for the sliding window
        {
            maxi = max(maxi,arr[j]);
        }
        ans.push_back(maxi);
    }
    return ans;
}

vector<int>optimal(vector<int>&arr, int n, int k){
    vector<int>ans;
    deque<int>dq;
    for (int i = 0; i < n; i++)
    {
        if(!dq.empty() && dq.front() <= i-k){//if that index is not in window
            dq.pop_front();
        }
        while(!dq.empty() && arr[dq.back()] <= arr[i]){//following the pge for monotonic stack
            dq.pop_back();
        }
        dq.push_back(i);
        
        if(i>=k-1){
            ans.push_back(arr[dq.front()]); //the ans will always be front after 1st window
        }
    }
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

    int k;
    cout<<"enter the size of sliding window: ";
    cin>>k;

    // vector<int>output = brute(arr,n,k);
    vector<int>output = optimal(arr,n,k);
    for(auto it: output){
        cout<<it<<" ";
    }
    
    return 0;
}