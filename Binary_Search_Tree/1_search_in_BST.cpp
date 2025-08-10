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

node* bst(node*root, int target){
    node*temp = root;
    while(temp != NULL){
        if(temp->data == target) return temp;
        else if(temp->data < target){
            temp = temp->right;
        }
        else temp = temp->left;
    }
    return NULL;
}

int main()
{
    node*root = new node(8);
    root->left = new node(3);
    root->left->left = new node(1);
    root->left->right = new node(6);
    root->left->right->left = new node(4);
    root->left->right->right = new node(7);
    root->right = new node(10);
    root->right->right = new node(14);
    root->right->right->left = new node(13);

    node*ans = bst(root,11);
    cout<<ans->data;
    
    return 0;
}