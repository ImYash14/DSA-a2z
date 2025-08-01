#include<iostream>
#include<bits/stdc++.h>
using namespace std;

int greedy(vector<int>&cookie,vector<int>&greed, int n1, int n2){
    sort(cookie.begin(),cookie.end());
    sort(greed.begin(),greed.end());
    int l =0;
    int r=0;
    while(l<n1 && r<n2){
        if(greed[r] <= cookie[l]){
            r = r+1; //children satisfied
        }
        l= l+1;
    }
    return r;
}

int main()
{
    int n1;
    cout<<"enter the size of cookie arr: ";
    cin>>n1;
    vector<int>cookie(n1);
    for (int i = 0; i < n1; i++)
    {
        cin>>cookie[i];
    }

    int n2;
    cout<<"enter the size of greed arr: ";
    cin>>n2;
    vector<int>greed(n2);
    for (int i = 0; i < n2; i++)
    {
        cin>>greed[i];
    }
    
    cout<<greedy(cookie,greed,n1,n2);
    
    return 0;
}