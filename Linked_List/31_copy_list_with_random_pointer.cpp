#include<iostream>
#include<bits/stdc++.h>
using namespace std;

class node  //Struct doesnt support oops, hence class
{
    public:
    int data;
    node* next;
    node* random;

    public:
    node(int data1, node*next1, node*random1){
        data = data1;
        next = next1;
        random = random1;
    }
    node(int data1){
        data = data1;
        next = nullptr;
        random = nullptr;
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

node* brute(node* head){
    //step1->take a hashmap and store original and its copy
    map<node*, node*> mpp;
    node* temp = head;
    while(temp != NULL){
        node* copy = new node(temp->data);
        mpp[temp] = copy;
        temp = temp->next;
    }

    //step2->copy the nodes
    node*temp1 = head;
    while(temp1 != NULL){
        node* copyNode = mpp[temp];
        copyNode->next = mpp[temp->next];
        copyNode->random = mpp[temp->random];
        temp = temp->next;
    }
    return mpp[head];
}

node* optimal(node*head){
    //step1-> insert copy nodes in between
    node*temp = head;
    while(temp != NULL){
        node* copyNode = new node(temp->data);
        copyNode->next = temp->next;
        temp->next = copyNode;

        temp = temp->next->next;
    }

    //step2-> connecting random pointer links
    node*temp1 = head;
    while(temp1 != NULL){
        node* copy = temp1->next;
        if(temp1->random){
            copy->random = temp1->random->next;
        }
        else{
            copy->random = NULL;
        }
        temp1 = temp1->next->next;
    }

    //step3-> connecting next pointer links
    //extraction original list and copy list
    node*dummy = new node(-1);
    node* res = dummy;
    node*temp2 = head;
    while(temp2 != NULL){
        res->next = temp2->next;
        temp2->next = temp2->next->next;

        res = res->next;
        temp2 = temp2->next;
    }
     
    return dummy->next;
}

int main()
{
    vector<int>arr = {2,5,8,7};
    node*head = arraytoLL(arr);
    
    traversalofll(head);
    return 0;
}