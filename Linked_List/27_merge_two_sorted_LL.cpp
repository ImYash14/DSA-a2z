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

node* brute(node* head1, node*head2){
    vector<int> arr;
    node*temp1 = head1;
    node*temp2 = head2;

    //step1->put data of 2 LLs in array
    while(temp1 != NULL){
        arr.push_back(temp1->data);
        temp1 = temp1->next;
    }
    while(temp2 != NULL){
        arr.push_back(temp2->data);
        temp2 = temp2->next;
    }
   
    //step2->sort the array
    sort(arr.begin(),arr.end());

    //step3->convert array to LL
    node*head = arraytoLL(arr);

    return head;
}

node* optimal(node*head1, node*head2){
    node*dummyNode = new node(-1);
    node*temp = dummyNode;
    node*t1 = head1;
    node*t2 = head2;
    while(t1 != NULL && t2 != NULL){
        if(t1->data < t2->data){
            temp->next = t1;
            temp = t1;
            t1 = t1->next;
        }
        else{
            temp->next = t2;
            temp = t2;
            t2 = t2->next;
        }
    }
    if(t1) temp->next = t1;
    else temp->next = t2;

    return dummyNode->next;
}

int main()
{
    vector<int>arr1 = {2,4,8,10};
    vector<int> arr2 = {1,3,3,6,11,14};
    node*head1 = arraytoLL(arr1);
    node*head2 = arraytoLL(arr2);
    
    // node*head = brute(head1,head2);
    node*head = optimal(head1,head2);
    traversalofll(head);
    return 0;
}