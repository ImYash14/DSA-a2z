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

int successor(node*root, int val){
    int ans = -1;
    node*temp = root;
    while(temp != NULL){
        if(temp->data > val){
            ans = temp->data;
            temp = temp->left;
        }
        else temp = temp->right;
    }
    return ans;
}

int predecessor(node*root, int val){
    int ans = -1;
    node*temp = root;
    while(temp != NULL){
        if(temp->data < val){
            ans = temp->data;
            temp = temp->right;
        }
        else temp = temp->left;
    }
    return ans;
}

int main()
{
    node*root = new node(5);
    root->left = new node(3);
    root->left->left = new node(2);
    root->left->right = new node(4);
    root->left->left->left = new node(1);
    root->right = new node(7);
    root->right->left = new node(6);
    root->right->right = new node(9);
    root->right->right->left = new node(8);
    root->right->right->right = new node(10);

    cout<<successor(root,8)<<endl;
    cout<<predecessor(root,8);
    
    return 0;
}