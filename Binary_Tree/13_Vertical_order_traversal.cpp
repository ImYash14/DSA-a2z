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

vector<vector<int>> verticalorder(node*root){
    map<int,map<int,multiset<int>>> mpp; //map<vertical,map<level,multiset<node->data>>>
    queue<pair<node*,pair<int,int>>> q; //queue<node,(vertical,level)>
    q.push({root,{0,0}});
    while(!q.empty()){
        //pop the front element from queue
        auto mark = q.front();
        q.pop();
        node*temp = mark.first;

        int vertical = mark.second.first;
        int level = mark.second.second;

        //push the node->data in map for current (vertical,level)
        mpp[vertical][level].insert(temp->data);

        //check for the popped nodes left and right and push in the queue
        if(temp->left != NULL){
            q.push({temp->left,{vertical-1, level+1}});
        }
        if(temp->right != NULL){
            q.push({temp->right,{vertical+1, level+1}});
        }
    }
    vector<vector<int>>ans;
    for(auto p : mpp){ //for each vertical
        vector<int>lines;
        for(auto q : p.second){ //p.second is multiset
            lines.insert(lines.end(),q.second.begin(),q.second.end());
        }
        ans.push_back(lines);
    }
    return ans;
}

int main()
{
    node*root = new node(1);
    root->left = new node(2);
    root->left->left = new node(4);
    root->left->right = new node(10);
    root->left->left->right = new node(5);
    root->left->left->right->right = new node(6);

    root->right = new node(3);
    root->right->left = new node(9);
    root->right->right = new node(10);

    vector<vector<int>>output = verticalorder(root);
    for(auto it : output){
        for(int num : it){
            cout<<num<<" ";
        }
    }
    
    return 0;
}