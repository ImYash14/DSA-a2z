#include<iostream>
#include<bits/stdc++.h>
using namespace std;

bool greedy(vector<int>&arr, int n){
    int fives =0;
    int tens =0;
    for (int i = 0; i < n; i++)
    {
        if(arr[i] == 5) fives = fives+1;
        else if(arr[i] == 10){
            if(fives){
                fives = fives-1;
                tens = tens +1;
            }
            else return false;
        }
        else{
            if(fives && tens){
                tens = tens-1;
                fives = fives-1;
            }
            else if(fives >=3){
                fives = fives-3;
            }
            else return false;
        }
    }
    return true;
}

int main()
{
    int n;
    cout<<"enter the no. of customers: ";
    cin>>n;
    vector<int>arr(n);
    for (int i = 0; i < n; i++)
    {
        cin>>arr[i];
    }

    cout<<greedy(arr,n);
    
    return 0;
}