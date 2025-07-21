#include<iostream>
#include<bits/stdc++.h>
using namespace std;

int lowerBound(vector<int>&arr, int n, int num){
    int low = 0;
    int high = n-1;
    int ans = -1;
    while(low <= high){
        int mid = (low+high)/2;
        if(arr[mid] >= num){
            ans = mid;
            high = mid-1;
        }
        else{
            low = mid+1;
        }
    }
    return ans;
}

int upperBound(vector<int>&arr, int n, int num){
    int low = 0;
    int high = n-1;
    int ans = -1;
    while(low <= high){
        int mid = (low+high)/2;
        if(arr[mid] > num){
            ans = mid;
            high = mid-1;
        }
        else{
            low = mid+1;
        }
    }
    return ans;
}

int optimal(vector<int> &arr, int n, int num){
    int first = lowerBound(arr,n,num);
    if(first == -1) return 0;
    int last = upperBound(arr,n,num) - 1;
    int result = last - first +1;

    return result ;
}
int main()
{
    int n;
    cout<<"enter the size of array: ";
    cin>>n;
    vector<int> arr(n);
    for (int i = 0; i < n; i++)
    {
        cin>>arr[i];
    }

    int num;
    cout<<"enter the number: ";
    cin>>num;

    // brute(arr,n,num);
    // pair<int,int> result = optimal(arr, n, num);
    // cout<<result.first<<" "<<result.second;
    cout<<optimal(arr,n,num);
    
    return 0;
}