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

bool getPath(node*root,vector<int>&ans, int val){
    if(root == NULL) return false;

    ans.push_back(root->data);
    if(root->data == val) return true;
    
    if(getPath(root->left,ans,val) || getPath(root->right,ans,val)){
        return true;
    }

    //else
    ans.pop_back();
    return false;
}

vector<int> root2node(node*root, int val){
    vector<int>ans;
    if(root == NULL) return ans;
    getPath(root,ans,val);
    return ans;
}

int main()
{
    node*root = new node(1);
    root->left = new node(2);
    root->left->left = new node(4);
    root->left->right = new node(5);
    root->left->right->left = new node(6);
    root->left->right->right = new node(7);
    root->right = new node(3);

    vector<int>output = root2node(root,7);
    for(auto it : output){
        cout<<it<<" ";
    }
    
    return 0;
}