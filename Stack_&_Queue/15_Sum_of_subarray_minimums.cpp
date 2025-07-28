#include<iostream>
#include<bits/stdc++.h>
using namespace std;

int brute(vector<int>&arr, int n){
    int sum =0;
    for (int i = 0; i < n; i++)
    {
        int mini = arr[i];
        for (int j = i; j < n; j++)
        {
            mini = min(mini,arr[j]);
            sum = sum + mini;//because we need all the minimum sums
        }
        
    }
    return sum;
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

int optimal(vector<int>&arr, int n){
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