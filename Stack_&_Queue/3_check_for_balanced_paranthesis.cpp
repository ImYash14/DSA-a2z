#include<iostream>
#include<bits/stdc++.h>
using namespace std;

bool fun(string s){
    stack<int>st;
    for (int i = 0; i < s.size(); i++)
    {
        if(s[i] == '(' || s[i] == '{' || s[i] == '['){
            st.push(s[i]);
        }
        else{
            if(st.empty()) return false;
            char ch = st.top();
            st.pop();

            if((s[i]==')' && ch=='(') || (s[i]=='}' && ch=='{') || (s[i]==']' && ch=='[')){
                //it is valid
            }
            else{
                return false;
            }
        }
    }
    return st.empty();
    //true->if st is empty, means each closing has an opening
    //false->if st is not empty, means not every closing has an opening
}

int main()
{
    string s;
    cout<<"enter the string of parenthesis: ";
    cin>>s;

    cout<<fun(s); //1 if true , 0 if false

    return 0;
}