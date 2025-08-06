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

bool check(node*leftroot,node*rightroot){
    if(leftroot == NULL || rightroot == NULL){
        return (leftroot == rightroot);
    }

    if(leftroot->data != rightroot->data) return false;
    return check(leftroot->left, rightroot->right) && check(leftroot->right, rightroot->left);
}

bool isSymmetrical(node*root){
    return (root == NULL) || check(root->left, root->right);
}

int main()
{
    //symmetric tree
    // node*root = new node(1);
    // root->left = new node(2);
    // root->right = new node(2);
    // root->left->left = new node(3);
    // root->left->right = new node(4);
    // root->right->left = new node(4);
    // root->right->right = new node(3);

    //non symmetric tree
    node*root = new node(1);
    root->left = new node(2);
    root->right = new node(2);
    root->left->right = new node(3);
    root->right->right = new node(3);

    cout<<isSymmetrical(root);
    
    return 0;
}