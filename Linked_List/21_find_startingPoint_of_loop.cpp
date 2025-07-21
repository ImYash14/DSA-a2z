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
    map<node*,int> mpp;
    node*temp = head;
    while(temp != NULL){
        if(mpp.find(temp) != mpp.end()){
            return temp;
        }
        mpp[temp]++;
        temp = temp->next;
    }
    return NULL;
}

node* optimal(node* head){
    //step1->detection of loop
    node*slow = head;
    node*fast = head;
    while(fast != NULL && fast->next != NULL){
        slow = slow->next;
        fast = fast->next->next;

        if(slow == fast){ //collisionPoint
            slow = head; //move slow or fast to head
            while(slow != fast){
                slow = slow->next;
                fast = fast->next;
            }
            return slow; //they will surely collide, return slow or fast
        }
    }
    return NULL;
}

int main()
{
    vector<int>arr = {2,5,8,7};
    node*head = arraytoLL(arr);
    
    traversalofll(head);
    return 0;
}