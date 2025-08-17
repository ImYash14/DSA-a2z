#include<iostream>
#include<bits/stdc++.h>
using namespace std;

bool BFS(int start,vector<int>&color,vector<vector<int>>&adj){
    queue<int>q;
    q.push(start);
    color[start] = 0;

    while(!q.empty()){
        int node = q.front();
        q.pop();

        for(auto it : adj[node]){
            //if not colored
            if(color[it] == -1){
                color[it] = !color[node]; //assign the color opposite to adjacent node
                q.push(it);
            }

            //if colored
            else{
                if(color[it] == color[node]){ //if adjacent nodes have same color
                    return false;
                }
            }
        }
    }
    return true;
}

bool isBipartite(int start,vector<vector<int>>&adj){
    int n = adj.size();
    vector<int>color(n,-1);

    //for components
    for(int i = 1; i<n; i++){
        if(color[i] == -1){
            if(BFS(i,color,adj)==false) return false;
        }
    }
    return true;
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
    
    cout<<isBipartite(1,adj);
    
    return 0;
}