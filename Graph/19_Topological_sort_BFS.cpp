#include<iostream>
#include<bits/stdc++.h>
using namespace std;

void BFS(vector<int>&indegree,vector<vector<int>>&adj,vector<int>&ans){
    queue<int>q;

    //push all the nodes whose indegree is 0
    for (int i = 0; i < adj.size(); i++)
    {
        if(indegree[i] == 0){
            q.push(i);
        }
    }

    while(!q.empty()){
        int node = q.front();
        q.pop();
        ans.push_back(node); //take the front node of queue in ans

        //decrease the indegree of node's adjacent 
        for(auto it : adj[node]){
            indegree[it]--;
            if(indegree[it]==0){ //if the adjacents become 0,push them in queue
                q.push(it);
            }
        }
    }
}

vector<int> topoSort(vector<vector<int>>&adj){
    int n = adj.size();

    //fill the indegree by iterating on adj list
    vector<int>indegree(n);
    for(auto node : adj){
        for(auto it : node){
            indegree[it]++;
        }
    }

    vector<int>ans;
    BFS(indegree,adj,ans);
    return ans;
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
    
    vector<int>output = topoSort(adj);
    for(auto it : output){
        cout<<it<<" ";
    }
    
    return 0;
}