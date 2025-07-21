#include<iostream>
#include<bits/stdc++.h>
using namespace std;

int optimal(vector<int> &arr, int n){
    int low = 0;
    int high = n-1;
    int ans = INT_MAX;
    int index = -1;
    while(low <= high){
        int mid = (low+high)/2;

        //optimization-> if already sorted
        if(arr[low] <= arr[high]){
            if(arr[low] < ans){
                index = low;
                ans = arr[low];
            }
            break;
        }

        //if left half sorted
        if(arr[low] <= arr[mid]){
            if(arr[low] < ans){
                index = low;
                ans = arr[low];
            }
            low = mid+1;
        }

        //if right half sorted
        else{
            if(arr[mid] < ans){
                index = mid;
                ans = arr[mid];
            }
            high = mid-1;
        }
    }
    return index;
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

    // cout<<brute(arr,n);
    cout<<optimal(arr,n);
    
    return 0;
}