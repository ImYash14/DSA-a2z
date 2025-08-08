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

int maxWidth(node*root){
    if(root == NULL) return 0;
    int width =0;
    queue<pair<node*,int>>q; //(node,index)
    q.push({root,0});
    while(!q.empty()){
        int size = q.size();
        int mini = q.front().second;
        int first;
        int last;
        for (int i = 0; i < size; i++)
        {
            int currIndex = q.front().second - mini;
            node*temp = q.front().first;
            q.pop();

            if(i == 0) first = currIndex;
            if(i == size-1) last = currIndex;

            if(temp->left != NULL){
                q.push({temp->left, 2*currIndex + 1});
            }
            if(temp->right != NULL){
                q.push({temp->right, 2*currIndex + 2});
            }
        }
        width = max(width, last-first+1);
    }
    return width;
}


int main()
{
    node*root = new node(1);
    root->left = new node(3);
    root->left->left = new node(5);
    root->left->left->left = new node(7);
    root->right = new node(2);
    root->right->right = new node(4);
    root->right->right->right = new node(6);

    cout<<maxWidth(root);
    
    return 0;
}