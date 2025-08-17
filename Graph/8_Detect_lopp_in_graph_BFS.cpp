#include<iostream>
#include<bits/stdc++.h>
using namespace std;

bool DFS(int start,vector<int>&vis,vector<vector<int>>&adj){
    vis[start] =1;
    queue<pair<int,int>>q; //(node,parent)
    q.push({start,-1});
    while(!q.empty()){
        int node = q.front().first;
        int parent = q.front().second;
        q.pop();

        for(auto it : adj[node]){
            if(!vis[it]){
                vis[it] =1;
                q.push({it,node});
            }
            else if(vis[it]){
                if(parent != it) return true;
            }
        }
    }
    return false;
}

bool detectLoop(vector<vector<int>>&adj, int n){
    vector<int>vis(n+1,0);

    //for components of graph
    for (int i = 1; i <= n; i++)
    {
        if(!vis[i]){
            if(DFS(i,vis,adj) == true) return true;
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
    
    cout<<detectLoop(adj,n);
    
    return 0;
}