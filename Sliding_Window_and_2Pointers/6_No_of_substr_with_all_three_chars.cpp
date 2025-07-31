#include<iostream>
#include<bits/stdc++.h>
using namespace std;

int brute(string s){
    int count =0;
    for (int i = 0; i < s.size(); i++)
    {
        set<int>st;
        for (int j = i; j < s.size(); j++)
        {
            st.insert(s[j]);
            if(st.size() == 3) count++;
            else continue;
        }
        
    }
    return count;
}

int better(string s){
    int n = s.size();
    int count =0;
    for (int i = 0; i < n; i++)
    {
        vector<int>hasharr(3,0);
        for (int j = i; j < n; j++)
        {
            hasharr[s[j] - 'a'] = 1; //a =0, b=1, c=2
            if(hasharr[0] + hasharr[1] + hasharr[2] == 3){
                count = count + (n-j);
                break;
            }
        }
        
    }
    return count;
}

int optimal(string s){
    int count =0;
    vector<int>hasharr(3,-1);
    for (int i = 0; i < s.size(); i++)
    {
        hasharr[s[i]-'a'] = i;
        if(hasharr[0]!=-1 && hasharr[1]!=-1 && hasharr[2]!=-1){ //all three are seen
            count = count + 1 + min(hasharr[0],min(hasharr[1],hasharr[2]));
        }
    }
    return count;
}

int main()
{
    string s;
    cout<<"enter the string containing a,b,c: ";
    cin>>s;

    // cout<<brute(s);
    // cout<<better(s);
    cout<<optimal(s);

    return 0;
}