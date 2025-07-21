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

node* optimal(node* head, int k){
    //step1-> find tail and calculate length
    node* tail = head;
    int len = 1;
    while(tail->next != NULL){
        len++;
        tail = tail->next;
    }

    
    k = k % len;
    if(k == 0) {
        // Break the circle
        tail->next = NULL;
        return head;
    }

    tail->next = head;

    //step2-> find (len-k) and stop on that node
    node*temp = head;
    int res = len-k;
    while(temp != NULL){
        res--;
        if(res == 0) break;

        temp = temp->next;
    }

    //step3-> change links
    head = temp->next;
    temp->next = NULL;

    return head;
}

int main()
{
    vector<int>arr = {1,2,3,4,5};
    node*head = arraytoLL(arr);
    head = optimal(head,2);
    traversalofll(head);
    return 0;
}