#include<iostream>
#include<bits/stdc++.h>
using namespace std;

int brute(string s, int k){
    int maxlen =0;
    for (int i = 0; i < s.size(); i++)
    {
        set<char>st;
        for (int j = i; j < s.size(); j++)
        {
            st.insert(s[j]);
            if(st.size() <= k){
                maxlen = max(maxlen, j-i+1);
            }
            else break;
        }
        
    }
    return maxlen;
}

int better(string s, int k){
    int maxlen =0;
    int l =0;
    int r=0;
    map<char,int>mpp;
    while(r<s.size()){
        mpp[s[r]]++;

        while(mpp.size() > k){
            mpp[s[l]]--;
            if(mpp[s[l]]==0){
                mpp.erase(s[l]);
            }
            l++;
        }

        if(mpp.size() <= k){
            maxlen = max(maxlen,r-l+1);
        }
        r++;
    }
    return maxlen;
}

int optimal(string s, int k){
    int maxlen =0;
    int l =0;
    int r=0;
    map<char,int>mpp;
    while(r<s.size()){
        mpp[s[r]]++;

        if(mpp.size() > k){
            mpp[s[l]]--;
            if(mpp[s[l]]==0){
                mpp.erase(s[l]);
            }
            l++;
        }

        if(mpp.size() <= k){
            maxlen = max(maxlen,r-l+1);
        }
        r++;
    }
    return maxlen;
}

int main()
{
    string s;
    cout<<"enter the string: ";
    cin>>s;

    int k;
    cout<<"enter the no. of atmost distinct chars: ";
    cin>>k;

    // cout<<brute(s,k);
    cout<<better(s,k);
    // cout<<brute(s,k);

    return 0;
}