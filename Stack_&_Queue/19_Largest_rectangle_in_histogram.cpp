#include<iostream>
#include<bits/stdc++.h>
using namespace std;

vector<int> findNSE(vector<int>&arr, int n){//return n if not found
    vector<int>ans(n);
    stack<pair<int,int>>st;
    for (int i = n-1; i>=0; i--)
    {
        while(!st.empty() && st.top().first >= arr[i]){
            st.pop();
        }
        if(st.empty()) ans[i] = n;
        else ans[i] = st.top().second;
        st.push({arr[i],i});
    }
    return ans;
}

vector<int> findPSE(vector<int>&arr, int n){//return -1 if not found
    vector<int>ans(n);
    stack<pair<int,int>>st;
    for (int i = 0; i < n; i++)
    {
        while(!st.empty() && st.top().first >= arr[i]){
            st.pop();
        }
        if(st.empty()) ans[i] =-1;
        else ans[i] = st.top().second;
        st.push({arr[i],i});
    }
    return ans;
}

int brute(vector<int>&arr, int n){
    vector<int>nse = findNSE(arr,n);
    vector<int>pse = findPSE(arr,n);
    int maxArea = 0;
    for (int i = 0; i < n; i++)
    {
        maxArea = max(maxArea, arr[i]*(nse[i]-pse[i]-1));
    }
    return maxArea;
}

int optimal(vector<int>&arr, int n){
    int nse, pse;
    stack<int>st;
    int maxArea =0;
    for (int i = 0; i < n; i++)
    {
        while(!st.empty() && arr[st.top()] > arr[i]){//following pse
            int element = arr[st.top()]; //the element that is to be touched
            st.pop();
            nse = i; 
            if(st.empty()) pse =-1;
            else pse = st.top();

            maxArea = max(maxArea,element*(nse-pse-1));
        }
        st.push(i);
    }
    //if elements remianing in stack
    while(!st.empty()){
        int element = arr[st.top()];
        st.pop();
        nse = n;
        if(st.empty()) pse = -1;
        else pse = st.top();

        maxArea = max(maxArea,element*(nse-pse-1));
    }
    return maxArea;
}

int main()
{
    int n;
    cout<<"enter the no. of bars in histogram: ";
    cin>>n;
    cout<<"enter the heights of each bar: ";
    vector<int>arr(n);
    for (int i = 0; i < n; i++)
    {
        cin>>arr[i];
    }

    // cout<<brute(arr,n);
    cout<<optimal(arr,n);
    
    return 0;
}