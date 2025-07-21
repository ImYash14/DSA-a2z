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

node* brute(node*head,int n){
    //step1-> count the elements
    node*temp = head;
    int count =0;
    while(temp!= NULL){
        count++;
        temp = temp->next;
    }
    if(count == n){
        node* newHead = head->next;
        free(head);
        return newHead;
    }

    //step2->stop before the element which is to be deleted
    int res = count-n;
    node*temp1 = head;
    while(temp1 != NULL){
        res--;
        if(res == 0) break;
        temp1 = temp1->next;
    }
    node* delNode = temp1->next;
    temp1->next = temp1->next->next;
    free(delNode);
    return head;
}

node* optimal(node*head, int n){
    node*fast = head;
    for (int i = 0; i < n; i++)
    {
        if (fast == NULL) return head;
        fast = fast->next;
    }
    if(fast == NULL){
        node* newHead = head->next;
        free(head);
        return newHead;
    }
    node*slow = head;
    while(fast->next != NULL){
        slow = slow->next;
        fast = fast->next;
    }

    node* delNode = slow->next;
    slow->next = slow->next->next;
    free(delNode);

    return head;   
}
int main()
{
    vector<int>arr = {1,2,3,4,5};
    node*head = arraytoLL(arr);
    // head = brute(head,2);
    head = optimal(head,5);
    traversalofll(head);
    return 0;
}