#include<iostream>
#include<bits/stdc++.h>
using namespace std;

int brute(vector<int>&arr, int n){
    //find prefixMax and suffixMax for the array
    vector<int>prefixMax(n);
    prefixMax[0] = arr[0];
    for (int i = 1; i < n; i++)
    {
        prefixMax[i] = max(prefixMax[i-1],arr[i]);
    }
    vector<int>suffixMax(n);
    suffixMax[n-1] = arr[n-1];
    for (int i = n-2; i >=0; i--)
    {
        suffixMax[i] = max(suffixMax[i+1],arr[i]);
    }
    
    //calculate total water logging in all buildings
    int total =0;
    for (int i = 0; i < n; i++)
    {
        int leftMax = prefixMax[i];
        int rightMax = suffixMax[i];
        if(arr[i] < leftMax && arr[i]<rightMax){ //for water logging to happen
            total += min(leftMax,rightMax)-arr[i];
        }
    }
    return total;
}

int optimal(vector<int>&arr, int n){
    int leftMax =0;
    int rightMax =0;
    int total =0;
    int l =0;
    int r = n-1;

    while(l<r){
        if(arr[l] <= arr[r]){ //if left building is smaller than right
            if(leftMax > arr[l]){ 
                //if there is some building in left that is larger than current,
                //and we know that on the right, there is building that is large or equal to previous left max
                //so we have found a dip so water logging will happen
                total += leftMax-arr[l];
            }
            else{
                //update with current largest building
                leftMax = arr[l];
            }
            l = l+1; //move left because left is currently smaller
        }
        else{//if(arr[l] > arr[r])//left building is larger than smaller
            if(rightMax > arr[r]){
                total += rightMax-arr[r];
            }
            else{
                rightMax = arr[r];
            }
            r = r-1;
        }
    }
    return total;
}

int main()
{
    int n;
    cout<<"enter the no. of buildings: ";
    cin>>n;
    cout<<"enter the building heights: ";
    vector<int>arr(n);
    for (int i = 0; i < n; i++)
    {
        cin>>arr[i];
    }

    // cout<<brute(arr,n);
    cout<<optimal(arr,n);
    
    return 0;
}