#include<iostream>
#include<bits/stdc++.h>
using namespace std;

bool brute(vector<vector<int>>&arr, int n1, int n2, int target){
    for (int i = 0; i < n1; i++)
    {
        for (int j = 0; j < n2; j++)
        {
            if(arr[i][j] == target){
                return true;
            }
        }
        
    }
    return false;   
}

bool binarySearch(vector<int>&arr, int n, int target){
    int low =0;
    int high =n-1;
    while(low<=high){
        int mid =(low+high)/2;
        if(arr[mid] == target) return true;
        else if(arr[mid] < target){
            low = mid+1;
        }
        else{
            high = mid-1;
        }
    }
    return false;
}

bool better(vector<vector<int>>&arr, int n1, int n2, int target){
    for (int i = 0; i < n1; i++)
    {
        if(arr[i][0] <= target && target<= arr[i][n2-1]){
            return binarySearch(arr[i],n2,target);
        }
    }
    return false;
}

bool optimal(vector<vector<int>>&arr, int n1, int n2, int target){
    int low =0;
    int high = (n1*n2)-1;
    while(low<=high){
        int mid =(low+high)/2;
        int row = mid/n2;
        int col = mid%n2;
        if(arr[row][col] == target) return true;
        else if(arr[row][col] < target){
            low = mid+1;
        }
        else{
            high = mid-1;
        }
    }
    return false;
}
int main()
{
    int n1;
    cout<<"enter the no. of rows: ";
    cin>>n1;
    int n2;
    cout<<"enter the no. of columns: ";
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
    
    cout<<brute(arr,n1,n2,target);
    // cout<<better(arr,n1,n2,target);
    // cout<<optimal(arr,n1,n2,target);
    return 0;
}