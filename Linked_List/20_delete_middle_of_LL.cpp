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
    if(head == NULL || head->next == NULL) return NULL;
    node*temp = head;
    int count =0;
    while(temp != NULL){
        count++;
        temp = temp->next;
    }

    int res = count/2;
    node*temp1 = head;
    while(temp1 != NULL){
        res--;
        if(res == 0) break;

        temp1 = temp1->next;
    }

    node*middle = temp1->next;
    temp1->next = temp1->next->next;
    delete middle;
    return head;
}

node* optimal(node*head){
    node* slow = head;
    node* fast = head;
    fast = fast->next->next; // skip one step of slow
    while(fast != NULL && fast->next != NULL){
        slow = slow->next;
        fast = fast->next->next;
    }
    node* middle = slow->next;
    slow->next = slow->next->next;
    delete middle;
    return head;
}

int main()
{
    vector<int>arr = {2,5,8,7};
    node*head = arraytoLL(arr);
    // head = brute(head);
    head = optimal(head);
    traversalofll(head);
    return 0;
}