#include<iostream>
#include<bits/stdc++.h>
using namespace std;


bool compare(string&s1, string&s2){
    //this func will check if we can form s1 by adding 1 char in s2
    if(s1.size() != s2.size() + 1) return false;
    
    int i =0;
    int j =0;
    while(i < s1.size()){
        if(j < s2.size() && s1[i] == s2[j]){
            i++;
            j++;
        }
        else{
            i++;
        }
    }
    if(i == s1.size() && j == s2.size()) return true;
    return false;
}

bool comp(string &s1, string &s2){
    return s1.size() < s2.size();
}

int longestStringChain(vector<string>&arr){
    int n = arr.size();

    //sort the arr according to string size
    //because question is about sequence and not subsequence
    sort(arr.begin(),arr.end(),comp);

    int maxi =0;
    vector<int>dp(n,1);
    for (int i = 0; i < n; i++)
    {
        for (int prev = 0; prev < i; prev++)
        {
            if(compare(arr[i],arr[prev]) && 1+dp[prev] > dp[i]){
                dp[i] = 1 + dp[prev];
            }
        }
        maxi = max(maxi,dp[i]);
    }
    return maxi;
}

int main()
{
    int n;
    cin>>n;
    vector<string>arr(n);
    for (int i = 0; i < n; i++)
    {
        cin>>arr[i];
    }
    
    cout<<longestStringChain(arr);
    
    return 0;
}