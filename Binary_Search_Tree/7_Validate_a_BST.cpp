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

bool fun(node*root, long minval, long maxval){
    if(root == NULL) return true;

    if(root->data <= minval || root->data >= maxval) return false;
    return fun(root->left, minval, root->data) && fun(root->right, root->data, maxval);
}

bool isBST(node*root){
    return fun(root, LONG_MIN, LONG_MAX);
}

int main()
{
    node*root = new node(13);
    root->left = new node(10);
    root->left->left = new node(7);
    root->left->right = new node(12);
    root->left->left->right = new node(9);
    root->left->left->right->left = new node(8);
    root->right = new node(15);
    root->right->left = new node(14);
    root->right->right = new node(17);
    root->right->right->left = new node(16);
    
    cout<<isBST(root);
    
    return 0;
}