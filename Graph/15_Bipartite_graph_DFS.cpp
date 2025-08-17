#include<iostream>
#include<bits/stdc++.h>
using namespace std;

bool DFS(int node,int col,vector<int>&color,vector<vector<int>>&adj){
    color[node] = col;

    for(auto it : adj[node]){
        if(color[it] == -1){ //if adjacent node not colored
            //take color opposite to node
            if(DFS(it,!col,color,adj) == false){
                return false;
            }
        }
        else{ //if adjacent node already colored
            if(color[it] == color[node]){ //if adjacent nodes have same color
                return false;
            }
        }
    }
    return true;
}

bool isBipartite(vector<vector<int>>&adj){
    int n = adj.size();
    vector<int>color(n,-1);

    //for components
    for (int i = 1; i < n; i++)
    {
        if(color[i] == -1){
            if(DFS(i,0,color,adj) == false) return false;
        }
    }
    return true;
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
        adj[v].push_back(u);
    }
    
    cout<<isBipartite(adj);
    
    return 0;
}