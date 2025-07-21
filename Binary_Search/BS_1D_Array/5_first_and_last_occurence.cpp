#include<iostream>
#include<bits/stdc++.h>
using namespace std;

void brute(vector<int> &arr, int n, int num){
    int first = -1;
    int last =-1;
    for (int i = 0; i < n; i++)
    {
        if(arr[i] == num){
            if(first == -1){
                first = i;
            }
            last =i;
        }
    }
    cout<<first<<" "<<last;
    
}

int lowerBound(vector<int>&arr, int n, int num){
    int low = 0;
    int high = n-1;
    int ans = -1;
    while(low <= high){
        int mid = (low+high)/2;
        if(arr[mid] >= num){
            ans = mid;
            high = mid-1;
        }
        else{
            low = mid+1;
        }
    }
    return ans;
}

int upperBound(vector<int>&arr, int n, int num){
    int low = 0;
    int high = n-1;
    
    while(low <= high){
        int mid = (low+high)/2;
        if(arr[mid] > num){
            
            high = mid-1;
        }
        else{
            low = mid+1;
        }
    }
    return low;
}

pair<int,int> optimal(vector<int> &arr, int n, int num){
    int first = lowerBound(arr,n,num);
    if(first == -1 || arr[first] != num) return {-1,-1};
    int last = upperBound(arr,n,num) - 1;

    return {first, last};
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

    int num;
    cout<<"enter the number: ";
    cin>>num;

    // brute(arr,n,num);
    pair<int,int> result = optimal(arr, n, num);
    cout<<result.first<<" "<<result.second;
    
    return 0;
}