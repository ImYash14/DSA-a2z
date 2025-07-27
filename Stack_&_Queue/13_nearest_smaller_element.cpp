#include<iostream>
#include<bits/stdc++.h>
using namespace std;

vector<int> brute(vector<int>&arr, int n){
    vector<int>nse(n,-1);
    for (int i = 0; i < n; i++)
    {
        for (int j = i-1; j >=0; j--)
        {
            if(arr[j] < arr[i]){
                nse[i] = arr[j];
                break;
            }
        }
        
    }
    return nse;
}

vector<int> optimal(vector<int>&arr, int n){
    vector<int>nse(n);
    stack<int>st;
    for (int i = 0; i < n; i++)
    {
        while(!st.empty() && st.top() >= arr[i]){
            st.pop();
        }

        if(st.empty()) nse[i] = -1;
        else nse[i] = st.top();

        st.push(arr[i]);
    }
    return nse;
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
    
    // vector<int>output = brute(arr,n);
    vector<int>output = optimal(arr,n);
    for(auto it : output){
        cout<<it<<" ";
    }
    return 0;
}