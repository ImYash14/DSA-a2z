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

void reversePreorder(node*root, int level, vector<int>&ans){
    if(root == NULL) return;

    if(level == ans.size()){
        ans.push_back(root->data);
    }
    reversePreorder(root->right,level+1,ans);
    reversePreorder(root->left,level+1,ans);
}

vector<int>rightView(node*root){
    vector<int>ans;
    reversePreorder(root,0,ans);
    return ans;
}

void normalPreorder(node*root, int level, vector<int>&ans){
    if(root == NULL) return;

    if(level == ans.size()){
        ans.push_back(root->data);
    }
    normalPreorder(root->left,level+1,ans);
    normalPreorder(root->right,level+1,ans);
}

vector<int>leftView(node*root){
    vector<int>ans;
    normalPreorder(root,0,ans);
    return ans;
}

int main()
{
    node*root = new node(1);
    root->left = new node(2);
    root->left->left = new node(4);
    root->left->right = new node(5);
    root->left->right->left = new node(6);

    root->right = new node(3);
    root->right->right = new node(7);

    // vector<int>output = rightView(root);
    vector<int>output = leftView(root);
    for(auto it : output){
        cout<<it<<" ";
    }
    
    return 0;
}