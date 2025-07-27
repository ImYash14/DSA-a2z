#include<iostream>
#include<bits/stdc++.h>
using namespace std;

class minStack{
    public:
    stack<pair<int,int>>st;

    //operations
    void push1(int x){
        if(st.empty()){
            st.push({x,x});
        }
        else{
            st.push({x,min(x,st.top().second)});
        }
    }

    int getMin(){
        return st.top().second;
    }

    int top1(){
        return st.top().first;
    }

    void pop1(){
        st.pop();
    }

    int sizeMinStack(){
        return st.size();
    }
};

class minStackImproved{
    public:
    stack<int>st;
    int mini = INT_MAX;

    //operations
    void push1(int val){
        if(st.empty()){
            st.push(val);
            mini = val;
        }
        else{
            if(val > mini){
                st.push(val);
            }
            else{
                st.push(2*val-mini); //storing the previous min using this formula
                mini = val; 
            }
        }
    }

    void pop1(){
        if(st.empty()) return;
        int x = st.top();
        st.pop();
        if(x < mini){
            mini = 2*mini - x; //previous minimum
        }
        //else no need to update mini
    }

    int top1(){
        if(st.empty()) return -1;
        int x = st.top();
        if(x < mini) return mini;
        else return x;

        return -1;
    }

    int getMin(){
        return mini;
    }

    int sizeofMinStack(){
        return st.size();
    }
};

int main()
{
    minStackImproved st;
    st.push1(12);
    st.push1(15);
    st.push1(10);
    cout<<st.getMin()<<endl;
    st.pop1();
    cout<<st.getMin()<<endl;
    cout<<st.top1()<<endl;
    st.push1(10);
    cout<<st.top1()<<endl;

    return 0;
}