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

node* brute(node*head1,node*head2){
    if(head1 == NULL || head2 == NULL) return NULL;
    map<node*,int>mpp;
    node* temp = head1;
    while(temp != NULL){
        mpp[temp]++;
        temp = temp->next;
    }

    node*temp1 = head2;
    while(temp1 != NULL){
        if(mpp.find(temp1) != mpp.end()) return temp1;
        temp1 = temp1->next;
    }

    return NULL;
}

node* collisionPoint(node*small, node*large, int d){
    while(d){
        d--;
        large = large->next;
    }
    while(small != large){
        small = small->next;
        large = large->next;
    }
    return small; //return large also
}

node* better(node*head1,node*head2){
    if(head1 == NULL || head2 == NULL) return NULL;
    node*temp1= head1;
    int n1 =0;
    while(temp1 != NULL){
        n1++;
        temp1 = temp1->next;
    }
    node*temp2 = head2;
    int n2=0;
    while(temp2 != NULL){
        n2++;
        temp2 = temp2->next;
    }
    node*t1 = head1;
    node*t2 = head2;
    if(n1<n2){
        return collisionPoint(t1,t2,n2-n1);
    }
    else return collisionPoint(t2,t1,n1-n2);

    return NULL;
}

node* optimal(node*head1, node*head2){
    if(head1 == NULL || head2 == NULL) return NULL;
    node*t1 = head1;
    node*t2 = head2;
    while(t1 != t2){
        t1 = t1->next;
        t2= t2->next;

        if(t1 == t2) return t1;//this also covers the null=null case

        if(t1 == NULL) t1 = head2;
        if(t2 == NULL) t2 = head1;
    }
    return t1;
}
int main()
{
    vector<int> arr1 = {3,1,4,6,2};
    // Create head1
    node* head1 = arraytoLL(arr1);

    // Traverse head1 to reach node with value 4 (intersection start)
    node* temp = head1;
    while (temp && temp->data != 4) {
        temp = temp->next;
    }

    // Create first part of head2
    node* head2 = new node(1);
    head2->next = new node(2);
    head2->next->next = new node(4);
    head2->next->next->next = new node(5);

    // Link the 5 node to node with value 4 in head1 (actual Y)
    node* last = head2->next->next->next;
    last->next = temp;  // ✅ point to same node from head1
    
    
    // node*head = brute(head1,head2);
    node*head = better(head1,head2);
    // node*head = optimal(head1,head2);
    cout<<head->data;
    // traversalofll(head);
    return 0;
}