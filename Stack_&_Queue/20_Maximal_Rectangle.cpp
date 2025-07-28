#include<iostream>
#include<bits/stdc++.h>
using namespace std;

int maxRectangleInHist(vector<int>&arr, int n){
    int maxArea =0;
    int nse;
    int pse;
    stack<int>st;
    for (int i = 0; i < n; i++)
    {
        while(!st.empty() && arr[st.top()] > arr[i]){
            int element = arr[st.top()];
            st.pop();
            nse = i;
            if(st.empty()) pse = -1;
            else pse = st.top();

            maxArea = max(maxArea,element*(nse-pse-1));
        }
        st.push(i);
    }
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

int optimal(vector<vector<int>>&arr, int n1, int n2){
    //convert the matrix to prefixsum matrix
    vector<vector<int>>prefixsum(n1,vector<int>(n2,0));
    for (int j = 0; j < n2; j++) //for the columns
    {
        int sum =0;
        for (int i = 0; i < n1; i++) //for the rows
        {
            sum = sum + arr[i][j];
            if(arr[i][j] == 0) sum =0;
            prefixsum[i][j] = sum;
        }
        
    }

    //find the rectangle with max area for each row
    int maxArea =0;
    for (int i = 0; i < n1; i++)
    {
        maxArea = max(maxArea, maxRectangleInHist(prefixsum[i],n2));
    }
    return maxArea;   
}

int main()
{
    int n1;
    cout<<"enter rows:";
    cin>>n1;
    int n2;
    cout<<"enter columns: ";
    cin>>n2;
    vector<vector<int>>arr(n1,vector<int>(n2));
    for (int i = 0; i < n1; i++)
    {
        for (int j = 0; j < n2; j++)
        {
            cin>>arr[i][j];
        }
        
    }

    cout<<optimal(arr,n1,n2);
    
    return 0;
}