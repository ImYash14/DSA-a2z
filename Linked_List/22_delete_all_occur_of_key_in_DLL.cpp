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

node* deleteKey(node* head, int key){
    node*temp = head;
    while(temp != NULL){
        if(temp->data == key){
            if(temp == head){
                head = head->next;
            }
            node*nextNode = temp->next;
            node*prevNode = temp->back;

            if(nextNode) nextNode->back = prevNode;
            if(prevNode) prevNode->next = nextNode;

            delete temp;
            temp = nextNode;
        }
        else{
            temp = temp->next;
        }
    }
    return head;
}
int main()
{
    vector<int> arr ={10,4,10,10,6,10};
    node*head = arr2DLL(arr);
    head = deleteKey(head,10);
    traversal(head);
    return 0;
}