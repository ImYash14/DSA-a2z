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

node*brute(vector<node*>&lists){
    //step1->take an array and put all the ele in it
    vector<int>arr;
    for (int i = 0; i < lists.size(); i++)
    {
        node*temp = lists[i];
        while(temp != NULL){
            arr.push_back(temp->data);
            temp = temp->next;
        }
    }

    //step2->sort the array
    sort(arr.begin(), arr.end());

    //step3->convert arr to ll
    node* head = arraytoLL(arr);

    return head;
    
}

node*merge(node*head1,node*head2){
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

node* better(vector<node*>&lists){
    node* head = lists[0];
    for (int i = 1; i < lists.size(); i++)
    {
        head = merge(head,lists[i]);
    }
    return head;
}

node* optimal(vector<node*>&lists){
    //step1->take a priority queue and add all the heads
    //implementation of min-heap using priority queue
    priority_queue<pair<int,node*>, vector<pair<int,node*>>,greater<pair<int,node*>>> pq;
    for (int i = 0; i < lists.size(); i++)
    {   
        if(lists[i]){
            pq.push({lists[i]->data, lists[i]});
        }
    }

    //step2->take dummy node
    node* dummy = new node(-1);
    node* temp = dummy;

    while(!pq.empty()){
        //step3->pop the min element
        auto it = pq.top();
        pq.pop(); 
        
        //step4->add the popped element to dummy
        temp->next = it.second;
        temp = temp->next;
        
        //step5->add the next element from the ll to pq
        if(it.second->next){
            pq.push({it.second->next->data, it.second->next});
        }

    }
    
    return dummy->next;    
}

int main()
{
    vector<int>arr1 = {2,4,6};
    vector<int>arr2 = {1,5};
    vector<int>arr3 = {1,1,3,7};
    vector<int>arr4 = {8};
    node*head1 = arraytoLL(arr1);
    node*head2 = arraytoLL(arr2);
    node*head3 = arraytoLL(arr3);
    node*head4 = arraytoLL(arr4);

    vector<node*>lists = {head1,head2,head3,head4};
    // node*head = brute(lists);
    // node*head = better(lists);
    node*head = optimal(lists);
    traversalofll(head);
    return 0;
}