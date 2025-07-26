#include<iostream>
#include<bits/stdc++.h>
using namespace std;

class stackImpl{
    public:
    int topp =-1;
    int st[10];

    //operations
    void push(int x){
        if(topp >= 10) return;
        topp = topp+1;
        st[topp] = x;
    }

    int top(){
        if(topp == -1) return -1;
        return st[topp];
    }

    void pop(){
        if(topp == -1) return;
        topp = topp-1;
    }

    int size(){
        return topp+1;
    }
};

int main()
{
    stackImpl st;
    st.push(2);
    st.push(1);
    st.push(3);
    st.push(4);
    st.pop();
    cout<<st.top()<<endl;
    st.pop();
    cout<<st.top()<<endl;
    st.push(7);
    cout<<st.top()<<endl;
    cout<<st.size()<<endl;
   
    return 0;
}