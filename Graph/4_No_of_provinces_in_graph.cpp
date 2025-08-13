#include<iostream>
#include<bits/stdc++.h>
using namespace std;

void DFS(int node,vector<int>&vis,vector<vector<int>>&adj){
    vis[node] = 1;
    for(auto it : adj[node]){
        if(!vis[it]){
            DFS(it,vis,adj);
        }
    }
}

int provinces(int n,vector<vector<int>>&adj){
    vector<int>vis(n+1,0);
    int count =0;
    for (int i = 1; i <= n; i++)
    {
        if(vis[i] == 0){
            count++;//new province starts
            DFS(i,vis,adj);
        }
    }
    return count;
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
    
    cout<<provinces(n,adj);
    
    return 0;
}