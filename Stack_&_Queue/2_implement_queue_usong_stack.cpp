#include<iostream>
#include<bits/stdc++.h>
using namespace std;

class queUsingSt{
    public:
    stack<int>s1;
    stack<int>s2;

    //operations
    void qpush(int x){
        //step1-> s1->s2
        while(s1.size()){
            s2.push(s1.top());
            s1.pop();
        }

        //step2-> x->s1
        s1.push(x);

        //step3-> s2->s1
        while(s2.size()){
            s1.push(s2.top());
            s2.pop();
        }
    }

    void qpop(){
        s1.pop();
    }

    int qtop(){
        return s1.top();
    }

    int qsize(){
        return s1.size();
    }
};

class queUsingSt1{
    public:
    stack<int>s1;
    stack<int>s2;

    //operations
    void qpush(int x){
        s1.push(x);
    }

    void qpop(){
        if(s2.size() != 0){
            s2.pop();
        }
        else{
            //s1->s2
            //s2.pop()
            while(s1.size()){
                s2.push(s1.top());
                s1.pop();
            }
            s2.pop();
        }
    }

    int qtop(){
        if(s2.size() != 0){
            return s2.top();
        }
        else{
            //s1->s2
            //s2.top()
            while(s1.size()){
                s2.push(s1.top());
                s1.pop();
            }
            return s2.top();
        }
        return -1;
    }

    int qsize(){
        return s1.size() + s2.size();
    }
};

int main()
{
    queUsingSt1 q;
    q.qpush(2);
    q.qpush(1);
    q.qpush(3);
    q.qpush(4);
    q.qpop();
    cout<<q.qtop()<<endl;
    q.qpop();
    cout<<q.qtop()<<endl;
    q.qpush(7);
    cout<<q.qtop()<<endl;
    cout<<q.qsize()<<endl;
    return 0;
}