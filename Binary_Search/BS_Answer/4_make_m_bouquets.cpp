#include<iostream>
#include<bits/stdc++.h>
using namespace std;

int minArray(vector<int>&arr, int n){
    int ans = arr[0];
    for (int i = 0; i < n; i++)
    {
        if(arr[i] < ans){
            ans = arr[i];
        }
    }
    return ans;   
}

int maxArray(vector<int>&arr, int n){
    int ans = arr[0];
    for (int i = 0; i < n; i++)
    {
        if(arr[i] > ans){
            ans = arr[i];
        }
    }
    return ans;   
}

bool fun(vector<int>&arr, int n, int day, int m, int k){
    int count =0;
    int numofBq =0;
    for (int i = 0; i < n; i++)
    {
        if(arr[i] <= day) count++;
        else{
            numofBq += (count/k);
            count =0;
        }
    }
    numofBq += (count/k);
    
    if(numofBq >= m) return true;
    else return false;
    
}

int brute(vector<int> &arr, int n, int m, int k){
    if(m*k > n) return -1;
    for (int i = minArray(arr,n); i <= maxArray(arr,n); i++)
    {
        if(fun(arr,n,i,m,k) == true){
            return i;
        }
    }
    return -1;
    
}

int optimal(vector<int>&arr, int n, int m, int k){
    int low = minArray(arr,n);
    int high = maxArray(arr,n);
    if(m*k > n) return -1;
    while(low<=high){
        int mid = (low+high)/2;
        if(fun(arr,n,mid,m,k) == true){
            high = mid-1;
        }
        else{
            low = mid+1;
        }
    }
    return low;
}
int main()
{
    int n;
    cout<<"enter the size of array for bloomdays: ";
    cin>>n;
    vector<int> arr(n);
    for (int i = 0; i < n; i++)
    {
        cin>>arr[i];
    }

    int m;
    cout<<"enter the no. of bouquets: ";
    cin>>m;

    int k;
    cout<<"enter adjacent flowers required: ";
    cin>>k;

    // cout<<brute(arr,n,m,k);
    cout<<optimal(arr,n,m,k);
    
    return 0;
}