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

class bruteBSTIterator{
    private:
    vector<int>arr;
    int i =0;
    void inorder(node*root, vector<int>&arr){
        if(root == NULL) return;

        inorder(root->left,arr);
        arr.push_back(root->data);
        inorder(root->right,arr);
    }

    public:
    bruteBSTIterator(node*root){
        inorder(root,arr);
    }

    int next(){
        int ans = arr[i];
        i++;
        return ans;
    }

    int prev(){
        if(i>0) i--;
        return arr[i];
    }

    bool hasnext(){
        return i<arr.size();
    }

};

class optimalBSTIterator{
    private:
    stack<node*>st1;
    stack<node*>st2;

    void pushallonleft(node*temp){
        while(temp != NULL){
            st1.push(temp);
            temp = temp->left;
        }
    }

    void pushallonright(node*temp){
        while(temp != NULL){
            st2.push(temp);
            temp = temp->right;
        }
    }

    public:
    optimalBSTIterator(node*root){
        pushallonleft(root);
        pushallonright(root);
    }

    int next(){//left root right
        node*temp = st1.top();
        st1.pop();
        pushallonleft(temp->right);
        return temp->data;
    }

    int prev(){//right root left
        node*temp = st2.top();
        st2.pop();
        pushallonright(temp->left);
        return temp->data;
    }

    bool hasnext(){
        return !st1.empty();
    }

    bool hasprev(){
        return !st2.empty();
    }

};

class BSTIterator{
    private:
    stack<node*>st;
    bool reverse = true; 
    //if true then next()
    //if false then prev()

    void pushall(node*temp){
        while(temp != NULL){
            st.push(temp);
            if(reverse) temp = temp->left; //next
            else temp = temp->right; //prev
        }
    }

    public:
    BSTIterator(node*root, bool rev){
        reverse = rev;
        pushall(root);
    }

    bool hasnext(){
        return !st.empty();
    }

    int next(){
        node*temp =st.top();
        st.pop();
        if(reverse) pushall(temp->right); //next
        else pushall(temp->left); //prev
        return temp->data;
    }
};

int main()
{
    node*root = new node(7);
    root->left = new node(3);
    root->right = new node(15);
    root->right->left = new node(9);
    root->right->right = new node(20);

    // optimalBSTIterator it(root);
    // bruteBSTIterator it(root);
    BSTIterator it(root,true);
    cout<<it.next()<<endl;
    cout<<it.next()<<endl;
    cout<<it.hasnext()<<endl;
    cout<<it.next()<<endl;
    cout<<it.hasnext()<<endl;
    cout<<it.next()<<endl;
    cout<<it.hasnext()<<endl;
    cout<<it.next()<<endl;
    cout<<it.hasnext()<<endl;
    
    return 0;
}