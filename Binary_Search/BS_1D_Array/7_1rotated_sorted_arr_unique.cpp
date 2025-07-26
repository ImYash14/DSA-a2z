#include<iostream>
#include<bits/stdc++.h>
using namespace std;

int brute(vector<int> &arr, int n, int target){
    for (int i = 0; i < n; i++)
    {
        if(arr[i] == target){
            return i;
        }
        
    }
    return -1;
    
}

int optimal(vector<int> &arr, int n, int target){
    int low =0;
    int high = n-1;

    while(low<=high){
        int mid = (low+high)/2;
        if(arr[mid] == target) return mid;
        
        //if left half sorted
        else if(arr[low] <= arr[mid]){
            //check if target lies in this half
            if(arr[low]<=target && target<=arr[mid]){
                
                high = mid -1;
            }
            else{
                low = mid+1;
            }
        }

        //if right half sorted (arr[mid]<= arr[high])
        else{
            //check if target lies in this half
            if(arr[mid]<=target && target<=arr[high]){
                
                low = mid+1;
            }
            else{
                high = mid-1;
            }
        }
    }
    return -1;
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

    int target;
    cout<<"enter the target: ";
    cin>>target;

    // cout<<brute(arr,n,target);
    cout<<optimal(arr,n,target);
    
    return 0;
}