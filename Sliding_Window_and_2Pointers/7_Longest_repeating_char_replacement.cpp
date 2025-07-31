#include<iostream>
#include<bits/stdc++.h>
using namespace std;

int brute(string s, int k){
    int maxlen =0;
    for (int i = 0; i < s.size(); i++)
    {
        vector<int>hasharr(26,0);
        int maxfreq =0;
        for (int j = i; j < s.size(); j++)
        {
            hasharr[s[j]-'A']++;
            maxfreq = max(maxfreq, hasharr[s[j]-'A']);

            int changes = (j-i+1)-maxfreq;
            if(changes <= k){
                maxlen = max(maxlen,j-i+1);
            }
            else break;
        }
        
    }
    return maxlen;
}

int better(string s, int k){
    int maxlen =0;
    int l =0;
    int r =0;
    int maxfreq = 0;
    vector<int>hasharr(26,0); 
    while(r<s.size()){
        //step1->push the freq in hash and calculate maxfreq
        hasharr[s[r]-'A']++;
        maxfreq = max(maxfreq, hasharr[s[r]-'A']);

        //if invalid substring
        while(((r-l+1)-maxfreq) > k){
            hasharr[s[l]-'A']--;
            //recalculate the maxfreq in hash
            maxfreq =0;
            for (int i = 0; i < 26; i++)
            {
                maxfreq = max(maxfreq,hasharr[i]);
            }
            l++;
        }

        //if valid substring
        if(((r-l+1)-maxfreq) <= k){
            maxlen = max(maxlen, r-l+1);
        }
        r++;
    }
    return maxlen;
}

int optimal(string s, int k){
    int maxlen =0;
    int l =0;
    int r =0;
    int maxfreq = 0;
    vector<int>hasharr(26,0); 
    while(r<s.size()){
        //step1->push the freq in hash and calculate maxfreq
        hasharr[s[r]-'A']++;
        maxfreq = max(maxfreq, hasharr[s[r]-'A']);

        //if invalid substring
        if(((r-l+1)-maxfreq) > k){
            hasharr[s[l]-'A']--;
            l++;
        }

        //if valid substring
        if(((r-l+1)-maxfreq) <= k){
            maxlen = max(maxlen, r-l+1);
        }
        r++;
    }
    return maxlen;
}


int main()
{
    string s;
    cout<<"enter the string in caps: ";
    cin>>s;

    int k;
    cout<<"enter the no. of atmost changes allowed: ";
    cin>>k;

    // cout<<brute(s,k);
    // cout<<better(s,k);
    cout<<optimal(s,k);

    return 0;
}