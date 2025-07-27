#include<iostream>
#include<bits/stdc++.h>
using namespace std;

vector<int> brute(vector<int>&arr, int n){
    vector<int>nge(n,-1);
    for (int i = 0; i < n; i++)
    {
        for (int j = i+1; j < n; j++)
        {
            if(arr[j] > arr[i]){
                nge[i] = arr[j];
                break;
            }
        }
        
    }
    return nge;
}

vector<int>optimal(vector<int>&arr, int n){
    vector<int>nge(n);
    stack<int>st;
    for (int i = n-1; i >= 0; i--)
    {
        //pop the ele in stack till the arr[i] has a nge
        while(!st.empty() && st.top() <= arr[i]){
            st.pop();
        }

        //if we poped all ele from stack while searching the nge for arr[i]
        if(st.empty()) nge[i] = -1;
        else{
            //if arr[i] < st.top()
            nge[i] = st.top();
        }
        st.push(arr[i]); //push the arr[i] in stack;
    }
    return nge;
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