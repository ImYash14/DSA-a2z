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

node* findRightmost(node*root){
    while(root->right != NULL){
        root = root->right;
    }
    return root;
}

node* deleter(node*root){
    if(root->left == NULL) return root->right;
    else if(root->right == NULL) return root->left;
    else{
        node*rightchild = root->right; //following method1
        node* rightmost = findRightmost(root->left); //find rightmost in keynode's left
        rightmost->right = rightchild;
        return root->left;
    }
}

node* deleteNodeinBST(node*root, int key){
    if(root == NULL) return NULL;

    if(root->data == key){
        return deleter(root);
    }

    node*temp = root;
    while(temp != NULL){
        if(temp->data < key){ //the keynode is on right subtree
            if(temp->right != NULL && temp->right->data == key){
                temp->right = deleter(temp->right);
                break;
            }
            else temp = temp->right;
        }
        else{//the keynode is on left subtree
            if(temp->left != NULL && temp->left->data == key){
                temp->left = deleter(temp->left);
                break;
            }
            else temp = temp->left;
        }
    }
    return root;
}

int main()
{
    node*root = new node(8);
    root->left = new node(3);
    root->left->left = new node(1);
    root->left->right = new node(6);
    root->left->right->left = new node(4);
    root->left->right->right = new node(7);
    root->right = new node(10);
    root->right->right = new node(14);
    root->right->right->left = new node(13);

    traversal(root);
    cout<<endl;
    node*ans = deleteNodeinBST(root,3);
    traversal(ans);
   
    return 0;
}