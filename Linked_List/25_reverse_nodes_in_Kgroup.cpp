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


node* reversell(node*head){
    node*temp = head;
    node*prev = NULL;
    while(temp != NULL){
        node*front = temp->next;
        temp->next = prev;
        prev = temp;
        temp = front;
    }
    return prev;
}

node* findKthNode(node*temp, int k){
    k = k-1;
    while(k != 0 && temp != NULL){
        k--;
        temp = temp->next;
    }
    return temp;
}

node* optimal(node* head, int k){
    node* temp = head;
    node*prevNode = NULL;
    while(temp != NULL){
        //step1-> finding kth node
        node* kNode = findKthNode(temp,k);
        if(kNode == NULL){  //if links are smaller than k
            if(prevNode){
                prevNode->next = temp;
                break;
            }
            return head;
        }

        //step2-> group link separation
        node*nextNode = kNode->next; //for next group
        kNode->next = NULL;

        //step3-> reverse the group
        reversell(temp);
        if(temp == head){
            head = kNode;
        }
        else{
            prevNode->next = kNode; //if this is not the first group
        }

        //step4->moving to check for new group
        prevNode = temp;
        temp = nextNode;
    }
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