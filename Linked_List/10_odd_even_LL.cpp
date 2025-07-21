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

node* oddEvenBrute(node*head){
    vector<int>arr;
    if(head == NULL || head->next == NULL) return head;
    node*temp1 = head;
    //step1->put odd indexed in arr
    while(temp1!= NULL && temp1->next != NULL){
        arr.push_back(temp1->data);
        temp1 = temp1->next->next;
    }
    if(temp1) arr.push_back(temp1->data);

    //step2->put even indexed in arr
    node*temp2 = head->next;
    while(temp2!= NULL && temp2->next != NULL){
        arr.push_back(temp2->data);
        temp2 = temp2->next->next;
    }
    if(temp2) arr.push_back(temp2->data);

    //step3->put data back in ll from arr
    int i=0;
    node*temp = head;
    while(temp != NULL){
        temp->data = arr[i];
        i++;
        temp = temp->next;
    }
    return head;
}

node* oddEvenOptimal(node*head){
    if(head == NULL || head->next == NULL) return head;

    node* odd = head;
    node* even = head->next;
    node* evenHead = head->next;

    while(even != NULL && even-> next != NULL){
        odd->next = odd->next->next;
        even->next = even->next->next;
        odd = odd->next;
        even = even->next;
    }
    odd->next = evenHead;
    return head;
}

int main()
{
    vector<int>arr = {1,3,4,2,5,6};
    node*head = arraytoLL(arr);
    // head = oddEvenBrute(head); //ans= 1 4 5 3 2 6
    head = oddEvenOptimal(head);
    traversalofll(head);
    return 0;
}