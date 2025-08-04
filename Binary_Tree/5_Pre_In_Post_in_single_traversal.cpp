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

vector<vector<int>> preinpost(node*root){
    vector<vector<int>>ans;
    if(root == NULL) return ans;
    stack<pair<node*,int>>st; //<node,count>
    vector<int> preorder,inorder,postorder;

    st.push({root,1});
    while(!st.empty()){
        auto it = st.top();
        st.pop();

        //for preorder
        if(it.second == 1){
            preorder.push_back(it.first->data);
            it.second++;
            st.push(it);
            if(it.first->left != NULL){
                st.push({it.first->left,1});
            }
        }

        //for inorder
        else if(it.second == 2){
            inorder.push_back(it.first->data);
            it.second++;
            st.push(it);
            if(it.first->right != NULL){
                st.push({it.first->right,1});
            }
        }

        //for postorder
        else{
            postorder.push_back(it.first->data);
        }
    }
    ans.push_back(preorder);
    ans.push_back(inorder);
    ans.push_back(postorder);
    return ans;
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

    vector<vector<int>>output = preinpost(root);
    for(auto it : output){
        for(int num : it){
            cout<<num<<" ";
        }
        cout<<endl;
    }

    return 0;
}