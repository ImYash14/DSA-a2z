#include<iostream>
#include<bits/stdc++.h>
using namespace std;

int brute(vector<int>&arr, vector<int>&dep, int n){
    int maxcount = INT_MIN;
    for (int i = 0; i < n; i++)
    {
        int count =1;
        for (int j = i+1; j < n; j++)
        {
            // if((arr[j]<arr[i] && dep[j]>dep[i])||(arr[j]<arr[i] && dep[j]<dep[i])||(arr[j]>arr[i] && dep[j]>dep[i])||(arr[j]>arr[i] && dep[j]<dep[i])){
            //     count++;
            // }
            if (j != i && arr[j] <= dep[i] && dep[j] >= arr[i]) {
                count++;
            }
        }
        maxcount = max(maxcount,count);
        
    }
    return maxcount;
}

int optimal(vector<int>&arr, vector<int>&dep, int n){
    int maxcount = INT_MIN;
    int count =0;
    int l=0;
    int r=0;
    sort(arr.begin(),arr.end());
    sort(dep.begin(),dep.end());
    while(l<n){//bc arrival will finish out first
        if(arr[l] <= dep[r]){
            count++;
            l++;
        }
        else{
            count--;
            r++;
        }
        maxcount = max(maxcount,count);
    }
    return maxcount;
}

int main()
{
    int n;
    cout<<"enter the no. of arrivals or departures: ";
    cin>>n;
    vector<int>arr(n);
    for (int i = 0; i < n; i++)
    {
        cin>>arr[i];
    }
    vector<int>dep(n);
    for (int i = 0; i < n; i++)
    {
        cin>>dep[i];
    }
    
    cout<<brute(arr,dep,n);
    // cout<<optimal(arr,dep,n);
    
    return 0;
}