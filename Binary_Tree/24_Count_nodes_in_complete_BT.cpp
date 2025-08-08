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

void usingDFS(node*root, int &count){
    if(root == NULL) return;
    
    count++;
    usingDFS(root->left,count);
    usingDFS(root->right,count);
}

int brute(node*root){
    int count =0;
    usingDFS(root,count);
    return count;
}

int findheight(node*root){
    if(root == NULL) return 0;

    int left = findheight(root->left);
    int right = findheight(root->right);

    return 1 + max(left,right);
}

int optimal(node*root){
    if(root == NULL) return 0;

    int lh = findheight(root->left);
    int rh = findheight(root->right);

    if(lh == rh) return (1<<(lh+1))-1;

    //else
    return 1 + optimal(root->left) + optimal(root->right);
}

int main()
{
    node*root = new node(1);
    root->left = new node(2);
    root->left->left = new node(4);
    root->left->right = new node(5);
    root->left->left->left = new node(8);
    root->left->left->right = new node(9);
    root->left->right->left = new node(10);
    root->left->right->right = new node(11);
    root->right = new node(3);
    root->right->left = new node(6);
    root->right->right = new node(7);

    // cout<<brute(root);
    cout<<optimal(root);
    
    return 0;
}