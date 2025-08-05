#include<iostream>
#include<bits/stdc++.h>
using namespace std;

class node{
    public:
    int data;
    node*left;
    node*right;

    node(int data1,node*left1,node*right1){
        data = data1;
        left = left1;
        right = right1;
    }
    node(int data1){
        data = data1;
        left = nullptr;
        right = nullptr;
    }
};

bool isLeaf(node*temp){
    if(temp->left == NULL && temp->right == NULL){
        return true;
    }
    return false;
}

void addLeft(node*root, vector<int>&ans){
    node*curr = root->left;
    while(curr){
        if(!isLeaf(curr)) ans.push_back(curr->data);
        if(curr->left) curr = curr->left;
        else curr = curr->right;
    }
}

void addLeaf(node*root,vector<int>&ans){
    if(isLeaf(root)){
        ans.push_back(root->data);
        return;
    }
    if(root->left) addLeaf(root->left,ans);
    if(root->right) addLeaf(root->right,ans);
}

void addRight(node*root,vector<int>&ans){
    node*curr = root->right;
    stack<int>st;
    while(curr){
        if(!isLeaf(curr)) st.push(curr->data);
        if(curr->right) curr = curr->right;
        else curr = curr->left;
    }
    while(!st.empty()){
        ans.push_back(st.top());
        st.pop();
    }
}

vector<int>boundaryAnticlock(node*root){
    vector<int>ans;
    if(root == NULL) return ans;
    if(!isLeaf(root)) ans.push_back(root->data);

    addLeft(root,ans);
    addLeaf(root,ans);
    addRight(root,ans);

    return ans;
}

int main()
{
    node*root = new node(1);

    root->left = new node(2);
    root->left->left = new node(3);
    root->left->left->right = new node(4);
    root->left->left->right->left = new node(5);
    root->left->left->right->right = new node(6);

    root->right = new node(7);
    root->right->right = new node(8);
    root->right->right->left = new node(9);
    root->right->right->left->left = new node(10);
    root->right->right->left->right = new node(11);

    vector<int>output = boundaryAnticlock(root);
    for(auto it: output){
        cout<<it<<" ";
    }
    
    return 0;
}