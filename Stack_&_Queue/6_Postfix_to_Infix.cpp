#include<iostream>
#include<bits/stdc++.h>
using namespace std;

string postfix2infix(string s){
    int i =0;
    stack<string>st;
    while(i < s.size()){
        //for the operands
        if((s[i]>='A' && s[i]<='Z')||(s[i]>='a' && s[i]<='z')||(s[i]>='0' && s[i]<='9')){
            st.push(string(1,s[i])); //char to string conversion
        }

        //for the operators
        else{
            string t1 = st.top();
            st.pop();
            string t2 = st.top();
            st.pop();
            string conv = '(' + t2 + s[i] + t1 + ')';

            st.push(conv);
        }
        i++;
    }
    return st.top();
}

int main()
{
    string s;
    cout<<"enter the postfix expression: ";
    cin>>s;

    cout<<postfix2infix(s);
    
    return 0;
}