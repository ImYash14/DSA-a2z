#include<iostream>
#include<bits/stdc++.h>
using namespace std;

int better(vector<vector<int>>&arr, int n1, int n2){
    int maxi = INT_MIN;
    for (int i = 0; i < n1; i++)
    {
        for (int j = 0; j < n2; j++)
        {
            if(arr[i][j] > maxi){
                maxi = arr[i][j];
            }
        }
        
    }
    return maxi;   
}

int maxElement(vector<vector<int>>&arr, int n1, int n2, int col){
    int maxi = INT_MIN;
    int index = -1;
    for (int i = 0; i < n1; i++)
    {
        if(arr[i][col] > maxi){
            maxi = arr[i][col];
            index =i;
        }
    }
    return index;
}
int optimal(vector<vector<int>>&arr, int n1, int n2){
    int low =0;
    int high = n2-1;
    while(low<=high){
        int mid = (low+high)/2;
        int row = maxElement(arr,n1,n2,mid);

        //for out of bound elements
        int left =-1;
        int right =-1;
        //for inside of bound elements
        if(mid-1 >=0) left = arr[row][mid-1];
        if(mid+1 <n2) right= arr[row][mid+1]; 

        if(arr[row][mid] >left && arr[row][mid] >right){
            return arr[row][mid];
        }
        else if(arr[row][mid] < left){
            //the max was discarded bc of someone on left
            //so eliminate right half
            high = mid -1; 
        }
        else{
            //the max was discarded bc of someone on right
            //so eliminate left half
            low = mid+1;
        }
    }
    return -1;
}
int main()
{
    int n1;
    cout<<"enter the rows: ";
    cin>>n1;
    int n2;
    cout<<"enter the col: ";
    cin>>n2;
    vector<vector<int>> arr(n1,vector<int>(n2));
    for (int i = 0; i < n1; i++)
    {
        for (int j = 0; j < n2; j++)
        {
            cin>>arr[i][j];
        }
        
    }

    // cout<<better(arr,n1,n2);
    cout<<optimal(arr,n1,n2);
    
    return 0;
}