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

node* optimal(node* head){
    node* temp = head;
    while(temp != NULL && temp->next != NULL){
        node* nextNode = temp->next;
        while(temp->data == nextNode->data && nextNode != NULL){
            node* duplicate = nextNode;
            nextNode = nextNode->next;
            delete duplicate;
        }
        temp->next = nextNode;
        nextNode->back = temp;

        temp = temp->next;
    }
    return head;
}
int main()
{
    vector<int> arr ={1,1,1,2,3,3,4};
    node*head = arr2DLL(arr);
    head = optimal(head);
    traversal(head);
    return 0;
}