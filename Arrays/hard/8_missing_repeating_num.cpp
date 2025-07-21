#include<iostream>
#include<bits/stdc++.h>
using namespace std;

vector<int> brute(vector<int>&arr, int n){
    int repeat =-1;
    int miss =-1;
    for (int i = 1; i <= n; i++)
    {
        int count =0;
        for (int j = 0; j < n; j++)
        {
            if(i == arr[j]) count++;
        }
        if(count > 1){
            repeat = i;
        }
        else if(count == 0){
            miss = i;
        }

        if(repeat != -1 && miss != -1) break;
        
    }
    vector<int> ans = {repeat, miss};
    return ans;
    
}

vector<int> better(vector<int>&arr, int n){
    vector<int> hasharr(n+1);
    int repeat =-1;
    int miss =-1;
    
    for (int i = 0; i < n; i++)
    {
        hasharr[arr[i]]++;
    }
    for (int i = 1; i <=n; i++)
    {
        if(hasharr[i] > 1) repeat = i;
        else if(hasharr[i] == 0) miss = i;
        
        if(repeat != -1 && miss != -1) break;
    }
    
    vector<int> ans = {repeat, miss};
    return ans;
    
}

vector<int> optimal1(vector<int> &arr, int n){
    long long sum1 =0;
    long long sumn1 = (n*(n+1))/2;
    long long sum2 =0;
    long long sumn2 = (n*(n+1)*(2*n+1))/6;
    for (int i = 0; i < n; i++)
    {
        sum1 = sum1 + (long long)arr[i];
        sum2 = sum2*sum2 + (long long)arr[i]*(long long)arr[i];
    }
    long long val1 = sum1-sumn1;
    long long val2 = sum2-sumn2;
    val2 = val2/val1;
    long long x = (val1+val2)/2;
    long long y = val2 - x;
    
    vector<int> ans = {(int)x,(int)y};
    return ans;
}
int main()
{
    int n;
    cout<<"enter the size of array: ";
    cin>> n;
    vector<int>arr(n);
    for (int i = 0; i < n; i++)
    {
        cin>>arr[i];
    }

    // vector<int>result = brute(arr,n);
    // vector<int>result = better(arr,n);
    vector<int>result = optimal1(arr,n);
    for(auto it: result){
        cout<<it<<" ";
    }
    
    return 0;
}