#include<iostream>
#include<bits/stdc++.h>
using namespace std;

class queImpl{
    public:
    int size = 4;
    int que[4];
    int currSize =0;
    int start = -1;
    int end = -1;

    //operations
    void push(int x){
        if(currSize == size) return;
        if(currSize == 0){
            start =0;
            end =0;
        }
        else{
            end = (end+1)%size;
        }

        que[end] = x;
        currSize = currSize+1;
    }

    void pop(){
        if(currSize == 0) return;
        // int ele = que[start];
        if(currSize == 1){
            start = -1;
            end =-1;
        }
        else{
            start = (start+1)%size;
        }
        currSize = currSize-1;
    }

    int top(){
        if(currSize == 0) return -1;
        return que[start];
    }

    int sizeofq(){
        return currSize;
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