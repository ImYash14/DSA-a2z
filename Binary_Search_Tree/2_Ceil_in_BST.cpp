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

int ceilBST(node*root, int key){
    int ceil = -1;
    node*temp = root;
    while(temp != NULL){
        if(temp->data >= key){
            ceil = temp->data;
            temp = temp->left;
        }
        else temp = temp->right;
    }
    return ceil;
}

int main()
{
    node*root = new node(10);
    root->left = new node(5);
    root->left->left = new node(3);
    root->left->right = new node(6);
    root->left->left->left = new node(2);
    root->left->left->right = new node(4);
    root->left->right->right = new node(9);
    root->right = new node(13);
    root->right->left = new node(11);
    root->right->right = new node(14);

    cout<<ceilBST(root,12);
    
    return 0;
}