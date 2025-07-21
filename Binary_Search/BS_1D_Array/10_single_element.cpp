#include<iostream>
#include<bits/stdc++.h>
using namespace std;

int brute(vector<int> &arr, int n){
    for (int i = 0; i < n; i++)
    {
        if(arr[i] != arr[i-1] && arr[i] != arr[i+1]){
            return arr[i];
        }
    }
    return -1;
    
}

int optimal(vector<int> &arr, int n){
    //edge cases
    if(n==1) return arr[0];
    if(arr[0] != arr[1]) return arr[0];
    if(arr[n-1] != arr[n-2]) return arr[n-1];

    int low = 1;
    int high = n-2;
    while(low<=high){
        int mid = (low+high)/2;
        if(arr[mid] != arr[mid-1] && arr[mid] != arr[mid+1]) return arr[mid];

        //if element is on right half->eleminate the left half
        //(even, odd)-> element is on right half->eleminate the left half
        else if((mid%2 == 1 && arr[mid] == arr[mid-1]) || (mid%2 == 0 && arr[mid] == arr[mid+1])){
            low = mid+1;
        }

        //if element is on left half->eleminate the right half
        //(odd, even)-> element is on left half->eleminate the right half
        else{
            high = mid-1;
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

    // cout<<brute(arr,n);
    cout<<optimal(arr,n);
    
    return 0;
}