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

bool root2node(node*root,vector<int>&ans, int val){
    if(root == NULL) return false;

    ans.push_back(root->data);
    if(root->data == val) return true;

    if(root2node(root->left,ans,val) || root2node(root->right,ans,val)){
        return true;
    }

    //else
    ans.pop_back();
    return false;
} 

int brute(node*root, int val1, int val2){
    vector<int>ans1;
    root2node(root,ans1,val1);
    vector<int>ans2;
    root2node(root,ans2,val2);

    int i=0,j=0;
    while(i<ans1.size() && j<ans2.size()){
        if(ans1[i] == ans2[j]){
            i++;
            j++;
        }
        else{
            return ans1[i-1]; //or ans2[j-1]
        }
    }
    return ans1[i-1]; // or ans2[j-1],because one of them got exhausted
}

node* optimal(node*root, node*a, node*b){
    if(root == NULL || root == a || root == b){
        return root;
    }

    node*l = optimal(root->left,a,b);
    node*r = optimal(root->right,a,b);

    if(l == NULL) return r;
    else if(r == NULL) return l;
    else return root;//both l and r are not null
}

int main()
{
    node*root = new node(1);
    root->left = new node(2);
    root->left->left = new node(4);
    root->left->right = new node(5);
    root->left->right->left = new node(6);
    root->left->right->right = new node(7);
    
    root->right = new node(3);
    root->right->left = new node(8);
    root->right->right = new node(9);

    cout<<brute(root,5,7);
    
    return 0;
}