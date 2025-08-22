#include<iostream>
#include<bits/stdc++.h>
using namespace std;

vector<int> shortestpath(int src,vector<vector<int>>&adj){
    int n = adj.size();

    vector<int>dist(n,INT_MAX);
    queue<pair<int,int>>q; //(node,distance)
    q.push({src,0});
    dist[src] = 0;
    while(!q.empty()){
        int node = q.front().first;
        int d = q.front().second;
        q.pop();

        for(auto it : adj[node]){
            if(dist[node] + 1 < dist[it]){
                dist[it] = dist[node] + 1;
                q.push({it,dist[it]});
            }
        }
    }

    for (int i = 0; i < n; i++)
    {
        if(dist[i] == INT_MAX){
            dist[i] = -1;
        }
    }
    
    return dist;
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
        adj[v].push_back(u);
    }
    
    vector<int>output = shortestpath(0,adj);
    for(auto it : output){
        cout<<it<<" ";
    }
    
    return 0;
}