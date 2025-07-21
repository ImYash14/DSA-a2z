#include<iostream>
#include<bits/stdc++.h>
using namespace std;

class node  //Struct doesnt support oops, hence class
{
    public:
    int data;
    node* next;
    node* child;

    public:
    node(int data1, node*next1, node*child1){
        data = data1;
        next = next1;
        child = child1;
    }
    node(int data1){
        data = data1;
        next = nullptr;
        child = nullptr;
    }
    node(int data1,node*next1){
        data = data1;
        next = next1;
        child = nullptr;
    }
   
};

node* arraytoLL(vector<int>&arr){
    node*head = new node(arr[0]);
    node*mover = head;
    for (int i = 1; i < arr.size(); i++)
    {
        node*temp = new node(arr[i]);
        mover->next = temp;
        mover = temp;
    }
    return head;
}

void traversalofll(node*head){
    node*temp = head;
    while(temp){
        cout<<temp->data<<" ";
        temp = temp->next;
    }
}

node* convert(vector<int>&arr){
    node* head = new node(arr[0]);
    node* prev = head;
    for (int i = 1; i < arr.size(); i++)
    {
        node* temp = new node(arr[i]);
        prev->child= temp;
        prev = temp;
    }
    return head;
}

node* brute(node*head){
    //step1->take an array and put the data in it
    vector<int>arr;
    node*temp = head;
    while(temp != NULL){
        node*t = temp;
        while(t != NULL){
            arr.push_back(t->data);
            t = t->child;
        }
        temp = temp->next;
    }

    //step2->sort the array
    sort(arr.begin(),arr.end());

    //step3->convert the arr to vertical ll
    node*newhead = convert(arr);

    return newhead;
}

node* merge(node*newHead, node* currHead){
    node*dummyNode = new node(-1);
    node* temp = dummyNode;
    node* t1 = newHead;
    node* t2 = currHead;
    while(t1 != NULL && t2 != NULL){
        if(t1->data < t2->data){
            temp->child = t1;
            temp = t1;
            t1= t1->child;
        }
        else{
            temp->child = t2;
            temp = t2;
            t2= t2->child;
        }
        temp->next = NULL;
    }
    return dummyNode->child;
}

node*optimal(node*head){
    //recursion
    //base case
    if(head == NULL || head->next == NULL){
        return head;
    }

    //for going deep
    node* mergedHead = optimal(head->next);

    //for backtracking
    return merge(head, mergedHead);
}

int main()
{
    vector<int>arr = {2,5,8,7};
    node*head = arraytoLL(arr);
    
    traversalofll(head);
    return 0;
}