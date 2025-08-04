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

vector<int> preorder(node*root){
    vector<int>ans;
    if(root == NULL) return ans;

    stack<node*>st;
    st.push(root);
    while(!st.empty()){
        root = st.top();
        st.pop();
        ans.push_back(root->data);
        if(root->right != NULL) st.push(root->right);
        if(root->left != NULL) st.push(root->left);
    }
    return ans;
}

vector<int> inorder(node*root){
    vector<int>ans;
    node*temp = root;
    stack<node*>st;
    while(true){
        if(temp != NULL){
            st.push(temp);
            temp = temp->left;
        }
        else{
            if(st.empty()==true) break;
            temp = st.top();
            st.pop();
            ans.push_back(temp->data);
            temp = temp->right;
        }
    }
    return ans;
}

vector<int> postorder2stack(node*root){
    vector<int>ans;
    if(root == NULL) return ans;
    stack<node*>st1;
    stack<node*>st2;
    st1.push(root);
    while(!st1.empty()){
        root = st1.top();
        st2.push(root);
        st1.pop();

        if(root->left != NULL) st1.push(root->left);
        if(root->right != NULL) st1.push(root->right);
    }
    while(!st2.empty()){
        ans.push_back(st2.top()->data);
        st2.pop();
    }
    return ans;
}

vector<int> postorder1stack(node*root){
    vector<int>ans;
    stack<node*>st;
    node*curr = root;
    while(curr != NULL || !st.empty()){
        if(curr != NULL){
            st.push(curr);
            curr = curr->left; //keep going left till null
        }
        else{
            node*temp = st.top()->right;
            if(temp == NULL){
                temp = st.top();
                st.pop();
                ans.push_back(temp->data);
                //check for the root of popped element
                while(!st.empty() && temp == st.top()->right){
                    temp = st.top();
                    st.pop();
                    ans.push_back(temp->data);
                }
            }
            else curr = temp; //if temp != NULL
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
    root->left->right->left = new node(8);

    root->right->left = new node(6);
    root->right->right = new node(7);
    root->right->right->left = new node(9);
    root->right->right->right = new node(10);

    // vector<int>output = preorder(root);
    // vector<int>output = inorder(root);
    // vector<int>output = postorder2stack(root);
    vector<int>output = postorder1stack(root);
    for(auto it : output){
        cout<<it<<" ";
    }

    return 0;
}