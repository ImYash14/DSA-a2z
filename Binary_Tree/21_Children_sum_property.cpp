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

void traversal(node*root){
    if(root == NULL) return;

    traversal(root->left);
    cout<<root->data<<" ";
    traversal(root->right);
}

void changetree(node*root){
    if(root == NULL) return;

    //while going down
    int child = 0;
    if(root->left != NULL) child += root->left->data;
    if(root->right != NULL) child += root->right->data;

    if(child >= root->data) root->data = child;
    else{
        if(root->left) root->left->data = root->data;
        if(root->right) root->right->data = root->data;
    }

    changetree(root->left);
    changetree(root->right);

    //while returning
    int total =0;
    if(root->left) total += root->left->data;
    if(root->right) total += root->right->data;
    //make sure it is not a leaf node
    if(root->left != NULL || root->right != NULL) root->data = total;
}

int main()
{
    node*root = new node(2);
    root->left = new node(35);
    root->left->left = new node(2);
    root->left->right = new node(3);
    root->right = new node(10);
    root->right->left = new node(5);
    root->right->right = new node(2);

    changetree(root);
    traversal(root);
    
    return 0;
}