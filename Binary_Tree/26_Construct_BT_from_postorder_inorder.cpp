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

node*fun(vector<int>&postorder,int postStart,int postEnd, vector<int>&inorder,int inStart,int inEnd,map<int,int>&mpp){
    if(postStart > postEnd || inStart > inEnd) return NULL;

    node*root = new node(postorder[postEnd]);
    int inroot = mpp[root->data]; //find the index of root in inorder
    int numsleft = inroot-inStart; //find how many on left of root in inorder

    root->left = fun(postorder,postStart,postStart+numsleft-1, inorder,inStart,inroot-1,mpp);
    root->right = fun(postorder,postStart+numsleft,postEnd-1, inorder,inroot+1,inEnd,mpp);

    return root;

}

node*buildTree(vector<int>&inorder, vector<int>&postorder){
    map<int,int>mpp;
    for (int i = 0; i < inorder.size(); i++)
    {
        mpp[inorder[i]] = i;
    }

    node*root = fun(postorder,0,postorder.size()-1,inorder,0,inorder.size()-1,mpp);
    return root;
}

int main()
{
    vector<int>inorder = {40,20,50,10,60,30};
    vector<int>postorder = {40,50,20,60,30,10};

    node*root = buildTree(inorder,postorder);
    traversal(root);
    
    return 0;
}