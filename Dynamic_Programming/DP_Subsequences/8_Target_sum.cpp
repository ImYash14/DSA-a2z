#include<iostream>
#include<bits/stdc++.h>
using namespace std;

int recursion(int index, int target,vector<int>&arr){
    int n = arr.size();

    //base case
    if(index == 0){
        // if(target == 0) return 1;
        // else return 0;
        int count = 0;
        if(target == arr[0]) count++;
        if(target == -arr[0]) count++;
        return count;
    }

    int plus = recursion(index-1,target - arr[index],arr);
    int minus = recursion(index-1,target + arr[index],arr);

    return plus + minus;
}

//same question as "count partitions with given difference"

int main()
{
    int n;
    cin>>n;
    vector<int>arr(n);
    for (int i = 0; i < n; i++)
    {
        cin>>arr[i];
    }
    int target;
    cin>>target;

    cout<<recursion(n-1,target,arr);
    
    return 0;
}