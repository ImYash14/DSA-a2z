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

vector<vector<int>> levelOrder(node*root){
    vector<vector<int>>ans;
    if(root == NULL) return ans;

    queue<node*>q;
    q.push(root);
    while(!q.empty()){
        int size = q.size();
        vector<int>level;
        for (int i = 0; i < size; i++)
        {
            node*temp = q.front();
            q.pop();
            if(temp->left != NULL) q.push(temp->left);
            if(temp->right != NULL) q.push(temp->right);
            level.push_back(temp->data);
        }
        ans.push_back(level);
    }
    return ans;
}

int main()
{
    node*root = new node(1);
    root->left = new node(2);
    root->right = new node(3);

    root->left->left = new node(4);
    root->left->right = new node(5);
    root->left->right->left = new node(8);

    root->right->left = new node(6);
    root->right->right = new node(7);
    root->right->right->left = new node(9);
    root->right->right->right = new node(10);

    vector<vector<int>>output = levelOrder(root);
    for(auto it: output){
        for(int num : it){
            cout<<num<<" ";
        }
    }
    
    return 0;
}