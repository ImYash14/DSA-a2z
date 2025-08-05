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

int findheight(node*root){
    if(root == NULL) return 0;

    int lh = findheight(root->left);
    int rh = findheight(root->right);
    //while returning
    return 1+max(lh,rh);
}

int maxi =0;
int brute(node*root){
    if(root == NULL) return 0;

    int lh = findheight(root->left);
    int rh = findheight(root->right);
      
    maxi = max(maxi,lh+rh);

    //for each node
    brute(root->left);
    brute(root->right);

    return maxi;
}

//pass anything to different func that we will be returning by reference
//such that any changes can be reflected in our ans
//for ex, for storing ans we sent vector<int>&ans
int findmax(node*root, int &maximum){
    if(root == NULL) return 0;

    int lh = findmax(root->left,maximum);
    int rh = findmax(root->right,maximum);
    maximum = max(maximum,lh+rh);
    //while returning
    return 1+max(lh,rh);
}

int optimal(node*root){
    int maximum =0;
    findmax(root,maximum);
    return maximum;
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