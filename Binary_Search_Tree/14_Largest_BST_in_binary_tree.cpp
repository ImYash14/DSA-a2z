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

bool ValidateBST(node*root,int minval, int maxval){
    if(root == NULL) return true;

    if(root->data <= minval || root->data >= maxval){
        return false;
    }

    return ValidateBST(root->left,minval,root->data)
     && ValidateBST(root->right,root->data,maxval);
}

int countNodes(node* root) {
    if (root == NULL) return 0;
    return 1 + countNodes(root->left) + countNodes(root->right);
}

void traversal(node*root, int &maxcount){
    if(root == NULL) return;

    traversal(root->left,maxcount);

    if(ValidateBST(root,INT_MIN,INT_MAX) == true){
        maxcount = max(countNodes(root),maxcount);
    }

    traversal(root->right,maxcount);
}

int brute(node*root){
   int maxcount = 0;
   traversal(root,maxcount);
   return maxcount;
}

class nodeValue{
    public:
    int minval, maxval, maxsize;
    nodeValue(int minval1, int maxval1, int maxsize1){
        // this->minval = minval;
        // this->maxval = maxval;
        // this->maxsize = maxsize;
        minval = minval1;
        maxval = maxval1;
        maxsize = maxsize1;
    }
};

nodeValue largestBST(node*root){
    if(root == NULL){
        return nodeValue(INT_MAX, INT_MIN, 0);
    }

    //perform preorder
    auto leftnode = largestBST(root->left);
    auto rightnode = largestBST(root->right);

    if(leftnode.maxval < root->data && root->data < rightnode.minval){
        //it is a bst
        return nodeValue(min(leftnode.minval,root->data), max(root->data,rightnode.maxval), 1+leftnode.maxsize+rightnode.maxsize);
    }

    //else if it is not a bst
    return nodeValue(INT_MIN, INT_MAX, max(leftnode.maxsize, rightnode.maxsize));
}

int optimal(node*root){
    return largestBST(root).maxsize;
}

int main()
{
    node*root = new node(20);
    root->left = new node(15);
    root->left->left = new node(14);
    root->left->left->right = new node(17);
    root->left->right = new node(18);
    root->left->right->left = new node(16);
    root->left->right->right = new node(19);
    root->right = new node(40);
    root->right->left = new node(30);
    root->right->right = new node(60);
    root->right->right->left = new node(50);

    // cout<<brute(root);
    cout<<optimal(root);
    
    return 0;
}