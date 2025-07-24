#include<iostream>
#include<bits/stdc++.h>
using namespace std;

int better(vector<int>&arr, int n){
    int ans =0;
    for (int bitIndex = 0; bitIndex < 32; bitIndex++) //for the bits
    {
        int count =0;
        for (int i = 0; i < n; i++) //for the arr elements
        {
            if((arr[i] & (1<<bitIndex))){ //check for set bits
                count++; //count the no. of set bits for a given bitInd
            }
        }
        if(count%3 == 1){
            ans = (ans | (1<<bitIndex)); //set the ans bit
        }
    }
    return ans;
}

int optimal(vector<int>&arr, int n){
    sort(arr.begin(),arr.end());
    for (int i = 1; i < n; i+=3)
    {
        if(arr[i] != arr[i-1]) return arr[i-1];
    }
    return arr[n-1];
}

int mostOptimal(vector<int>&arr, int n){
    int ones =0;
    int twos = 0;
    //bucket method
    //arr[i] will goto ones, if not in twos
    //arr[i] will goto twos, if it is in ones
    //arr[i] will goto threes, if it is in twos

    for (int i = 0; i < n; i++)
    {
        //add to ones, if no one in twos
        ones = ((ones^arr[i]) & (~(twos)));

        //add to twos, if no one in ones
        twos = ((twos^arr[i]) & (~(ones)));
    }
    return ones;
}

int main()
{
    int n;
    cout<<"enter the size of array: ";
    cin>>n;
    vector<int>arr(n);
    for (int i = 0; i < n; i++)
    {
        cin>>arr[i];
    }
    
    // cout<<better(arr,n);
    // cout<<optimal(arr,n);
    cout<<mostOptimal(arr,n);
    return 0;
}