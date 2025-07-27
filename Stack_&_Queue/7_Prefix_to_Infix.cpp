#include<iostream>
#include<bits/stdc++.h>
using namespace std;

string prefix2infix(string s){
    int i = s.size()-1; //back iteration
    stack<string>st;
    while(i>=0){
        //for the operands
        if((s[i]>='A' && s[i]<='Z')||(s[i]>='a' && s[i]<='z')||(s[i]>='0' && s[i]<='9')){
            st.push(string(1,s[i]));
        }

        //for the operators
        else{
            string t1 = st.top();
            st.pop();
            string t2 = st.top();
            st.pop();
            string conv = '(' + t1 + s[i] + t2 + ')';

            st.push(conv);
        }
        i--;
    }
    return st.top();
}

int main()
{
    string s;
    cout<<"enter the prefix expression: ";
    cin>>s;

    cout<<prefix2infix(s);

    return 0;
}