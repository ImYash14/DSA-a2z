#include<iostream>
#include<bits/stdc++.h>
using namespace std;

void brute(vector<vector<int>> &arr, int n){
    vector<vector<int>> ans(n,vector<int>(n));

    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            ans[j][n-1-i] = arr[i][j];
        }
        
    }
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            cout<<ans[i][j]<<" ";
        }
        cout<<endl;
        
    }
       
}

void optimal(vector<vector<int>> &arr, int n){
    //step1-> transpose the matrix
    for (int i = 0; i < n-1; i++)
    {
        for (int j = i+1; j < n; j++)
        {
            swap(arr[i][j], arr[j][i]);
        }
        
    }

    //step2-> reverse all the rows
    for (int i = 0; i < n; i++)
    {
        reverse(arr[i].begin(), arr[i].end());
    }
    
    
}
int main()
{
    int n;
    cout<<"enter the size of 2d array: ";
    cin>>n;
    

    vector<vector<int>> arr(n, vector<int>(n)); 

    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            cin>>arr[i][j];
        }
        cout<<endl;
        
    }

    brute(arr,n);

    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            cout<<arr[i][j]<<" ";
        }
        cout<<endl;
        
    }

    return 0;
}