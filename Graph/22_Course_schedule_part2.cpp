#include<iostream>
#include<bits/stdc++.h>
using namespace std;

void BFS(vector<int>&indegree,vector<vector<int>>&adj,vector<int>&ans){
    queue<int>q;
    for (int i = 0; i < adj.size(); i++)
    {
        if(indegree[i] == 0) q.push(i);
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

vector<int> topoSort(int tasks,vector<pair<int,int>>&arr){
    //convert into adj list
    vector<vector<int>>adj(tasks);
    for(auto it : arr){
        adj[it.first].push_back(it.second);
        //if reverse tasks order then
        //adj[it.second].push_back(it.first);
    }

    vector<int>indegree(tasks);
    for(auto node : adj){
        for(auto it : node){
            indegree[it]++;
        }
    }
    
    vector<int>ans;
    BFS(indegree,adj,ans);
    if(ans.size() == tasks) return ans;
    return {};
}

int main()
{
    int tasks,pairs;
    cin>>tasks>>pairs;
    vector<pair<int,int>>arr(pairs);
    for (int i = 0; i < pairs; i++)
    {
        cin>>arr[i].first>>arr[i].second;
    }

    vector<int>output = topoSort(tasks,arr);
    for(auto it : output){
        cout<<it<<" ";
    }
    
    return 0;
}