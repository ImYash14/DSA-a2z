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

bool isSame(node*root1,node*root2){
    if(root1 == NULL || root2 == NULL) return (root1==root2);

    return (root1->data == root2->data)
        && isSame(root1->left,root2->left)
        && isSame(root1->right,root2->right);
}

int main()
{
    node*root1 = new node(1);
    root1->left = new node(2);
    root1->right = new node(3);
    root1->right->left = new node(4);
    root1->right->right = new node(5);
    
    node*root2 = new node(1);
    root2->left = new node(2);
    root2->right = new node(3);
    root2->right->left = new node(4);
    root2->right->right = new node(5);

    cout<<isSame(root1,root2);

    return 0;
}