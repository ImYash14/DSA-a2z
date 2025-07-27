#include<iostream>
#include<bits/stdc++.h>
using namespace std;

int priority(char ch){
    if(ch == '^') return 3;
    else if(ch == '*' || ch == '/') return 2;
    else if(ch == '+' || ch == '-') return 1;
    return -1;
}

void reverse(string &s){
    int low =0;
    int high = s.size()-1;
    while(low < high){
        int temp = s[low];
        s[low] = s[high];
        s[high] = temp;
        low++;
        high--;
    }
}

string infix2prefix(string s){
    //step1->reverse the infix expression
    reverse(s);

    //Swap '(' with ')'
    for (int i = 0; i < s.length(); i++) {
        if (s[i] == '(') s[i] = ')';
        else if (s[i] == ')') s[i] = '(';
    }

    int i=0;
    stack<char>st;
    string ans = "";
    while(i<s.size()){
        //for the operands
        if((s[i] >= 'A' && s[i] <= 'Z') || (s[i] >= 'a' && s[i] <='z') || (s[i] >= '0' && s[i] <='9')){
            ans = ans + s[i];
        }
        else if(s[i] == '('){
            st.push(s[i]);
        }
        else if(s[i] == ')'){
            while(!s.empty() && st.top()!= '('){
                ans = ans + st.top();
                st.pop();
            }
            st.pop();//pop the '('
        }

        //for the operators
        else{
            if(s[i] == '^'){
                while(!st.empty() && priority(s[i]) <= priority(st.top())){
                    ans = ans + st.top();
                    st.pop();
                }
            }
            else{
                while(!st.empty() && priority(s[i]) < priority(st.top())){
                    ans = ans + st.top();
                    st.pop();
                }
            }
            st.push(s[i]); //if priority of s[i] >= st.top()
        }
        i++;
    }
    while(!st.empty()){
        ans = ans + st.top();
        st.pop();
    }

    //step3->reverse the ans
    reverse(ans);
    return ans;
}

int main()
{
    string s;
    cout<<"enter the infix expression: ";
    cin>>s;

    cout<<infix2prefix(s);

    return 0;
}