#include<iostream>
#include<bits/stdc++.h>
using namespace std;

int optimal(vector<int> &arr, int n){
    int low = 0;
    int high = n-1;
    int ans = INT_MAX;
    while(low <= high){
        int mid = (low+high)/2;
        
        //optimization-> if already sorted
        if(arr[low] < arr[high]){
            ans = min(ans, arr[low]);
            break;
        }
        //trim down the array
        if(arr[low] == arr[mid] && arr[mid] == arr[high]){
            ans = min(ans, arr[mid]);
            low++;
            high--;
            continue;
        }


        //if left half sorted
        if(arr[low] <= arr[mid]){
            ans = min(ans, arr[low]);
            low = mid+1;
        }

        //if right half sorted
        else{
            ans = min(ans, arr[mid]);
            high = mid-1;
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

    // cout<<brute(arr,n);
    cout<<optimal(arr,n);
    
    return 0;
}