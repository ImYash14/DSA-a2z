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

void anyTraversal(node*root, vector<int>&arr){
    if(root == NULL) return;

    arr.push_back(root->data);
    anyTraversal(root->left, arr);
    anyTraversal(root->right, arr);
}

int brute(node*root, int k){
    vector<int>arr;
    anyTraversal(root,arr);

    sort(arr.begin(),arr.end());
    return arr[k-1];
}

void inorder(node*root, vector<int>&arr){
    if(root == NULL) return;
    
    inorder(root->left,arr);
    arr.push_back(root->data);
    inorder(root->right,arr);
}

int better(node*root, int k){
    vector<int>arr;
    inorder(root,arr);
    return arr[k-1];
}

int optimal(node*root, int k){
    int count =0;
    node*curr = root;
    while(curr != NULL){
        if(curr->left == NULL){
            count++;
            if(count == k) return curr->data;
            curr = curr->right;
        }
        else{
            node*temp = curr->left;
            while(temp->right != NULL && temp->right != curr){
                temp = temp->right;
            }
            if(temp->right == NULL){
                temp->right = curr;
                curr = curr->left;
            }
            else{
                temp->right = NULL;
                count++;
                if(count == k) return curr->data;
                curr = curr->right;
            } 
        }
    }
    return -1;
}

//for kth largest
void traversal(node*root, int &n){
    if(root == NULL) return;

    n++;
    traversal(root->left,n);
    traversal(root->right,n);
}

int kthlargest(node*root, int k){
    int count =0;
    int n=0;
    traversal(root,n);

    node*curr = root;
    while(curr != NULL){
        if(curr->left == NULL){
            count++;
            if(count == n-k+1) return curr->data;
            curr = curr->right;
        }
        else{
            node*temp = curr->left;
            while(temp->right != NULL && temp->right != curr){
                temp = temp->right;
            }
            if(temp->right == NULL){
                temp->right = curr;
                curr = curr->left;
            }
            else{
                temp->right = NULL;
                count++;
                if(count == n-k+1) return curr->data;
                curr = curr->right;
            } 
        }
    }
    return -1;     
}

int main()
{
    node* root = new node(5);
    root->left = new node(3);
    root->left->left = new node(1);
    root->left->right = new node(4);
    root->left->left->right = new node(2);
    root->right = new node(7);
    root->right->left = new node(6);
    root->right->right = new node(8);

    // cout<<brute(root,3)<<endl;
    // cout<<better(root,3)<<endl;
    // cout<<optimal(root,3)<<endl;
    cout<<kthlargest(root,3);
    
    return 0;
}