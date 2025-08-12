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

void anyTraversal(node*root, vector<int>&arr){
    if(root == NULL) return;

    arr.push_back(root->data);
    anyTraversal(root->left,arr);
    anyTraversal(root->right,arr);
}

void inorder(node*root, int &i,vector<int>&arr){
    if(root == NULL) return;

    inorder(root->left,i,arr);

    if(root->data != arr[i]){
        root->data = arr[i];
    }
    i++;

    inorder(root->right,i,arr);
}

void brute(node*root){
    vector<int>arr;
    anyTraversal(root,arr);
    sort(arr.begin(),arr.end()); //now this has become inorder traversal

    int i =0;
    inorder(root,i,arr);
}

void inorderTrav(node*root,node*&first, node*&last, node*&mid, node*&prev){
    if(root == NULL) return;

    inorderTrav(root->left,first,last,mid,prev);

    if(prev != NULL && root->data < prev->data){
        //if first violation
        if(first == NULL){
            first = prev;
            mid = root;
        }
        
        //if second violation
        else{
            last = root;
        }
    }
    prev = root;

    inorderTrav(root->right,first,last,mid,prev);
}

void optimal(node*root){
    node*first;
    node*last;
    node*mid;
    node*prev;

    first = last = mid = NULL;
    prev = new node(INT_MIN);

    inorderTrav(root,first,last,mid,prev);

    if(first && last) swap(first->data, last->data);
    else if(first && mid) swap(first->data, mid->data);
}

int main()
{
    node*root = new node(3);
    root->left = new node(1);
    root->right = new node(4);
    root->right->left = new node(2);

    traversal(root);
    cout<<endl;
    // brute(root);
    optimal(root);
    traversal(root);
    
    return 0;
}