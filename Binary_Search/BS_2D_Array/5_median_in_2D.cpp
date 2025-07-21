#include<iostream>
#include<bits/stdc++.h>
using namespace std;

int brute(vector<vector<int>>&arr, int n1, int n2){
    //step1->put all elements in 1D array
    vector<int> oneD;
    for (int i = 0; i < n1; i++)
    {
        for (int j = 0; j < n2; j++)
        {
            oneD.push_back(arr[i][j]);
        }
        
    }

    //step2->sort the 1D array
    sort(oneD.begin(),oneD.end());

    //step3->return n1*n2/2
    return oneD[(n1*n2)/2];    
}

int minElement(vector<vector<int>>&arr, int n1, int n2, int col){
    int mini = INT_MAX;
    for (int i = 0; i < n1; i++)
    {
        if(arr[i][col] <= mini){
            mini = arr[i][col];
        }
    }
    return mini;
}

int maxElement(vector<vector<int>>&arr, int n1, int n2, int col){
    int max = INT_MIN;
    for (int i = 0; i < n1; i++)
    {
        if(arr[i][col] >= max){
            max = arr[i][col];
        }
    }
    return max;
}

int upperBound(vector<int>&arr, int n, int target){
    int low =0;
    int high = n-1;
    int ans =-1;
    while(low<=high){
        int mid = (low+high)/2;
        if(arr[mid] > target){
            ans = mid;
            high = mid-1;
        }
        else{
            low = mid+1;
        }
    }
    return low;
}

int fun(vector<vector<int>>&arr,int n1,int n2, int num){
    int count =0;
    for (int i = 0; i < n1; i++)
    {
        count = count + upperBound(arr[i],n2,num);
    }
    return count;
}

int optimal(vector<vector<int>>&arr, int n1, int n2){
    int low = minElement(arr,n1,n2,0);
    int high = maxElement(arr,n1,n2, n2-1);
    while(low<=high){
        int mid = (low+high)/2;
        int lesserEqual = fun(arr,n1,n2,mid);
        int req = (n1*n2)/2;
        if(lesserEqual <= req){
            low = mid+1;
        }
        else{
            high = mid-1;
        }
    }
    return low;
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

    // cout<<brute(arr, n1,n2);
    cout<<optimal(arr, n1,n2);
    
    return 0;
}