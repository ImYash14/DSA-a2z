#include<iostream>
#include<bits/stdc++.h>
using namespace std;

void BFS(vector<int>&indegree,vector<vector<int>>&adj,vector<int>&ans){
    queue<int>q;
    for (int i = 0; i < adj.size(); i++)
    {
        if(indegree[i] == 0){
            q.push(i);
        }
    }

    while(!q.empty()){
        int node = q.front();
        q.pop();
        ans.push_back(node);

        for(auto it : adj[node]){
            indegree[it]--;
            if(indegree[it] == 0){
                q.push(it);
            }
        }
    }
    
}

bool detectCycle(vector<vector<int>>&adj){
    int n = adj.size();

    vector<int>indegree(n);
    for(auto node : adj){
        for(auto it : node){
            indegree[it]++;
        }
    }

    vector<int>ans;
    BFS(indegree,adj,ans);
    return(ans.size() != n); //if true then cycle
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
    }

    cout<<detectCycle(adj);
        
    return 0;
}