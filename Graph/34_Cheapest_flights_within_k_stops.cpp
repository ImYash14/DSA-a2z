#include<iostream>
#include<bits/stdc++.h>
using namespace std;

int cheapestFlight(vector<vector<pair<int,int>>>&routes,int src, int dest, int k){
    int n = routes.size();
   
    queue<vector<int>>q; //{stops,node,dist}
    vector<int>dist(n,INT_MAX);
    dist[src] = 0;
    q.push({0,src,0});
    while(!q.empty()){
        vector<int>arr = q.front();
        int stops = arr[0];
        int node = arr[1];
        int d = arr[2];
        q.pop();

        if(stops > k) continue; 

        for(auto it : routes[node]){
            int v = it.first;
            int cost = it.second;
            if(d + cost < dist[v] && stops <= k){//bc it will be skipped in next iteration
                dist[v] = d + cost;
                q.push({stops+1, v, dist[v]});
            }
        }
    }
    if(dist[dest] == INT_MAX) return -1;
    return dist[dest];
}

int main()
{
    int v,e;
    cin>>v>>e;
    vector<vector<pair<int,int>>>routes(v);
    for (int i = 0; i < e; i++)
    {
        int from,to,cost;
        cin>>from>>to>>cost;
        routes[from].push_back({to,cost});
    }
    
    cout<<cheapestFlight(routes,0,2,2);
    
    return 0;
}