#include<iostream>
#include<bits/stdc++.h>
using namespace std;

int brute(vector<int>&arr, int n){
    int maxlen =0;
    for (int i = 0; i < n; i++)
    {
        set<int>st;
        for (int j = i; j < n; j++)
        {
            st.insert(arr[j]);
            if(st.size() <= 2){
                maxlen = max(maxlen, j-i+1);
            }
            else break;
        }
        
    }
    return maxlen;
}

int better(vector<int>&arr, int n){
    int maxlen =0, l=0,r=0;
    map<int,int>mpp;
    while(r<n){
        mpp[arr[r]]++;

        while(mpp.size() > 2){
            mpp[arr[l]]--;
            if(mpp[arr[l]] == 0){
                mpp.erase(arr[l]);
            }
            l++;
        }

        if(mpp.size() <= 2){
            maxlen = max(maxlen,r-l+1);
        }
        r++;
    }
    return maxlen;
}

int optimal(vector<int>&arr, int n){
    int maxlen =0, l=0,r=0;
    map<int,int>mpp;
    while(r<n){
        mpp[arr[r]]++;

        if(mpp.size() > 2){
            mpp[arr[l]]--;
            if(mpp[arr[l]] == 0){
                mpp.erase(arr[l]);
            }
            l++;
        }

        if(mpp.size() <= 2){
            maxlen = max(maxlen,r-l+1);
        }
        r++;
    }
    return maxlen;
}


int main()
{
    int n;
    cout<<"enter the no. of trees: ";
    cin>>n;
    vector<int>arr(n);
    for (int i = 0; i < n; i++)
    {
        cin>>arr[i];
    }

    // cout<<brute(arr,n);
    cout<<better(arr,n);
    
    return 0;
}