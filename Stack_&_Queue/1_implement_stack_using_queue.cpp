#include<iostream>
#include<bits/stdc++.h>
using namespace std;

class stackUsingQue{
    public:
    queue<int>que;

    //operations
    void stpush(int x){
        int s = que.size();
        que.push(x);
        for (int i = 1; i <= s; i++)
        {
            que.push(que.front());
            que.pop();
        }        
    }

    void stpop(){
        que.pop();
    }

    int sttop(){
        return que.front();
    }

    int stsize(){
        return que.size();
    }
};

int main()
{
    stackUsingQue st;
    st.stpush(2);
    st.stpush(1);
    st.stpush(3);
    st.stpush(4);
    st.stpop();
    cout<<st.sttop()<<endl;
    st.stpop();
    cout<<st.sttop()<<endl;
    st.stpush(7);
    cout<<st.sttop()<<endl;
    cout<<st.stsize()<<endl;
    return 0;
}