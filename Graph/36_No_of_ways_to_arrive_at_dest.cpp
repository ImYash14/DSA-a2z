#include<iostream>
#include<bits/stdc++.h>
using namespace std;

int noOfways(vector<vector<pair<int,int>>>&adj){
    int n = adj.size();

    //(dist,node)
    priority_queue<pair<int,int>,vector<pair<int,int>>,greater<pair<int,int>>>pq;
    vector<int>ways(n,0);
    vector<int>dist(n, INT_MAX);

    int mod = 1e9 + 7;
    dist[0] = 0;
    ways[0] = 1;
    pq.push({0,0});
    while(!pq.empty()){
        int node = pq.top().second;
        int d = pq.top().first;
        pq.pop();

        for(auto it : adj[node]){
            int v = it.first;
            int wt = it.second;

            //first time arriving with this short path
            if(d + wt < dist[v]){
                dist[v] = d + wt;
                pq.push({dist[v],v});
                ways[v] = ways[node];
            }
            //if again arriving with same short path
            else if(d + wt == dist[v]){
                ways[v] = (ways[v] + ways[node])%mod;
            }
        }
    }
    return ways[n-1]%mod;
}

int main()
{
    int v,e;
    cin>>v>>e;
    vector<vector<pair<int,int>>>adj(v);
    for (int i = 0; i < e; i++)
    {
        int u,v,weight;
        cin>>u>>v>>weight;
        adj[u].push_back({v,weight});
        adj[v].push_back({u,weight});
    }
    
    cout<<noOfways(adj);
    
    return 0;
}