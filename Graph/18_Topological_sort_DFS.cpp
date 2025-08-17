#include<iostream>
#include<bits/stdc++.h>
using namespace std;

void DFS(int node,vector<int>&vis,stack<int>&st,vector<vector<int>>&adj){
    vis[node] =1;

    for(auto it : adj[node]){
        if(!vis[it]){
            DFS(it,vis,st,adj);
        }
    }

    //whose dfs is complete, store it in stack
    // push AFTER exploring all children
    st.push(node); 
}

vector<int> topoSort(vector<vector<int>>&adj){
    int n = adj.size();

    vector<int>vis(n,0);
    stack<int>st;
    for (int i = 0; i < n; i++)
    {
        if(!vis[i]){
            DFS(i,vis,st,adj);
        }
    }

    vector<int>ans;
    while(!st.empty()){
        ans.push_back(st.top());
        st.pop();
    }
    return ans;  
}

int main()
{
    int v,e;
    cin>>v>>e;
    vector<vector<int>>adj(v);
    for (int i = 0; i < e; i++)
    {
        int u,v;
        cin>>u>>v;
        adj[u].push_back(v);
    }
    
    vector<int>output = topoSort(adj);
    for(auto it : output){
        cout<<it<<" ";
    }
    
    return 0;
}