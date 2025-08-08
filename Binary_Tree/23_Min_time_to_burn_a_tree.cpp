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

node* markParent(node*root,map<node*,node*>&parent, int start){
    queue<node*>q;
    q.push(root);
    node*startnode;
    while(!q.empty()){
        node*temp = q.front();
        q.pop();
        if(temp->data == start) startnode = temp;

        if(temp->left != NULL){
            q.push(temp->left);
            parent[temp->left] = temp;
        }
        if(temp->right != NULL){
            q.push(temp->right);
            parent[temp->right] = temp;
        }
    }
    return startnode;
}

int burnTree(node*root,int start){
    map<node*,node*>parent;
    node* startnode = markParent(root,parent,start);
    map<node*,int>vis;
    queue<node*>q;
    q.push(startnode);
    vis[startnode] = 1;
    int timer =0;
    while(!q.empty()){
        int size = q.size();
        int burnt =0;
        for (int i = 0; i < size; i++)
        {
            node*curr = q.front();
            q.pop();

            if(curr->left != NULL && !vis[curr->left]){
                burnt =1;
                q.push(curr->left);
                vis[curr->left] = 1;
            }
            if(curr->right != NULL && !vis[curr->right]){
                burnt = 1;
                q.push(curr->right);
                vis[curr->right] = 1;
            }
            if(parent[curr] != NULL && !vis[parent[curr]]){
                burnt =1;
                q.push(parent[curr]);
                vis[parent[curr]] =1;
            }
        }
        if(burnt) timer++;
    }
    return timer;
}

int main()
{
    node*root = new node(1);
    root->left = new node(2);
    root->left->left = new node(4);
    root->left->left->right = new node(7);
    root->right = new node(3);
    root->right->left = new node(5);
    root->right->right = new node(6);

    cout<<burnTree(root,2);
    
    return 0;
}