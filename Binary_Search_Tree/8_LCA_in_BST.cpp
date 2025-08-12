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

int recusiveLCA(node*root, int u, int v){
    if(root == NULL) return -1;

    //if both u & v lie on right of the root
    if(root->data < u && root->data < v){
        return recusiveLCA(root->right,u,v);
    }

    //if both u & v lie on left of the root
    else if(root->data > u && root->data >v){
        return recusiveLCA(root->left,u,v);
    }

    //if they lie on either side or one of them is the root
    return root->data;
}

int iterativeLCA(node*root, int u, int v){
    if(root == NULL) return -1;
    while(root != NULL)
    {
        if(root->data < u && root->data <v){
            root = root->right;
        }
        else if(root->data > u && root->data >v){
            root = root->left;
        }
        else{
            return root->data;
        }
    }
    return -1;
}

int main()
{
    node*root = new node(10);
    root->left = new node(4);
    root->left->left = new node(3);
    root->left->right = new node(8);
    root->left->left->left = new node(1);
    root->left->left->left->right = new node(2);
    root->left->right = new node(8);
    root->left->right->left = new node(6);
    root->left->right->right = new node(9);
    root->left->right->left->left = new node(5);
    root->left->right->left->right = new node(7);
    root->right = new node(13);
    root->right->left = new node(11);
    root->right->right = new node(16);

    cout<<recusiveLCA(root,5,9)<<endl;
    cout<<iterativeLCA(root,5,9);
    
    return 0;
}