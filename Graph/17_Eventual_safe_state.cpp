#include<iostream>
#include<bits/stdc++.h>
using namespace std;

bool DFS(int node,vector<int>&vis,vector<int>&pathvis,vector<vector<int>>&adj,vector<int>&check){
    vis[node] =1;
    pathvis[node] =1;
    check[node] = 0; //unsafe

    for(auto it : adj[node]){
        if(!vis[it]){
            if(DFS(it,vis,pathvis,adj,check)==true){
                check[node] = 0; //unsafe
                return true;//cycle found
            }
        }
        else{
            if(vis[it] && pathvis[it]){
                check[node] = 0; //unsafe
                return true; //cycle found
            }
        }
    }

    //if no cycle is found
    //and unmark the pathvis
    pathvis[node] =0;
    check[node] = 1; //safe
    return false;
}

void topoSortDFS(int node,vector<int>&vis,vector<vector<int>>&adj,vector<int>&ans){
    vis[node] = 1;

    for(auto it : adj[node]){
        if(!vis[it]){
            topoSortDFS(it,vis,adj,ans);
        }
    }

    //whose dfs is completed, push in the ans
    ans.push_back(node);
}

vector<int> safeState(vector<vector<int>>&adj){
    int n = adj.size();
    vector<int>vis(n,0);
    vector<int>pathvis(n,0);
    vector<int>check(n);
    for (int i = 0; i < n; i++)
    {
        if(!vis[i]){
            DFS(i,vis,pathvis,adj,check);
        }
    }
    
    //the pathvis doesnot gaurantees the safe node
    //bc, suppose a func has two calls
    //one call detects a cycle while other didnt
    //so eventually all nodes will be unsafe
    //hence we need a diff check array
    vector<int>ans;
    for (int i = 0; i < n; i++)
    {
        if(check[i] == 1){
            ans.push_back(i);
        }
    }
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
    
    vector<int>output = safeState(adj);
    for(auto it : output){
        cout<<it<<" ";
    }
    
    return 0;
}