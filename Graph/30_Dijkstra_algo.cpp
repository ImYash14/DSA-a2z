#include<iostream>
#include<bits/stdc++.h>
using namespace std;

vector<int> dijkstraUsingPQ(int src,vector<vector<pair<int,int>>>&adj){
    int n = adj.size();

    //if we use queue it will also give us correct ans

    //min heap implementation using priority queue
    //top will be min distance
    //pair(dist,node)
    priority_queue<pair<int,int>,vector<pair<int,int>>,greater<pair<int,int>>>pq;
    pq.push({0,src});

    vector<int>dist(n,INT_MAX);
    dist[src] = 0;
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
            }
        }
    }
    return dist;
}

vector<int> dijkstraUsingSet(int src,vector<vector<pair<int,int>>>&adj){
    int n = adj.size();

    set<pair<int,int>>st; //pair(dist,node)
    st.insert({0,src});
    vector<int>dist(n,INT_MAX);
    dist[src] = 0;

    while(!st.empty()){
        auto it = *(st.begin()); //gives te address of top
        int d = it.first;
        int node = it.second;
        st.erase(it);

        for(auto i : adj[node]){
            int v = i.first;
            int wt = i.second;
            if(d + wt < dist[v]){
                if(dist[v] != INT_MAX){ //someone visited
                    st.erase({dist[v],v});
                }
                dist[v] = d + wt;
                st.insert({dist[v],v});
            }
        }
    }
    return dist;
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
    
    // vector<int>output = dijkstraUsingPQ(2,adj);
    vector<int>output = dijkstraUsingSet(2,adj);
    for(auto it : output){
        cout<<it<<" ";
    }
    
    return 0;
}