#include<iostream>
#include<bits/stdc++.h>
using namespace std;

int brute(vector<int> &arr, int n){
    for (int i = 0; i < n; i++)
    {
        if((i==0 || arr[i] > arr[i-1]) && (i== n-1 || arr[i] > arr[i+1])){
            return arr[i];
        }
    }
    return 0;
    
}

int optimal(vector<int> &arr, int n){
    //edge cases
    if(n==1) return arr[0];
    if(arr[0] > arr[1]) return arr[0];
    if(arr[n-1] > arr[n-2]) return arr[n-1];

    int low = 1;
    int high = n-2;
    while(low <= high){
        int mid = (low+high)/2;
        if(arr[mid] > arr[mid-1] && arr[mid] > arr[mid+1]) return arr[mid];

        //if mid is on increasing slope-> mid is on left half
        //it means the peak is on right half->eliminate left half
        else if(arr[mid] < arr[mid+1]){
            low = mid+1;
        }

        //if mid is on decreasing slope-> mid is on right half
        //it means the peak is on left half->eliminate right half
        else if(arr[mid] > arr[mid+1]){
            high = mid-1;
        }

        //for multiple peaks, there will be multiple dips
        //dips will have peaks on both side-> causes infinite loop
        //so we can eliminate any of the halves
        else{
            low = mid+1; //or high = mid-1;
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