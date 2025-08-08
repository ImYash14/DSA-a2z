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

string serializeBT(node*root){
    if(root == NULL) return "";
    queue<node*>q;
    q.push(root);
    string s = "";
    while(!q.empty()){
        node*temp = q.front();
        q.pop();

        if(temp == NULL) s.append("#,");
        else s.append(to_string(temp->data) + ',');

        if(temp != NULL){
            q.push(temp->left);
            q.push(temp->right);
        }
    }
    return s;
}

node* deserializeBT(string data){
    if(data.size() == 0) return NULL;

    stringstream s(data);
    string str;
    getline(s,str,',');
    node* root = new node(stoi(str));

    queue<node*>q;
    q.push(root);
    while(!q.empty()){
        node* temp = q.front();
        q.pop();

        //for left child
        getline(s,str,',');
        if(str == "#") temp->left = NULL;
        else{
            node* leftnode = new node(stoi(str));
            temp->left = leftnode;
            q.push(leftnode);
        }

        //for right child
        getline(s,str,',');
        if(str == "#") temp->right = NULL;
        else{
            node* rightnode = new node(stoi(str));
            temp->right = rightnode;
            q.push(rightnode);
        }
    }
    return root;
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

    string ans = serializeBT(root);
    cout<<ans<<endl;
    node*tree = deserializeBT(ans);
    traversal(tree);
    
    return 0;
}