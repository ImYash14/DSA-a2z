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

int findmaxsum(node*root,int &sum){
    if(root == NULL) return 0;

    //ignore the -ve max sums
    int leftsum = max(0,findmaxsum(root->left,sum));
    int rightsum = max(0,findmaxsum(root->right,sum));
    sum = max(sum, root->data + leftsum + rightsum);
    //while returning
    return root->data + max(leftsum,rightsum);//to know which max path to follow
}

int optimal(node*root){
    int sum =0;
    findmaxsum(root,sum);
    return sum;
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

    cout<<optimal(root);
    
    return 0;
}