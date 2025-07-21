#include<iostream>
#include<bits/stdc++.h>
using namespace std;

bool fun(vector<int>&arr, int n, int distance, int cows){
    int countCows = 1;
    int last = arr[0]; //first cow to be placed at first(greedy)
    for (int i = 1; i <= n-1; i++)
    {
        if(arr[i] - last >= distance){
            countCows++;
            last = arr[i];
        }

        if(countCows >= cows) return true;
    }
    return false;
    
}

int brute(vector<int>&arr, int n, int cows){
    sort(arr.begin(),arr.end());
    for (int i = 1; i <= arr[n-1] - arr[0]; i++)
    {
        if(fun(arr,n,i,cows) == true){
            continue;
        }
        else return (i-1);
    }
    return -1;
}

int optimal(vector<int>&arr, int n, int cows){
    if(cows<2) return -1;
    sort(arr.begin(),arr.end());
    int low = 1;
    int high = arr[n-1] - arr[0];
    while(low<=high){
        int mid = (low+high)/2;
        if(fun(arr,n,mid,cows) == true){
            low = mid+1;
        }
        else{
            high = mid-1;
        }
    }
    return high;
}
int main()
{
    int n;
    cout<<"enter the size of array of stall no.: ";
    cin>>n;

    vector<int> arr(n);
    for (int i = 0; i < n; i++)
    {
        cin>>arr[i];
    }

    int cows;
    cout<<"enter the no.of cows to be placed: ";
    cin>>cows;  //cows>=2

    // cout<<brute(arr,n,cows);
    cout<<optimal(arr,n,cows);
    
    return 0;
}