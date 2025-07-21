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

int lengthofLL(node*head){
    int count =0;
    node*temp = head;
    while(temp){
        temp = temp->next;
        count++;
    }
    return count;
}

bool searchLL(node*head, int value){
    node*temp = head;
    while(temp){
        if(temp->data == value) return true;
        temp =temp->next;
    }
    return false;
}
int main()
{
    // vector<int>arr = {1, 2, 3, 4};
    // node*y = new node(arr[0],nullptr);
    // cout<<y<<endl;
    // cout<<y->data<<endl;
    // cout<<y->next<<endl;

    // node x = node(arr[1],nullptr);
    // cout<<x.data<<endl;
    // cout<<x.next<<endl;

    vector<int>arr = {2,5,8,7};
    node*head = arraytoLL(arr);
    // cout<<head->data<<endl;
    // cout<<head->next<<endl;


    // cout<<lengthofLL(head);
    // cout<<searchLL(head,8);
    traversalofll(head);
    return 0;
}