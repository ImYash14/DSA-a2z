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

node* reverseLL(node*head){
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

node* iterative(node*head){
    if(head == NULL) return NULL;
    
    head = reverseLL(head);

    node*temp = head;
    int carry =1;
    while(temp != NULL){
        temp->data = (temp->data + carry);
        if(temp->data < 10){
            carry =0;
            break;
        }
        else{
            temp->data = 0;
            carry =1;
        }
        // carry = (temp->data + carry)/10;

        temp = temp->next;
    }

    head = reverseLL(head);

    if(carry){
        node* newHead = new node(carry,head);
        return newHead;
    }
    
    return head;
}

int finalCarry(node*temp){
    if(temp == NULL) return 1; //base case

    int carry = finalCarry(temp->next); //recursion call till temp = null
    //backtracking starts
    temp->data = temp->data + carry;
    if(temp->data < 10){
        return 0; //return carry 0
    }
    temp->data = 0;
    return 1; //return carry 1
}

node* recursive(node*head){
    node*temp = head;
    int carry = finalCarry(temp);
    if(carry == 1){
        node* newNode = new node(1,head);
        return newNode;
    }
    return head;
}

int main()
{
    vector<int>arr = {9,9,9,9};
    node*head = arraytoLL(arr);
    // head = iterative(head);
    head = recursive(head);
    traversalofll(head);
    return 0;
}