#include<iostream>
#include<bits/stdc++.h>
using namespace std;

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

int sumArray(vector<int>&arr, int n){
    int ans =0;
    for (int i = 0; i < n; i++)
    {
        ans = ans + arr[i];
    }
    return ans;   
}

int fun(vector<int>&arr, int n, int pages){
    int stud =1; //initially one student
    int allocate = 0;// and no allocation of books

    for (int i = 0; i < n; i++)
    {
        if(allocate + arr[i] > pages){
            stud++;
            allocate = arr[i];
        }
        else{
            allocate += arr[i];
        }
    }
    return stud;
    
}

int brute(vector<int>&arr, int n, int students){
    if(students > n) return -1;
    for (int i = maxArray(arr,n); i <= sumArray(arr,n); i++)
    {
        if(fun(arr,n,i) <= students){
            return i;
        }
    }
    return -1;   
}

int optimal(vector<int>&arr, int n, int students){
    if(students > n) return -1;

    int low = maxArray(arr,n);
    int high = sumArray(arr,n);
    while(low<=high){
        int mid = (low+high)/2;

        //studs->5................4....4..........1
        //pages->49 50 51.....70 71 72 73.......172
        if(fun(arr,n,mid) > students){
            low = mid+1;
        }
        else{
            high = mid-1;
        }
    }
    return low;
}

int main()
{
    int n;
    cout<<"enter the no. of books: ";
    cin>>n;
    vector<int> arr(n);
    for (int i = 0; i < n; i++)
    {
        cin>>arr[i];
    }

    int students;
    cout<<"enter the no. of students: ";
    cin>>students;
    
    // cout<<brute(arr,n,students);
    cout<<optimal(arr,n,students);

    return 0;
}