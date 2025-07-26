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

class queImpl{
    public:
    node*start = NULL;
    node*end = NULL;
    int size =0;

    //operations
    void push(int x){
        node* newNode = new node(x);
        if(start == NULL){
            start = newNode;
            end = newNode;
        }
        else{
            end->next = newNode;
            end = newNode;
        }
        size++;
    }

    void pop(){
        if(start == NULL) return;
        node*temp = start;
        start = start->next;
        delete temp;
        size--;
    }

    int top(){
        if(start == NULL) return -1;
        return start->data;
    }

    int sizeofq(){
        return size;
    }
};

int main()
{
    queImpl q;
    q.push(2);
    q.push(1);
    q.push(3);
    q.push(4);
    q.pop();
    cout<<q.top()<<endl;
    q.pop();
    cout<<q.top()<<endl;
    q.push(7);
    cout<<q.top()<<endl;
    cout<<q.sizeofq()<<endl;
       
    return 0;
}