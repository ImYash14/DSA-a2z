#include<iostream>
#include<bits/stdc++.h>
using namespace std;

int lowerBound(int target,vector<int>&arr){
    int n = arr.size();

    int low =0;
    int high = n-1;
    while(low<=high){
        int mid = (low+high)>>1;

        if(arr[mid] >= target){
            high = mid-1;
        }
        else low = mid+1;
    }
    return low;
}

int LIS(vector<int>&arr){
    int n = arr.size();

    vector<int>temp;
    temp.push_back(arr[0]);
    for (int i = 1; i < n; i++)
    {
        if(arr[i] > temp.back()){
            temp.push_back(arr[i]);
        }
        else{
            int index = lowerBound(arr[i],arr);
            temp[index] = arr[i]; //replace the element
        }
    }
    return temp.size();
}

int main()
{
    int n;
    cin>>n;
    vector<int>arr(n);
    for (int i = 0; i < n; i++)
    {
        cin>>arr[i];
    }

    cout<<LIS(arr);
    
    
    return 0;
}