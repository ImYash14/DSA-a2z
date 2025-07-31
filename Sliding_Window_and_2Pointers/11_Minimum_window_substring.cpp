#include<iostream>
#include<bits/stdc++.h>
using namespace std;

string brute(string s, string t){
    int minlen = INT_MAX;
    int ansStart = -1;
    for (int i = 0; i < s.size(); i++)
    {
        vector<int>hasharr(256,0);
        int count =0;
        //push the char of string t in hash
        for (int j = 0; j < t.size(); j++)
        {
            hasharr[t[j]]++;
        }

        for (int j = i; j < s.size(); j++)
        {
            //if +ve, means preinserted
            if(hasharr[s[j]] > 0){
                count++;
            }
            hasharr[s[j]]--;//while inserting

            if(count == t.size()){
                if(j-i+1 < minlen){
                    minlen = j-i+1;
                    ansStart =i;//store the index of min substr
                    break;
                }
            }
        }
        
    }
    if(ansStart == -1) return "";
    return s.substr(ansStart,minlen); //prints the min substring   
}

string optimal(string s, string t){
    int l =0;
    int r =0;
    int minlen = INT_MAX;
    int count =0;
    int ansStart = -1;
    vector<int>hasharr(256,0);
    //push the char of t in hash
    for (int i = 0; i < t.size(); i++)
    {
        hasharr[t[i]]++;
    }
    while(r<s.size()){

        if(hasharr[s[r]] > 0){
            count++;
        }
        hasharr[s[r]]--; //while inserting

        while(count == t.size()){
            if(r-l+1 < minlen){
                minlen = r-l+1;
                ansStart = l;
            }
            hasharr[s[l]]++; //while moving l, we will also remove s[l] frequencies
            if(hasharr[s[l]] >0){
                count--; //for reinserting
            }
            l++;
        }
        r++;
    }
    if(ansStart == -1) return "";
    return s.substr(ansStart,minlen);
}

int main()
{
    string s;
    cout<<"enter the string s: ";
    cin>>s;

    string t;
    cout<<"enter the string t: ";
    cin>>t;

    // cout<<brute(s,t);
    cout<<optimal(s,t);

    return 0;
}