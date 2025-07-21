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
    node*temp = head;
    int count0 =0;
    int count1 =0;
    int count2 =0;
    //step1
    while(temp != NULL){
        if(temp->data == 0) count0++;
        else if(temp->data == 1) count1++;
        else count2++;

        temp = temp->next;
    }
    //step2
    node*temp1 = head;
    while(temp1 != NULL){
        if(count0){
            temp1->data = 0;
            count0--;
        }
        else if(count1){
            temp1->data = 1;
            count1--;
        }
        else{
            temp1->data =2;
            count2--;
        }
        temp1 = temp1->next;
    }
    return head;
}

node* optimal(node*head){
    if(head == NULL || head-> next == NULL) return head;
    node* zeroHead = new node(-1);
    node* oneHead = new node(-1);
    node* twoHead = new node(-1);
    node*zero = zeroHead;
    node*one = oneHead;
    node*two = twoHead;
    node*temp =head;

    while(temp != NULL){
        if(temp->data == 0){
            zero-> next = temp;
            zero = temp;
        }
        else if(temp->data == 1){
            one->next = temp;
            one = temp;
        }
        else{
            two->next = temp;
            two = temp;
        }
        temp = temp->next;
    }
    if(oneHead->next){
        zero->next = oneHead->next;
    }
    else{
        zero->next = twoHead->next;
    }

    if(twoHead->next){
        one->next = twoHead->next;
    }
    two->next = nullptr;

    return zeroHead->next;
}
int main()
{
    vector<int>arr = {1,0,1,2,0,2,1};
    node*head = arraytoLL(arr);
    // head = brute(head);
    head = optimal(head);
    traversalofll(head);
    return 0;
}