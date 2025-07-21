#include<iostream>
#include<bits/stdc++.h>
using namespace std;

int brute(vector<int>&arr1,vector<int>&arr2, int n1, int n2,int k){
    int n = n1+n2;
    vector<int>temp(n);
    int low =0;
    int high =0;
    while(low<n1 && high<n2){
        if(arr1[low] < arr2[high]){
             temp.push_back(arr1[low]);
             low++;
        }
        else{ 
            temp.push_back(arr2[high]);
            high++;
        }
    }
    while(low<n1){
        temp.push_back(arr1[low]);
        low++;
    }
    while(high<n2){
        temp.push_back(arr2[high]);
        high++;
    }
    return temp[k-1];
    
}

int optimal(vector<int>&arr1,vector<int>&arr2, int n1, int n2, int k){
    if(n1>n2) return optimal(arr2,arr1,n2,n1,k);
    int n = n1+n2;
    int low = max(0,k-n2);
    int high = min(k,n);
    int left =k;
    while(low<=high){
        int mid1 = (low+high)/2;
        int mid2 = left - mid1;
        int l1 = INT_MIN;
        int l2 = INT_MIN;
        int r1 = INT_MAX;
        int r2 = INT_MAX;
        if(mid1<n1) r1 = arr1[mid1];
        if(mid2<n2) r2 = arr2[mid2];
        if(mid1-1>=0) l1 = arr1[mid1-1];
        if(mid2-1>=0) l2 = arr2[mid2-1];

        if(l1<= r2 && l2<=r1) return max(l1,l2);
        else if(l1>r2){
            high =mid1-1;
        }
        else{
            low = mid1+1;
        }
    }
    return 0;
}
int main()
{
    int n1;
    cout<<"enter the size of arr1: ";
    cin>>n1;
    vector<int> arr1(n1);
    for (int i = 0; i < n1; i++)
    {
        cin>>arr1[i];
    }
    int n2;
    cout<<"enter the size of arr2: ";
    cin>>n2;
    vector<int> arr2(n2);
    for (int i = 0; i < n2; i++)
    {
        cin>>arr2[i];
    }

    int k;
    cout<<"enter the element: ";
    cin>>k;

    cout<<brute(arr1,arr2,n1,n2,k);
    
    return 0;
}