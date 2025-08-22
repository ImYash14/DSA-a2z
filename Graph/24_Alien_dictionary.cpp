#include<iostream>
#include<bits/stdc++.h>
using namespace std;

void toposortBFS(vector<vector<int>>&adj,vector<int>&ans){
    int n = adj.size();
    vector<int>indegree(n);
    for (int i = 0; i < n; i++)
    {
        for(auto it : adj[i]){
            indegree[it]++;
        }
    }
    
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
            indegree[it]--;
            if(indegree[it] == 0){
                q.push(it);
            }
        }
    }
    
}

string alienDictionary(int k,vector<string>&dict){
    //construct an adj list
    vector<vector<int>>adj(k);
    for (int i = 0; i < dict.size()-1; i++)
    {
        string s1 = dict[i];
        string s2 = dict[i+1];
        int len = min(s1.size(),s2.size());
        for (int j = 0; j < len; j++)
        {
            if(s1[j] != s2[j]){
                adj[s1[j]-'a'].push_back(s2[j]-'a');
                break;
            }
        }
        
    }

    vector<int>res;
    toposortBFS(adj,res);

    string ans = "";
    for(auto it : res){
        ans = ans + char(it + 'a');
    }
    return ans;
}

int main()
{
    int n,k; //n words & k starting alphabets
    cin>>n>>k;
    vector<string>dict(n);
    for (int i = 0; i < n; i++)
    {
        cin>>dict[i];
    }

    cout<<alienDictionary(k,dict);
    
    return 0;
}