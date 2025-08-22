#include<iostream>
#include<bits/stdc++.h>
using namespace std;

void topoDFS(int node,vector<int>&vis,vector<vector<pair<int,int>>>&adj, stack<int>&st){
    vis[node] = 1;

    for(auto it : adj[node]){
        if(!vis[it.first]){
            topoDFS(it.first,vis,adj,st);
        }
    }
    st.push(node);
}

vector<int> shortestPath(int src,vector<vector<pair<int,int>>>&adj){
    int n = adj.size();

    //step1->apply toposort(dfs or bfs) on graph
    vector<int>vis(n,0);
    stack<int>st;
    for (int i = 0; i < n; i++)
    {
        if(!vis[i]){
            topoDFS(i,vis,adj,st);
        }
    }

    //step2->take the nodes out of stack & (relax the edges)
    vector<int>dist(n,INT_MAX);
    dist[src] = 0;

    while(!st.empty()){
        int node = st.top();
        st.pop();

        for(auto it : adj[node]){
            // dist[it.first] = min(dist[it.first],it.second + dist[node]);
            int v = it.first;
            int wt = it.second;
            // dist[v] = min(dist[v], dist[node] + wt);
            if(dist[node] != INT_MAX && dist[node]+wt < dist[v]){//to avoid overflow
                dist[v] = dist[node] + wt;
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

void topoBFS(vector<int>indegree,vector<vector<pair<int,int>>>&adj,vector<int>&ans){
    int n = adj.size();
    queue<int>q;
    for (int i = 0; i < n; i++)
    {
        if(indegree[i] == 0) q.push(i);
    }

    while(!q.empty()){
        int node = q.front();
        q.pop();
        ans.push_back(node);

        for(auto it : adj[node]){
            indegree[it.first]--;
            if(indegree[it.first]==0)q.push(it.first);
        }
    }
}

vector<int> shortestpathBFS(int src,vector<vector<pair<int,int>>>&adj){
    int n = adj.size();

    vector<int>indegree(n,0);
    for(auto node : adj){
        for(auto it : node){
            indegree[it.first]++;
        }
    }

    vector<int>ans; 
    topoBFS(indegree,adj,ans);
    //now we have the topo sort order
    reverse(ans.begin(),ans.end()); //stack order

    vector<int>dist(n,INT_MAX);
    dist[src] = 0;
    while(ans.size() != 0){
        int node = ans.back();
        ans.pop_back();

        for(auto it : adj[node]){
            // dist[it.first] = min(dist[it.first],it.second + dist[node]);
            int v = it.first;
            int wt = it.second;
            // dist[v] = min(dist[v], dist[node] + wt);
            if(dist[node] != INT_MAX && dist[node]+wt < dist[v]){//to avoid overflow
                dist[v] = dist[node] + wt;
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
    vector<vector<pair<int,int>>>adj(v);
    for (int i = 0; i < e; i++)
    {
        int u,v,weight;
        cin>>u>>v>>weight;
        adj[u].push_back({v,weight});
    }
    
    vector<int>output = shortestpathBFS(4,adj);
    for(auto it : output){
        cout<<it<<" ";
    }
    
    return 0;
}