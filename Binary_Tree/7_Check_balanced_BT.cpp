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

int heightoftree(node*root){
    if(root == NULL) return 0;

    int lh = heightoftree(root->left);
    int rh = heightoftree(root->right);
    //while returning after getting lh and rh
    return 1+max(lh,rh);
}

bool brute(node*root){
    if(root == NULL) return true;

    //calculate height of left and right trees
    int leftheight = heightoftree(root->left);
    int rightheight = heightoftree(root->right);
    //while returning check for this case
    if(abs(rightheight-leftheight) > 1) return false;

    //if the above case is true, keep checking till leaf node
    bool left = brute(root->left);
    bool right = brute(root->right);
    //if at any moment left or right becomes false
    if(!left || !right) return false;

    //else
    return true;
}

int findheight(node*root){
    if(root == NULL) return 0;
    
    int lh = findheight(root->left);
    if(lh == -1) return -1;
    int rh = findheight(root->right);
    if(rh == -1) return -1;

    if(abs(lh-rh) > 1) return -1;

    return 1+max(lh,rh);
}

bool optimal(node*root){
    return findheight(root) != -1;
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

    // cout<<brute(root);
    cout<<optimal(root);
    
    return 0;
}