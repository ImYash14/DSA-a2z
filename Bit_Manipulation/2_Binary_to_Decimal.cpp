#include<iostream>
#include<bits/stdc++.h>
using namespace std;

int fun(string s){
    int n = s.size();
    int ans =0;
    int power =1;
    for (int i = n-1; i>=0; i--)
    {
        if(s[i] == '1'){
            ans = ans + power;
        }
        power = power*2;
    }
    return ans;
}

int main()
{
    string s;
    cout<<"enter the binary: ";
    cin>>s;

    cout<<fun(s);
    return 0;
}