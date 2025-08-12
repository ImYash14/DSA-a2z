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

    cout<<root->data<<" ";
    traversal(root->left);
    traversal(root->right);
}

node* brutebuildBST(vector<int>&preorder){
    node*root = new node(preorder[0]);
    node*temp = root;
    for (int i = 1; i < preorder.size(); i++)
    {
        if(preorder[i] < temp->data){
            node* newnode = new node(preorder[i]);
            temp->left = newnode;
            temp = newnode;
        }
        else{
            node*newnode = new node(preorder[i]);
            temp->right = newnode;
            temp = newnode;
        }
    }
    return root;

    //correct code
    // TreeNode* insert(TreeNode*root, int data){
    //     if(root == NULL) return new TreeNode(data);

    //     if(data < root->val){
    //         root->left = insert(root->left,data);
    //     }
    //     else root->right = insert(root->right, data);

    //     return root;
    // }
    // TreeNode* bstFromPreorder(vector<int>& preorder) {
    //     TreeNode* root = nullptr;
    //     for(int i =0; i<preorder.size(); i++){
    //         root = insert(root,preorder[i]);
    //     }
    //     return root;
    // }
}

node* buildtree(vector<int>&preorder, int prestart, int preend, vector<int>&inorder,int instart, int inend,map<int,int>&mpp){
    if(prestart > preend || instart > inend) return NULL;

    node*root = new node(preorder[prestart]);
    int inroot = mpp[root->data];
    int numsleft = inroot - instart;

    root->left = buildtree(preorder,prestart+1,prestart+numsleft,inorder,instart,inroot-1,mpp);
    root->right = buildtree(preorder,prestart+numsleft+1,preend,inorder,inroot+1,inend,mpp);

    return root;
}

node* betterbuildBST(vector<int>&preorder){
    vector<int> inorder;
    for (int i = 0; i < preorder.size(); i++)
    {
        inorder.push_back(preorder[i]);
    }

    sort(inorder.begin(),inorder.end());
    map<int,int>mpp;
    for (int i = 0; i < inorder.size(); i++)
    {
        mpp[inorder[i]] = i;
    }
    
    node*root = buildtree(preorder,0,preorder.size()-1,inorder,0,inorder.size()-1,mpp);
    return root;
}

node* build(vector<int>&arr, int &i, int ub){
    if(i == arr.size() || arr[i] > ub) return NULL;

    node*root = new node(arr[i++]);
    root->left = build(arr,i,root->data);
    root->right = build(arr,i,ub);

    return root;
}

node* optimalbuildBST(vector<int>&preorder){
    int i =0;
    node*root = build(preorder,i,INT_MAX);
    return root;
}

int main()
{
    vector<int> preorder = {8,5,1,7,10,12};
    // node*root = brutebuildBST(preorder);
    // node*root = betterbuildBST(preorder);
    node*root = optimalbuildBST(preorder);
    traversal(root);
    
    return 0;
}