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

int brute(node*head){
    map<node*,int> mpp;
    node*temp = head;
    int timer = 0;
    while(temp != NULL){
        if(mpp.find(temp) != mpp.end()){
            int value = mpp[temp];
            return timer-value;
        }
        mpp[temp] = timer;
        timer++;

        temp = temp->next;
    }
    return 0; //if no loop exists
}

int findLen(node*slow,node*fast){
    int count =0;
    while(slow != fast){
        count++;
        fast = fast->next;
    }
    return count;
}

int optimal(node*head){
    node*slow = head;
    node*fast = head;
    while(fast->next != NULL && fast != NULL){
        slow = slow->next;
        fast = fast->next->next;
        if(slow == fast){
            return findLen(slow,fast);
        }
    }
    return 0;
}
int main()
{
    vector<int>arr = {2,5,8,7};
    node*head = arraytoLL(arr);
    
    traversalofll(head);
    return 0;
}