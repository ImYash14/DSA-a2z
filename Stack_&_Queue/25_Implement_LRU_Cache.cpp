#include<iostream>
#include<bits/stdc++.h>
using namespace std;

class node{
    public:
    int key;
    int value;
    node*next;
    node*prev;

    node(int key1, int value1,node*next1,node*prev1){
        key = key1;
        value = value1;
        next = next1;
        prev = prev1;
    }
    node(int key1, int value1){
        key = key1;
        value = value1;
        next = nullptr;
        prev = nullptr;
    }
};

class LRUCache{
    private:
    void deleteNode(node*temp){
        node*nextNode = temp->next;
        node*prevNode = temp->prev;
        prevNode->next = nextNode;
        nextNode->prev = prevNode;
    }

    void insertAfterHead(node*head, node*temp){
        temp->next = head->next;
        head->next->prev = temp;

        head->next = temp;
        temp->prev = head;
    }

    public:
    map<int,node*>mpp;
    int capacity;
    node*head;
    node*tail;

    LRUCache(int capacity1){
        capacity=capacity1;
        mpp.clear();
        head = new node(-1,-1);
        tail = new node(-1,-1);
        head->next = tail;
        tail->prev = head;
    }

    int get(int key1){
        if(mpp.find(key1) == mpp.end()) return -1;//if key not found in the map
       
        //if key found in the map
        node*temp = mpp[key1];
        deleteNode(temp);
        insertAfterHead(head,temp);

        return temp->value;
    }

    void put(int key1,int value1){
        if(mpp.find(key1) != mpp.end()){//if key found in the map
            node*temp = mpp[key1];
            temp->value = value1; //update the value of key

            deleteNode(temp);
            insertAfterHead(head,temp);
        }
        else{//if key not found in the map
            if(mpp.size()==capacity){ //if capacity is full
                node*temp1 = tail->prev; //delete least recently use cache
                mpp.erase(temp1->key);
                deleteNode(temp1);
            }

            //if capacity is not full
            node* newNode = new node(key1, value1);
            mpp[key1] = newNode; 
            insertAfterHead(head,newNode);
        }
    }
};

int main()
{
    LRUCache c(4);
    c.put(2,6);
    c.put(4,7);
    c.put(8,11);
    c.put(7,10);
    cout<<c.get(2)<<endl;
    cout<<c.get(8)<<endl;
    c.put(5,6);
    cout<<c.get(7)<<endl;
    c.put(5,7);
    
    return 0;
}