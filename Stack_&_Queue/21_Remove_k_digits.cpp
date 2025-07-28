#include<iostream>
#include<bits/stdc++.h>
using namespace std;

string optimal(string s, int k){
    stack<char>st;
    for (int i = 0; i < s.size(); i++)
    {
        while(!st.empty() && k>0 && (st.top()-'0') > (s[i]-'0')){//following the prev smaller element rule
            st.pop();
            k= k-1;
        }
        st.push(s[i]);
    }

    //Edge cases
    //1->if we did not pop all k digits
    while(k>0){
        st.pop();
        k--;
    }

    //2->if stack is empty
    if(st.empty()) return "0";

    string ans = "";
    while(!st.empty()){
        ans = ans + st.top();
        st.pop();
    }

    //3->if ans contains initial zeros
    while(ans.size()!=0 && ans.back()=='0'){
        ans.pop_back();
    }

    reverse(ans.begin(),ans.end());

    //important to check if ans is empty after poping initial zeros
    //because ans can be "0000000"etc
    if(ans.empty()) return "0";
    return ans;
}

int main()
{
    string s;
    cout<<"enter the number: ";
    cin>>s;
    int k;
    cout<<"enter the no. of digits to remove: ";
    cin>>k;

    cout<<optimal(s,k);

    return 0;
}