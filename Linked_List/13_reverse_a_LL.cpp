#include<iostream>
#include<bits/stdc++.h>
using namespace std;

class node  //Struct doesnt support oops, hence class
{
    public:
    int data;
    node* next;

    public:
    node(int data1, node*next1){
        data = data1;
        next = next1;
    }
    node(int data1){
        data = data1;
        next = nullptr;
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

node* brute(node*head){
    node* temp = head;
    stack<int> st;
    while(temp != NULL){
        st.push(temp->data);
        temp = temp->next;
    }
    node*temp1 = head;
    while(temp1 != NULL){
        temp1->data = st.top();
        st.pop();
        temp1 = temp1->next;
    }
    return head;
}

node* optimal(node* head){
    if(head==NULL || head->next== NULL) return head;
    node*temp = head;
    node* prev = nullptr;
    while(temp!= NULL){
        node*front = temp->next;
        temp->next = prev;
        prev = temp;
        temp = front;
    }
    return prev;
}

node* recursiveOptimal(node*head){
    if(head==NULL || head->next== NULL) return head;//for 1 node
    node*newHead = recursiveOptimal(head->next);
    node*front = head->next;
    front->next = head;
    head->next = nullptr;

    return newHead;
}

int main()
{
    vector<int>arr = {2,5,8,7};
    node*head = arraytoLL(arr);
    // head = brute(head);
    // head = optimal(head);
    head = recursiveOptimal(head);
    traversalofll(head);
    return 0;
}