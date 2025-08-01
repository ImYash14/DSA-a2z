#include<iostream>
#include<bits/stdc++.h>
using namespace std;

bool greedy(vector<int>&arr, int n){
    int maxInd =0; //this tells us at max where we can reach after jumping from certain index
    for (int i = 0; i < n; i++)
    {
        if( i > maxInd) return false; //we never reached at that index
        maxInd = max(maxInd, i+arr[i]);
        //optimization
        if(maxInd >= n-1) return true; //we reached the end
    }
    return true;
}

int main()
{
    int n;
    cout<<"enter the size of arr: ";
    cin>>n;
    vector<int>arr(n);
    for (int i = 0; i < n; i++)
    {
        cin>>arr[i];
    }

    cout<<greedy(arr,n);
    
    return 0;
}