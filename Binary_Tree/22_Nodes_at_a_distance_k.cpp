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

void markParent(node*root, map<node*,node*>&parent){
    queue<node*>q;
    q.push(root);
    while(!q.empty()){
        node*temp = q.front();
        q.pop();
        if(temp->left != NULL){
            q.push(temp->left);
            parent[temp->left] = temp;
        }
        if(temp->right != NULL){
            q.push(temp->right);
            parent[temp->right] = temp;
        }
    }
}

vector<int> nodesDistanceK(node*root, node*target, int k){
    map<node*,node*>parent; //(child->parent)
    markParent(root,parent);

    map<node*,bool>vis;
    queue<node*>q;
    q.push(target);
    vis[target] = true;
    int distance =0;
    while(!q.empty()){
        int size = q.size();
        if(distance == k) break;
        distance++;
        for (int i = 0; i < size; i++)
        {
            node*curr = q.front();
            q.pop();

            //for leftwards
            if(curr->left != NULL && !vis[curr->left]){
                q.push(curr->left);
                vis[curr->left] = true;
            }

            //for rightwards
            if(curr->right != NULL && !vis[curr->right]){
                q.push(curr->right);
                vis[curr->right] = true;
            }

            //for upwards
            if(parent[curr] != NULL && !vis[parent[curr]]){
                q.push(parent[curr]);
                vis[parent[curr]] = true;
            }
        }        
    }
    vector<int>ans;
    while(!q.empty()){
        ans.push_back(q.front()->data);
        q.pop();
    }
    return ans;
}

int main()
{
    node*root = new node(3);
    root->left = new node(5);
    root->left->left = new node(6);
    root->left->right = new node(2);
    root->left->right->left = new node(7);
    root->left->right->right = new node(4);
    
    root->right = new node(1);
    root->right->left = new node(0);
    root->right->right = new node(8);

    vector<int>output = nodesDistanceK(root,root->left,2);
    for(auto it : output){
        cout<<it<<" ";
    }
    
    return 0;
}