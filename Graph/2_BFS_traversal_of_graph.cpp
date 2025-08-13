#include<iostream>
#include<bits/stdc++.h>
using namespace std;

vector<int> BFS(int n, int start, vector<vector<int>>&adj){
    vector<int>ans;
    vector<int>vis(n+1,0); 
    vis[start] =1;
    queue<int>q;
    q.push(start);
    while(!q.empty()){
        int node = q.front();
        q.pop();
        ans.push_back(node);

        //check for the neighbours of the node in adjacency list
        for(auto it : adj[node]){
            if(!vis[it]){
                vis[it] =1;
                q.push(it);
            }
        }
    }
    return ans;
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
    
    vector<int>output = BFS(n,6,adj);
    for(auto it : output){
        cout<<it<<" ";
    }
    
    return 0;
}