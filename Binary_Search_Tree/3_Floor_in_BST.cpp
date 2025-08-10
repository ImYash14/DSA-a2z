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

int floorBST(node*root, int key){
    int floor = -1;
    node*temp = root;
    while(temp != NULL){
        if(temp->data <= key){
            floor = temp->data;
            temp = temp->right;
        }
        else temp = temp->left;
    }
    return floor;
}

int main()
{
    node*root = new node(10);
    root->left = new node(5);
    root->left->left = new node(2);
    root->left->right = new node(6);
    root->right = new node(15);

    cout<<floorBST(root,14);
    
    return 0;
}