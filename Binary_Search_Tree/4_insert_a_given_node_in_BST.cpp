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

node* insertinBST(node*root, int val){
    if(root == NULL) return new node(val);
    node*temp = root;
    while(true){
        if(temp->data <= val){ //we have to go on right
            if(temp->right != NULL) temp = temp->right;
            else {
                temp->right = new node(val);
                break;
            }
        }
        else{//we have to go on left
            if(temp->left != NULL) temp = temp->left;
            else {
                temp->left = new node(val);
                break;
            }
        }
    }
    return root;
}

int main()
{
    
    return 0;
}
