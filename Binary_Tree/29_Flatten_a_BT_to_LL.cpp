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

void traversalofLL(node*root){
    node*temp = root;
    while(temp != NULL){
        cout<<temp->data<<" ";
        temp = temp->right;
    }
}


void recursive(node*root,node*&prev){
    if(root == NULL) return;

    recursive(root->right,prev);
    recursive(root->left,prev);

    root->right = prev;
    root->left = NULL;
    prev = root;
}

node* bruteRecursive(node*root){
    node*prev = NULL;
    recursive(root,prev);
    return prev; //bc at the end prev will be updated to root
}

node* bruteIterative(node*root){
    stack<node*>st;
    st.push(root);
    while(!st.empty()){
        node*curr = st.top();
        st.pop();

        if(curr->right != NULL){
            st.push(curr->right);
        }
        if(curr->left != NULL){
            st.push(curr->left);
        }

        if(!st.empty()){
            curr->right = st.top();
        }
        curr->left = NULL;
    }
    return root;
}

node*optimalMorris(node*root){
    node*curr = root;
    while(curr != NULL){
        if(curr->left != NULL){
            node*temp = curr->left;
            while(temp->right != NULL){
                temp = temp->right;
            }
            
            temp->right = curr->right;
            curr->right = curr->left;
            curr->left = NULL;
        }
        curr = curr->right;
    }
    return root;
}

int main()
{
    node*root = new node(1);
    root->left = new node(2);
    root->left->left = new node(3);
    root->left->right = new node(4);
    root->right = new node(5);
    root->right->right = new node(6);
    root->right->right->left = new node(7);

    node*ans = bruteRecursive(root);
    // node*ans = bruteIterative(root);
    // node*ans = optimalMorris(root);
    traversalofLL(ans);
    
    return 0;
}