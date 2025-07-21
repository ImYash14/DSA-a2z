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

node* add2num(node*head1, node*head2){
    node*temp1 = head1;
    node*temp2 = head2;
    node* dummyNode = new node(-1);
    node* current = dummyNode;
    int carry= 0;

    while(temp1 != NULL || temp2!= NULL){
        //addition
        int sum = carry;
        if(temp1) sum = sum+ temp1->data;
        if(temp2) sum = sum+ temp2->data;

        //storing the sum
        node* newNode = new node(sum%10);
        current->next = newNode;
        current = current->next;
        carry = sum/10;

        //moving the temp1 and temp2
        if(temp1) temp1= temp1->next;
        if(temp2) temp2= temp2->next;
    }
    //if there is still a carry
    if(carry){
        node* newNode = new node(carry);
        current->next = newNode;
    }

    return dummyNode->next;
}

int main()
{

    vector<int>arr1 = {3,5}; //num1 = 53
    vector<int>arr2 = {4,5,9,9}; //num2 = 9954
    node*head1 = arraytoLL(arr1);
    node*head2 = arraytoLL(arr2);
    
    node* head = add2num(head1,head2);
    //ans = 10007
    traversalofll(head);
    return 0;
}