#include<iostream>
#include<bits/stdc++.h>
using namespace std;

void topoSortBFS(vector<int>&indegree,vector<vector<int>>&revadj,vector<int>&ans){
    queue<int>q;
    // for(auto it : indegree){
    //     if(indegree[it] == 0) q.push(it);
    // }
    for (int i = 0; i < revadj.size(); i++)
    {
        if(indegree[i] == 0) q.push(i);
    }
    

    while(!q.empty()){
        int node = q.front();
        q.pop();
        ans.push_back(node);

        for(auto it : revadj[node]){
            indegree[it]--;
            if(indegree[it] == 0) q.push(it);
        }
    }
}

vector<int> safeState(vector<vector<int>>&adj){
    int n = adj.size();

    //reverse the edges
    vector<vector<int>>revadj(n);
    for (int i = 0; i < n; i++)
    {
        //here we have i->it
        //but we want it->i
        for(auto it : adj[i]){
            revadj[it].push_back(i);
        }
    }

    vector<int>indegree(n);
    for(auto node : revadj){
        for(auto it : node){
            indegree[it]++;
        }
    }

    vector<int>ans;
    topoSortBFS(indegree,revadj,ans);
    sort(ans.begin(),ans.end());
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