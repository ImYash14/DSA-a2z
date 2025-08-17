#include<iostream>
#include<bits/stdc++.h>
using namespace std;

bool DFS(int node,vector<int>&vis,vector<int>&pathvis,vector<vector<int>>&adj){
    vis[node] = 1;
    pathvis[node] =1;

    for(auto it : adj[node]){
        if(!vis[it]){
            if(DFS(it,vis,pathvis,adj)==true) return true;
        }
        else{
            //it has to be visited in same path for a cycle
            if(vis[it] && pathvis[it]) return true;
        }
    }

    //while returning if not found cycle
    pathvis[node] = 0;
    return false;
}

bool detectCycle(vector<vector<int>>&adj){
    int n = adj.size();
    vector<int>vis(n,0);
    vector<int>pathvis(n,0);

    for (int i = 1; i < n; i++)
    {
        if(!vis[i]){
            if(DFS(i,vis,pathvis,adj) == true) return true;
        }
    }
    return false;
}

int main()
{
    int v,e;
    cin>>v>>e;
    vector<vector<int>>adj(v+1);
    for (int i = 0; i < e; i++)
    {
        int u,v;
        cin>>u>>v;
        adj[u].push_back(v);
    }
    
    cout<<detectCycle(adj);
    
    return 0;
}