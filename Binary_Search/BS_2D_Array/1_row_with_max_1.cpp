#include<iostream>
#include<bits/stdc++.h>
using namespace std;

int brute(vector<vector<int>>&matrix, int n1, int n2){
    int index =-1;
    int maxCount =0;
    for (int i = 0; i < n1; i++)
    {
        int countRows =0;
        for (int j = 0; j < n2; j++)
        {
            countRows += matrix[i][j];
        }
        if(countRows > maxCount){
            maxCount = countRows;
            index =i;
        }        
    }
    return index;
}

int lowerBound(vector<int>&arr, int n, int target){
    int low=0;
    int high =n-1;
    int ans =-1;
    while(low<=high){
        int mid = (low+high)/2;
        if(arr[mid] >= target){
            ans = mid;
            high = mid-1;
        }
        else low = mid+1;
    }
    return ans;
}

int optimal(vector<vector<int>>&matrix, int n1, int n2){
    int index =-1;
    int maxCount =0;
    for (int i = 0; i < n1; i++)
    {
        int lb = lowerBound(matrix[i],n2,1);
        if(lb != -1){ //for rows containing all 0s
            int countOnes =n2 - lb;
            if(countOnes > maxCount){
                maxCount = countOnes;
                index =i;
            }
        }
    }
    return index;
}

int main()
{
    int n1;
    cout<<"enter the no. of rows: ";
    cin>>n1;
    int n2;
    cout<<"enter the no. of columns: ";
    cin>>n2;
    vector<vector<int>> matrix(n1,vector<int>(n2));
    for (int i = 0; i < n1; i++)
    {
        for (int j = 0; j < n2; j++)
        {
            cin>>matrix[i][j];
        }
        cout<<endl;
    }
    
    // cout<<brute(matrix,n1,n2);
    cout<<optimal(matrix,n1,n2);
    return 0;
}