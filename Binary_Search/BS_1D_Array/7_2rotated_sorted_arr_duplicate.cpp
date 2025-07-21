#include<iostream>
#include<bits/stdc++.h>
using namespace std;

bool optimal(vector<int> &arr, int n, int target){
    int low =0;
    int high = n-1;
    int ans = false;
    while(low<=high){
        int mid = (low+high)/2;
        if(arr[mid] == target) return true;
        
        //trim down the array
        if(arr[low] == arr[mid] == arr[high]){
        
            low++;
            high--;
            continue;
        }
        
        //if left sorted
        else if(arr[low] <= arr[mid]){
            //check if target lies in this half
            if(arr[low]<=target && target<=arr[mid]){
                ans = true;
                high = mid -1;
            }
            else{
                low = mid+1;
            }
        }

        //if right sorted
        else{
            //check if target lies in this half
            if(arr[mid]<=target && target<=arr[high]){
                ans = true;
                low = mid+1;
            }
            else{
                high = mid-1;
            }
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

    int target;
    cout<<"enter the target: ";
    cin>>target;

    // cout<<brute(arr,n,target);
    cout<<optimal(arr,n,target);
    
    return 0;
}