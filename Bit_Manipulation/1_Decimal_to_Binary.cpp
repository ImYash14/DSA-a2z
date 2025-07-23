#include<iostream>
#include<bits/stdc++.h>
using namespace std;

void reverse(string &s){
    int low =0;
    int high =s.size()-1;
    while(low < high){
        int temp = s[low];
        s[low] = s[high];
        s[high] = temp;
        low++;
        high--;
    }
}

string fun(int n){
    string ans = "";
    while(n != 1){
        if(n%2 == 1) ans += '1';
        else ans += '0';

        n = n/2;
    }
    ans += '1'; //taking the last left 1
    reverse(ans);
    return ans;
}

int main()
{
    int n;
    cout<<"enter the number: ";
    cin>>n;

    cout<<fun(n);
    return 0;
}