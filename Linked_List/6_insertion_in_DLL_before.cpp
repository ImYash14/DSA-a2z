#include<iostream>
#include<bits/stdc++.h>
using namespace std;

class node{
    public:
    int data;
    node* next;
    node* back;

    node(int data1, node*next1, node*back1){
        data = data1;
        next = next1;
        back = back1;
    }
    node(int data1){
        data = data1;
        next = nullptr;
        back = nullptr;
    }
};

node* arr2DLL(vector<int>&arr){
    node*head = new node(arr[0]);
    node*prev = head;
    for (int i = 1; i < arr.size(); i++)
    {
        node*temp = new node(arr[i],nullptr,prev);
        prev->next= temp;
        prev = temp;
    }
    return head;
}

void traversal(node*head){
    node*temp = head;
    while(temp){
        cout<<temp->data<<" ";
        temp = temp->next;
    }
}

node* insertbeforeHead(node*head, int value){
    node* newNode = new node(value,head,nullptr);
    head->back = newNode;
    return newNode;
}

node* insertbeforeTail(node*head, int value){
    if(head->next == NULL){
        return insertbeforeHead(head,value);
    }
    node*tail = head;
    while(tail->next != NULL){
        tail = tail->next;
    }
    node*prev = tail->back;
    node* newNode = new node(value,tail,prev);
    prev->next=newNode;
    tail->back=newNode;
    return head;
}

void insertbeforeNode(node*temp,int value){
    node*prev = temp->back;
    node*newNode = new node(value,temp,prev);
    prev->next= newNode;
    temp->back = newNode;
}

node* insertbeforeKth(node*head, int k, int value){
    if(k==1) return insertbeforeHead(head,value);
    int count =0;
    node*temp = head;
    while(temp != NULL){
        count++;
        if(count==k) break;
        temp = temp->next;
    }
    node*prev = temp->back;
    node*newNode = new node(value,temp,prev);
    prev->next = newNode;
    temp->back = newNode;
    return head;
}
int main()
{
    vector<int> arr ={1,2,3,4,5};
    node*head = arr2DLL(arr);
    // head = insertbeforeHead(head,10);
    // head = insertbeforeTail(head,10);
    // head = insertbeforeKth(head,2,10);
    insertbeforeNode(head->next->next,10);

    traversal(head);
    return 0;
}