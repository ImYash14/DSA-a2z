#include<iostream>
#include<bits/stdc++.h>
using namespace std;

class node{
    public:
    int data;
    node* next;
    node* back;

    node(int data1, node*next1, node*back1){
        data = data1;
        next = next1;
        back = back1;
    }
    node(int data1){
        data = data1;
        next = nullptr;
        back = nullptr;
    }
};

node* arr2DLL(vector<int>&arr){
    node*head = new node(arr[0]);
    node*prev = head;
    for (int i = 1; i < arr.size(); i++)
    {
        node*temp = new node(arr[i],nullptr,prev);
        prev->next= temp;
        prev = temp;
    }
    return head;
}

void traversal(node*head){
    node*temp = head;
    while(temp){
        cout<<temp->data<<" ";
        temp = temp->next;
    }
}

vector<pair<int,int>> brute(node*head, int sum){
    node*temp1 = head;
    vector<pair<int,int>>ans;
    while(temp1 != NULL){
        node*temp2 = temp1->next;
        while(temp2 != NULL && temp1->data + temp2->data <= sum){
            if(temp1->data + temp2->data == sum){
                ans.push_back({temp1->data,temp2->data});
            }
            temp2 = temp2->next;
        }
        temp1 = temp1->next;
    }
   
    return ans;
}

vector<vector<int>> optimal(node*head, int sum){
    set<vector<int>> st;
    node*high = head;
    while(high -> next != NULL){
        high = high -> next;
    }
    node*low = head;
    while(low->data < high->data){
        if(low->data + high->data == sum){
            st.insert(low->data,high->data);
            low = low->next;
            high = high->back;
        }
        else if(low->data + high->data <sum) low = low->next;
        else high = high->back;
    }

    vector<vector<int>> ans(st.begin(),st.end());
    return ans;
}

int main()
{
    vector<int>arr = {1,2,3,4,9};
    node*head = arr2DLL(arr);
    
    // vector<vector<int>> result = brute(head,5);
    vector<vector<int>> result = optimal(head,5);
    for(auto it: result){
        for(int num : it){
            cout<<num<<" ";
        }
    }

    traversal(head);
    return 0;
}