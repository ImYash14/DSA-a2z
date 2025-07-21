#include<iostream>
#include<bits/stdc++.h>
using namespace std;

int brute(vector<int>&arr, int n, int k){
    for (int i = 0; i < n; i++)
    {
        if(arr[i] <= k){
            k++;
        }
        else break;
    }
    return k;
    
}

int optimal(vector<int>&arr, int n, int k){
    int low =0;
    int high = n-1;
    while(low<=high){
        int mid= (low+high)/2;
        int missing = arr[mid] - (mid+1);

        if(missing < k){
            low = mid+1;
        }
        else{
            high = mid-1;
        }
    }
    // return k+high+1;
    return k+low;
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

    int k;
    cout<<"enter the k: ";
    cin>>k;

    // cout<<brute(arr,n,k);
    cout<<optimal(arr,n,k);
    
    return 0;
}