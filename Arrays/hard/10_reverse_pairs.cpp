#include<iostream>
#include<bits/stdc++.h>
using namespace std;

void brute(vector<int>&arr, int n){
    int count =0;
    for (int i = 0; i < n; i++)
    {
        for (int j = i+1; j < n; j++)
        {
            if(arr[i] > 2*arr[j]){
                count++;
            }
        }
        
    }
    cout<<count;
    
}

void merge(vector<int>&arr, int n, int low, int mid , int high){
    int count =0;
    vector<int> temp;
    int left = low;
    int right = mid+1;
    
    while(left <= mid && right <= high){
        if(arr[left] >= arr[right]){
            temp.push_back(arr[right]);
            right++;
        }
        else{
            temp.push_back(arr[left]);
            left++;
        }
    }
    while(left<=mid){
        temp.push_back(arr[left]);
        left++;
    }
    while(right<=high){
        temp.push_back(arr[right]);
        right++;
    }

    for (int i = low; i <= high; i++)
    {
        arr[i] = temp[i-low];
    }

}

int countPairs(vector<int>&arr, int n, int low, int mid , int high){
    int count =0;
    int right = mid+1;
    for (int i = low; i <= mid; i++)
    {
        while(right<=high && arr[i] > 2*arr[right]){
            right++;
        }
        count = count + (right-(mid+1));
    }
    return count;
    
}
int mergesort(vector<int>&arr, int n,int low,int high){
    int cnt =0;
    // int low = 0;
    // int high = n-1;
    if(low>=high) return cnt;
    int mid = (low+high)/2;

    //because every mergesort is calling a merge
    //so we have to combine all the counts
    cnt+= mergesort(arr,n,low,mid);
    cnt+= mergesort(arr,n,mid+1,high);

    //while returning
    cnt+= countPairs(arr,n,low,mid,high);
    merge(arr,n,low,mid,high);
    
    return cnt;
    
}

int optimal(vector<int>&arr, int n){
    int result = mergesort(arr,n,0,n-1);
    return result;
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
    
    // brute(arr,n);
    cout<<optimal(arr,n);

    return 0;
}