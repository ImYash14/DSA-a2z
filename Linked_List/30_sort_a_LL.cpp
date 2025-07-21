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
    //step1->take an array and put the elements in arr
    vector<int>arr;
    node*temp = head;
    while(temp != NULL){
        arr.push_back(temp->data);
        temp= temp->next;
    }

    //step2->sort the arr
    sort(arr.begin(), arr.end());

    //step3->we can convert the arr to a new LL
    //or we can do it in-place
    node*temp1 = head;
    int i =0;
    while(temp1 != NULL){
        temp1->data = arr[i];
        i++;
        temp1 = temp1->next;
    }
    return head;
}

node* findMid(node* head){
    node*slow = head;
    node*fast = head->next;
    while(fast != NULL && fast->next != NULL){
        slow = slow->next;
        fast = fast->next->next;
    }
    return slow;
}

node* mergeLL(node*head1, node*head2){
    node* dummy = new node(-1);
    node* temp = dummy;
    node* t1 = head1;
    node* t2 = head2;
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

    return dummy->next;
}

node* optimal(node*head){
    if(head == NULL || head->next == NULL){
        return head; //base case 
    }

    //step1->find mid
    node*mid = findMid(head);

    //step2->divide in left and right half
    node*leftHead = head;
    node*rightHead = mid->next;
    mid->next = NULL;
    
    leftHead = optimal(leftHead);
    rightHead = optimal(rightHead);

    //step3->backtracking happens when merging
    head = mergeLL(leftHead,rightHead);

    return head;
}

int main()
{
    vector<int>arr = {3,4,2,1,5};
    node*head = arraytoLL(arr);
    // head = brute(head);
    head = optimal(head);
    traversalofll(head);
    return 0;
}