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

void traversal(node*root){
    if(root == NULL) return;

    traversal(root->left);
    cout<<root->data<<" ";
    traversal(root->right);
}

node* fun(vector<int>&preorder, int preStart, int preEnd, vector<int>&inorder,int inStart,int inEnd, map<int,int>&mpp){
    if(preStart > preEnd || inStart > inEnd) return NULL;

    node*root = new node(preorder[preStart]);
    int inroot = mpp[root->data]; //find the index of root in inorder
    int numsleft = inroot - inStart; //find how many on the left of root in inorder

    root->left = fun(preorder,preStart+1,preStart+numsleft, inorder,inStart,inroot-1,mpp);
    root->right = fun(preorder,preStart+numsleft+1,preEnd, inorder,inroot+1,inEnd, mpp);

    return root;

}

node* buildTree(vector<int>&preorder, vector<int>&inorder){
    map<int,int>mpp;
    for (int i = 0; i < inorder.size(); i++)
    {
        mpp[inorder[i]] = i;
    }

    node* root = fun(preorder,0,preorder.size()-1,inorder,0,inorder.size()-1, mpp);
    return root;
}

int main()
{
    vector<int>inorder = {40,20,50,10,60,30};
    vector<int>preorder = {10,20,40,50,30,60};

    node*root = buildTree(preorder,inorder);
    traversal(root);

    return 0;
}