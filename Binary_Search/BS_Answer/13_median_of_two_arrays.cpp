#include<iostream>
#include<bits/stdc++.h>
using namespace std;

double brute(vector<int>&arr1, int n1, vector<int>&arr2, int n2){
    int n = n1+n2;
    vector<int>temp(n);
    int low =0;
    int high =0;
    while(low<n1 && high<n2){
        if(arr1[low] < arr2[high]) temp.push_back(arr1[low++]);
        else temp.push_back(arr2[high++]);
    }
    while(low<n1){
        temp.push_back(arr1[low++]);
    }
    while(high<n2){
        temp.push_back(arr2[high++]);
    }

    if(n%2 == 1){
        return temp[n/2];
    }
    
    return (double)((double)(temp[n/2]) + (double)(temp[(n/2)-1]))/2.0;
    
}

double better(vector<int>&arr1,int n1,vector<int>&arr2, int n2){
    int n = n1+n2;
    int low =0;
    int high =0;
    int countInd = 0;
    int index1 = n/2;
    int index2 = (n/2)-1;
    int element1 = INT_MIN;
    int element2 = INT_MIN;

    while(low<n1 && high<n2){
        if(arr1[low]<arr2[high]){
            if(countInd==index1) element1 = arr1[low];
            if(countInd==index2) element2 = arr1[low];
            low++;
            countInd++;
        }
        else{
            if(countInd==index1) element1 = arr2[high];
            if(countInd==index2) element2 = arr2[high];
            high++;
            countInd++;
        }
    }
    while(low<n1){
        if(countInd==index1) element1 = arr1[low];
        if(countInd==index2) element2 = arr1[low];
        low++;
        countInd++;
    }
    while(high<n2){
        if(countInd==index1) element1 = arr2[high];
        if(countInd==index2) element2 = arr2[high];
        high++;
        countInd++;
    }

    if(n%2 == 1){
        return element1;
    }
    else{
        return (double)((double)(element1+element2))/2.0;
    }
    return 0;
}

double optimal(vector<int>&arr1,int n1, vector<int>&arr2, int n2){
    int n = n1+n2;
    int left = (n1+n2+1)/2;
    int low =0;
    int high = n1;
    while(low<=high){
        int mid1 = (low+high)/2;
        int mid2 = left-mid1;
        int l1 = INT_MIN;
        int l2 = INT_MIN;
        int r1 = INT_MAX;
        int r2 = INT_MAX;
        if(mid1<n1) r1 = arr1[mid1];
        if(mid2<n2) r2 = arr2[mid2];
        if(mid1-1>=0) l1 = arr1[mid1-1];
        if(mid2-1>=0) l2 = arr2[mid2-1];

        if(l1<=r2 && l2<=r1){
            if(n%2==1){
                return max(l1,l2);
            }
            else{
                return (double)(max(l1,l2) + min(r1,r2))/2.0;
            }
        }
        else if(l1>r2) high = mid1-1;
        else low = mid1+1;
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

    cout<<brute(arr1,n1,arr2,n2);
    cout<<better(arr1,n1,arr2,n2);
    cout<<optimal(arr1,n1,arr2,n2);

    return 0;
}