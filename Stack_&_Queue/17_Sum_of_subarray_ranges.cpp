#include<iostream>
#include<bits/stdc++.h>
using namespace std;

int brute(vector<int>&arr, int n){
    int rangeSum =0;
    for (int i = 0; i < n; i++)
    {
        int largest = arr[i];
        int smallest = arr[i];
        for (int j = i+1; j < n; j++) //because starting subarrays are not contributing
        {
            largest = max(largest,arr[j]);
            smallest = min(smallest,arr[j]);
            rangeSum += (largest-smallest);
        }
        
    }
    return rangeSum;
}

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

vector<int> findPSEE(vector<int>&arr, int n){//return -1 if not found
    vector<int>ans(n);
    stack<pair<int,int>>st;
    for (int i = 0; i < n; i++)
    {
        while(!st.empty() && st.top().first > arr[i]){//rem, not to pop equal ele
            st.pop();
        }
        if(st.empty()) ans[i] =-1;
        else ans[i] = st.top().second;
        st.push({arr[i],i});
    }
    return ans;
}

int subMin(vector<int>&arr, int n){
    vector<int>nse = findNSE(arr,n); //it will return arr of indexes of next smaller ele
    vector<int>psee = findPSEE(arr,n); //it will return arr of indexes of prev smaller or equal ele
    int sum =0;
    for (int i = 0; i < n; i++)
    {
        int left = i-psee[i];
        int right = nse[i]-i;
        sum += (left*right*arr[i]); //total contribution of that element
    }
    return sum;
}

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

int subMax(vector<int>&arr, int n){
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

int optimal(vector<int>&arr, int n){
    return subMax(arr,n) - subMin(arr,n);
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

    // cout<<brute(arr,n);
    cout<<optimal(arr,n);
    return 0;
}