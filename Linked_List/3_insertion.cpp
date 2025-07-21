#include<iostream>
#include<bits/stdc++.h>
using namespace std;
class node{
    public:
    int data;
    node*next;

    node(int data1, node*next1){
        data = data1;
        next = next1;
    }
    node(int data1){
        data = data1;
        next = nullptr;
    }

};

node* arr2ll(vector<int>&arr){
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

void traversal(node*head){
    node*temp = head;
    while (temp)
    {
        cout<<temp->data<<" ";
        temp = temp->next;
    }
    
}

node* insertBegin(node*head, int val){
    node*temp = new node(val,head);
    return temp;
}

node* insertEnd(node*head, int val){
    if(head == NULL){
        return new node(val);
    }
    node*temp = head;
    while(temp->next != NULL){
        temp = temp->next;
    }
    node* newNode = new node(val);
    temp->next = newNode;
    return head;
}

node* insertKth(node*head, int element, int k){
    if(head == NULL){
        if(k==1) return new node(element);
        else return NULL;
    }
    if(k==1){
        node* newNode = new node(element,head);
        return newNode;
    }
    
    int count =0;
    node*temp = head;
    while(temp != NULL){
        count++;
        if(count == k-1){
            node* newNode = new node(element);
            newNode->next= temp->next;
            temp->next = newNode;
            break;
        }
        temp = temp->next;
    }
    return head;
}

node* insertBeforeValue(node*head, int element, int value){
    if(head == NULL){
        return NULL;
    }
    if(head->data == value){
        node* newNode = new node(element,head);
        return newNode;
    }
    
    node*temp = head;
    while(temp->next != NULL){
        if(temp->next->data == value){
            node* newNode = new node(element);
            newNode->next= temp->next;
            temp->next = newNode;
            break;
        }
        temp = temp->next;
    }
    return head;
}
int main()
{
    vector<int>arr ={1,2,3,4,5};
    node*head = arr2ll(arr);

    // head = insertBegin(head,100);
    // head = insertEnd(head,100);
    // head = insertKth(head,100,5);
    head = insertBeforeValue(head,100,4);


    traversal(head);
    return 0;
}