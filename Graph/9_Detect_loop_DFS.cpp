#include<iostream>
#include<bits/stdc++.h>
using namespace std;

bool DFS(int node, int parent, vector<int>&vis, vector<vector<int>>&adj){
    vis[node] =1;
    for(auto it : adj[node]){
        if(!vis[it]){
            if(DFS(it,node,vis,adj) == true) return true;
        }
        else if(parent != it) return true;
    }
    return false;
}

bool detectLoop(int n, vector<vector<int>>&adj){
    vector<int>vis(n+1,0);
    for (int i = 1; i <= n; i++)
    {
        if(!vis[i]){
            if(DFS(i,-1,vis,adj) == true) return true;
        }
    }
    return false;
}

int main()
{
    int n,m;
    cin>>n>>m;
    vector<vector<int>>adj(n+1);
    for (int i = 0; i < m; i++)
    {
        int u,v;
        cin>>u>>v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }
    
    cout<<detectLoop(n,adj);
    
    return 0;
}