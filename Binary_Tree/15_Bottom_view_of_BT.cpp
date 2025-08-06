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

vector<int> bottomView(node*root){
    vector<int>ans;
    if(root == NULL) return ans;
    map<int,int>mpp; //(vertical,node->data)
    queue<pair<node*,int>>q; //(node,vertical)
    q.push({root,0});
    while(!q.empty()){
        auto mark = q.front();
        q.pop();

        int vertical = mark.second;
        node* temp = mark.first;

        mpp[vertical] = temp->data;

        if(temp->left != NULL){
            q.push({temp->left, vertical-1});
        }
        if(temp->right != NULL){
            q.push({temp->right, vertical+1});
        }
    }
    for(auto it : mpp){
        ans.push_back(it.second);
    }
    return ans;
}

int main()
{
    node*root = new node(1);
    root->left = new node(2);
    root->left->left = new node(4);
    root->left->right = new node(5);
    root->left->right->left = new node(8);
    root->left->right->right = new node(9);

    root->right = new node(3);
    root->right->left = new node(6);
    root->right->right = new node(7);

    vector<int>output = bottomView(root);
    for(auto it : output){
        cout<<it<<" ";
    }
    
    return 0;
}