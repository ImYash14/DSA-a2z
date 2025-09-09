#include<iostream>
#include<bits/stdc++.h>
using namespace std;

bool spaceopt(vector<int>&arr, int target){
    int n = arr.size();

    vector<bool>prev(target+1,0);
    prev[0] = true;

    //for loop for states
    for (int index = 1; index < n; index++)
    {
        vector<bool>curr(target+1,0);
        curr[0] = true;
        for (int k = 1; k <= target; k++)
        {
            bool nottake = prev[k];
            bool take = false;
            if(target >= arr[index]){
                take = prev[k-arr[index]];
            }
            curr[k] = (take | nottake);
        }
        prev = curr;
    }
    return prev[target];   
}

bool partitionSubsetSum(vector<int>&arr){
    int n = arr.size();

    int sum = accumulate(arr.begin(),arr.end(),0);
    if(sum%2 == 1) return false;

    return spaceopt(arr,sum/2);
}

int main()
{
    int n;
    cin>>n;
    vector<int>arr(n);
    for (int i = 0; i < n; i++)
    {
        cin>>arr[i];
    }
    
    cout<<partitionSubsetSum(arr);
    
    return 0;
}