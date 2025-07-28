#include<iostream>
#include<bits/stdc++.h>
using namespace std;

vector<int> findNGE(vector<int>&arr, int n){//return n if not found
    vector<int>ans(n);
    stack<int>st;
    for (int i = n-1; i>=0; i--)
    {
        while(!st.empty() && arr[st.top()] <= arr[i]){
            st.pop();
        }
        if(st.empty()) ans[i] = n;
        else ans[i] = st.top();
        st.push(i);
    }
    return ans;
}

vector<int> findPGEE(vector<int>&arr, int n){//return -1 if not found
    vector<int>ans(n);
    stack<int>st;
    for (int i = 0; i < n; i++)
    {
        while(!st.empty() && arr[st.top()] < arr[i]){//rem,not to pop equal ele
            st.pop();
        }
        if(st.empty()) ans[i] = -1;
        else ans[i] = st.top();
        st.push(i);
    }
    return ans;
}

int optimal(vector<int>&arr, int n){
    vector<int>nge = findNGE(arr,n); //returns arr of indices of next greater ele
    vector<int>pgee = findPGEE(arr,n); //returns arr of indices of prev greater or equal ele 
    int total=0;
    for (int i = 0; i < n; i++)
    {
        int left = i - pgee[i];
        int right = nge[i] - i;
        total += (left*right*arr[i]);
    }
    return total;
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

    cout<<optimal(arr,n);
    return 0;
}