#include <iostream>
#include <bits/stdc++.h>
using namespace std;

vector<int> bellmanFordalgo(int v, int src, vector<vector<int>> &edges)
{
    int n = edges.size();

    vector<int> dist(v, INT_MAX);
    dist[src] = 0;

    for (int i = 0; i < v; i++)
    {
        for (auto it : edges)
        {
            int u = it[0];
            int v = it[1];
            int wt = it[2];
            if (dist[u] != INT_MAX && dist[u] + wt < dist[v])
            {
                dist[v] = dist[u] + wt;
            }
        }
    }

    // nth relaxation to check negative cycle
    for (auto it : edges)
    {
        int u = it[0];
        int v = it[1];
        int wt = it[2];
        if (dist[u] != INT_MAX && dist[u] + wt < dist[v])
        {
            return {-1};
        }
    }
    return dist;
}

int main()
{
    int v, e;
    cin >> v >> e;
    vector<vector<int>> edges;
    for (int i = 0; i < e; i++)
    {
        int u, v, weight;
        cin >> u >> v >> weight;
        edges.push_back({u, v, weight});
    }

    vector<int>output = bellmanFordalgo(v,0,edges);
    for(auto it : output){
        cout<<it<<" ";
    }

    return 0;
}