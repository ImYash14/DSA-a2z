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

vector<int> morrisinorder(node*root){
    vector<int>ans;
    node*curr = root;
    while(curr != NULL){
        //case1
        if(curr->left == NULL){
            ans.push_back(curr->data);
            curr = curr->right;
        }

        else if(curr->left != NULL){
            //case2->find the rightmost node on left
            node* temp = curr->left;
            while(temp->right != NULL && temp->right != curr){
                temp = temp->right;
            }

            //if there is no thread,connect the rightmost node on left to curr
            //and move to left
            if(temp->right == NULL){
                temp->right = curr;
                curr = curr->left;
            }

            //if there is already a thread, then remove it and move right
            else{//if temp->right = curr
                temp->right = NULL;
                ans.push_back(curr->data);
                curr = curr->right;
            }
        }
    }
    return ans;
}

vector<int> morrispreorder(node*root){
    vector<int>ans;
    node*curr = root;
    while(curr != NULL){
        if(curr->left == NULL){
            ans.push_back(curr->data);
            curr = curr->right;
        }
        else if(curr->left != NULL){
            node*temp= curr->left;
            while(temp->right != NULL && temp->right != curr){
                temp = temp->right;
            }

            //if there is no thread,connect the rightmost node on left to curr
            //and move to left, while doing this add to the ans because preorder(root left right)
            if(temp->right == NULL){
                temp->right = curr;
                ans.push_back(curr->data);
                curr = curr->left;
            }
             //if there is already a thread, then remove it and move right
            else if(temp->right == curr){
                temp->right = NULL;
                curr = curr->right;
            }
        }
    }
    return ans;
}

int main()
{
    node*root = new node(1);
    root->left = new node(2);
    root->right = new node(3);
    root->left->left = new node(4);
    root->left->right = new node(5);
    root->left->right->right = new node(6);

    // vector<int>output = morrisinorder(root);
    vector<int>output = morrispreorder(root);
    for(auto it : output){
        cout<<it<<" ";
    }
    
    return 0;
}
