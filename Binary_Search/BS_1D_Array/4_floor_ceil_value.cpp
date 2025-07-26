#include<iostream>
#include<bits/stdc++.h>
using namespace std;

int floor(vector<int>&arr, int n, int num){
    int low =0;
    int high = n-1;
    int ans = -1;
    while(low <= high){
        int mid = (low+high)/2;
        if(arr[mid] <= num){
            ans = arr[mid];
            low = mid+1;
        }
        else{
            high = mid -1;
        }
    }
    return ans; //we can also return high if index is asked
}

int ceil(vector<int>&arr, int n, int num){
    int low =0;
    int high = n-1;
    int ans = -1;
    while(low <= high){
        int mid = (low+high)/2;
        if(arr[mid] >= num){
            ans = arr[mid];
            high = mid-1;
        }
        else{
            low = mid+1;
        }
    }
    return ans;
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

    cout<<floor(arr,n,num)<<"and"<<ceil(arr,n,num);
    
    return 0;
}