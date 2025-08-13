#include<iostream>
#include<bits/stdc++.h>
using namespace std;

void recursion(int node, vector<int>&vis, vector<int>&ans, vector<vector<int>>&adj){
    vis[node] =1;
    ans.push_back(node);

    //for traversing the neighbours of the node
    for(auto it : adj[node]){
        if(!vis[it]){
            recursion(it,vis,ans,adj);
        }
    }
}

vector<int> DFS(int n, int start, vector<vector<int>>&adj){
    vector<int>ans;
    vector<int>vis(n+1,0);
    vis[start] = 1;
    recursion(start,vis,ans,adj);
    return ans;
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
    
    vector<int>output = DFS(n,3,adj);
    for(auto it : output){
        cout<<it<<" ";
    }
    
    return 0;
}