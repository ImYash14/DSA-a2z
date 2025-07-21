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
    if(head == NULL || head->next == NULL) return head;
    node*temp = head;
    int count =0;
    while(temp != NULL){
        count++;
        temp = temp->next;
    }

    node*temp1 = head;
    int mid = count/2 + 1;
    while(temp1 != NULL){
        mid--;
        if(mid==0) break;
        temp1 = temp1->next;
    }
    return temp1;
}

node* optimal(node*head){
    if(head == NULL || head->next == NULL) return head;
    node*slow = head;
    node*fast = head;
    while(fast != NULL && fast->next != NULL){
        slow = slow->next;
        fast = fast->next->next;
    }
    return slow;
}

int main()
{
    vector<int>arr = {1,2,3,4,5,6};
    node*head = arraytoLL(arr);
    // head = brute(head);
    head = optimal(head);
    cout<<head->data;
    // traversalofll(head);
    return 0;
}