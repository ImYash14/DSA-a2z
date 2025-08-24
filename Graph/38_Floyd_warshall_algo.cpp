#include<iostream>
#include<bits/stdc++.h>
using namespace std;

vector<vector<int>> floydWarshalalgo(vector<vector<int>>&mat){
    int n = mat.size();

    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            if(i==j) mat[i][j] = 0;
        }
        
    }

    for (int via = 0; via < n; via++)
    {
        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < n; j++)
            {
               if(mat[i][via] != INT_MAX && mat[via][j] != INT_MAX){
                    mat[i][j] = min(mat[i][j],mat[i][via] + mat[via][j]);
               }              
            }
            
        }
        
    }

    for (int i = 0; i < n; i++)
    {
        if(mat[i][i] < 0) return {{-1}};
    }
    
    return mat;    
}

int main()
{
    int v,e;
    cin>>v>>e;
    vector<vector<int>>mat(v,vector<int>(v,INT_MAX));
    for (int i = 0; i < e; i++)
    {
        int u,v,weight;
        cin>>u>>v>>weight;
        mat[u][v] = weight;
    }
    
    vector<vector<int>>output = floydWarshalalgo(mat);
    for(auto it : output){
        for(int num : it){
            cout<<num<<" ";
        }
        cout<<endl;
    }
    
    return 0;
}