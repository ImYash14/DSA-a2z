#include<iostream>
#include<bits/stdc++.h>
using namespace std;

class node{
    public:
    int data;
    node*next;

    node(int data1, node*next1){
        data = data1;
        next = next1;
    }
    node(int data1){
        data = data1;
        next = nullptr;
    }
};

class stackImpl{
    public:
    node*topp = NULL;
    int size =0;

    //operations
    void push(int x){
        node* newNode = new node(x,topp);
        topp = newNode;
        size++;
    }

    void pop(){
        if(topp == NULL) return;
        node*temp = topp;
        topp = topp->next;
        delete temp;
        size--;
    }

    int top(){
        if(topp == NULL) return -1;
        return topp->data;
    }

    int sizeofst(){
        return size;
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
    cout<<st.sizeofst()<<endl;

    return 0;
}