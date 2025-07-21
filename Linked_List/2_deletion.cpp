#include<iostream>
#include<bits/stdc++.h>
using namespace std;

class node{
    public:
    int data;
    node*next;

    node(int data1, node*next1){
        data = data1;
        next = next1;
    }
    node(int data1){
        data = data1;
        next = nullptr;
    }

};

node* arr2ll(vector<int>&arr){
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

void traversal(node*head){
    node*temp = head;
    while (temp)
    {
        cout<<temp->data<<" ";
        temp = temp->next;
    }
    
}

node* deleteHead(node*head){
    if(head == NULL) return head;
    node*temp = head;
    head = head->next;
    free(temp);
    return head;
}

node*deleteTail(node*head){
    if(head==NULL || head->next == NULL) return NULL;
    node*temp = head;
    while(temp->next->next != NULL){
        temp = temp->next;
    }
    free(temp->next);
    temp->next = nullptr;
    return head;
}

node* deleteKth(node*head, int k){
    if(head == NULL) return head;
    if(k == 1){
        node*temp = head;
        head = head->next;
        free(temp);
        return head;
    }

    int count =0;
    node*prev = NULL;
    node*temp = head;
    while(temp != NULL){
        count++;
        if(count == k){
            prev->next = prev->next->next;
            free(temp);
            break;
        }
        prev = temp;
        temp = temp->next;
    }
    return head;
}

node* deleteElement(node*head, int element){
    if(head == NULL) return head;
    if(head->data == element){
        node*temp = head;
        head = head->next;
        free(temp);
        return head;
    }

    node*prev = NULL;
    node*temp = head;
    while(temp != NULL){      
        if(temp->data == element){
            prev->next = prev->next->next;
            free(temp);
            break;
        }
        prev = temp;
        temp = temp->next;
    }
    return head;
}

int main()
{
    vector<int>arr = {1,2,3,4,5};
    node*head = arr2ll(arr);
    
    // head = deleteHead(head);
    // head = deleteTail(head);
    // head = deleteKth(head,4);
    head = deleteElement(head,15);
    traversal(head);
        
    return 0;
}