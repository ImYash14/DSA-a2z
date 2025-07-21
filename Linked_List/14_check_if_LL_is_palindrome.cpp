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

bool brute(node*head){
    if(head == NULL || head->next == NULL) return true;
    stack<int>st;
    node*temp = head;
    while(temp != NULL){
        st.push(temp->data);
        temp = temp->next;
    }

    node*temp1 = head;
    while(temp1 != NULL){
        if(temp1->data == st.top()){
            st.pop();
        }
        else return false;
        temp1 = temp1->next;
    }
    return true;
}

node* reverseLL(node*head){
    if(head == NULL || head->next == NULL) return head;
    node* newHead = reverseLL(head->next);
    node*front = head->next;
    front->next = head;
    head->next = nullptr;

    return newHead;
}

bool optimal(node*head){
    if(head == NULL || head->next == NULL) return true;
    //step1->find the second half
    node*slow = head;
    node*fast = head;
    while(fast->next != NULL && fast->next->next != NULL){
        slow= slow->next;
        fast = fast->next->next;
    }

    //step2->reverse second half
    node* newHead = reverseLL(slow->next);

    //step3->compare first and second half
    node* p1 = head;
    node* p2 = newHead;
    while(p2 != NULL){
        if(p1->data != p2->data){
            reverseLL(newHead);
            return false;
        }
        p1 = p1->next;
        p2 = p2->next;
    }
    reverseLL(newHead);
    return true;
}

int main()
{
    vector<int>arr = {1,2,3,2,1};
    node*head = arraytoLL(arr);
    
    // bool ans = brute(head);
    bool ans = optimal(head);
    cout<<ans; //if true->1 else 0
    // traversalofll(head);
    return 0;
}