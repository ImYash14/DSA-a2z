#include<iostream>
#include<bits/stdc++.h>
using namespace std;

vector<int> shortestPath(vector<vector<pair<int,int>>>&adj,int src,int dest){
    int n = adj.size();

    vector<int>dist(n,INT_MAX);
    dist[src] = 0;
    vector<int>parent(n);
    for (int i = 0; i < n; i++)
    {
        parent[i] = i;
    }
    

    priority_queue<pair<int,int>,vector<pair<int,int>>,greater<pair<int,int>>>pq;
    pq.push({0,src});
    while(!pq.empty()){
        int d = pq.top().first;
        int node = pq.top().second;
        pq.pop();

        for(auto it : adj[node]){
            int v = it.first;
            int wt = it.second;
            if(d + wt < dist[v]){
                dist[v] = d + wt;
                pq.push({dist[v],v});
                parent[v] = node;
            }
        }
    }

    if(dist[n-1] == INT_MAX) return {-1};
    vector<int>ans;
    int node = dest; //or n-1
    while(parent[node] != node){
        ans.push_back(node);
        node = parent[node];
    }
    ans.push_back(src);

    reverse(ans.begin(),ans.end());
    return ans;
}

int main()
{
    int v,e;
    cin>>v>>e;
    vector<vector<pair<int,int>>>adj(v+1);
    for (int i = 0; i < e; i++)
    {
        int u,v,weight;
        cin>>u>>v>>weight;
        adj[u].push_back({v,weight});
        adj[v].push_back({u,weight});
    }
    
    vector<int>output = shortestPath(adj,1,5);
    for(auto it : output){
        cout<<it<<" ";
    }
    
    return 0;
}