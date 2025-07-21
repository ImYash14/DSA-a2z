#include<iostream>
#include<bits/stdc++.h>
using namespace std;

vector<int> brute(vector<vector<int>>&arr, int n1, int n2, int target){
    for (int i = 0; i < n1; i++)
    {
        for (int j = 0; j < n2; j++)
        {
            if(arr[i][j] == target){
                return {i,j};
            }
        }
        
    }
    return {-1,-1};
}
int binarySearch(vector<int>&arr, int n, int target){
    int low =0;
    int high = n-1;
    while(low<=high){
        int mid = (low+high)/2;
        if(arr[mid] == target) return mid;
        else if(arr[mid] < target){
            low = mid+1;
        }
        else{
            high = mid-1;
        }
    }
    return -1;
}

vector<int> better(vector<vector<int>>&arr, int n1, int n2, int target){
    for (int i = 0; i < n1; i++)
    {
        int index = binarySearch(arr[i],n2,target);
        if(index != -1){
            return {i,index};
        }
    }
    return {-1,-1};
}

vector<int> optimal(vector<vector<int>>&arr, int n1, int n2, int target){
    int row =0;
    int col = n2-1;
    while(row<n1 && col>=0){
        if(arr[row][col] == target) return {row,col};
        else if(arr[row][col] < target){
            row++;
        }
        else{
            col--;
        }
    }
    return {-1,-1};
}
int main()
{
    int n1;
    cout<<"enter the no. of rows: ";
    cin>>n1;
    int n2;
    cout<<"enter the no. of col: ";
    cin>>n2;
    vector<vector<int>> arr(n1,vector<int>(n2));
    for (int i = 0; i < n1; i++)
    {
        for (int j = 0; j < n2; j++)
        {
            cin>>arr[i][j];
        }
        
    }
    int target;
    cout<<"enter the target: ";
    cin>>target;

    // vector<int> ans = brute(arr,n1,n2,target);
    // vector<int> ans = better(arr,n1,n2,target);
    vector<int> ans = optimal(arr,n1,n2,target);
    for(auto it: ans){
        cout<<it<<" ";
    }
    
    return 0;
}