#include<iostream>
#include<bits/stdc++.h>
using namespace std;

int minEffort(vector<vector<int>>&mat){
    int n = mat.size();
    int m = mat[0].size();

    //(diff,(row,col))
    priority_queue<pair<int,pair<int,int>>,vector<pair<int,pair<int,int>>>,greater<pair<int,pair<int,int>>>>pq;
    vector<vector<int>>dist(n,vector<int>(m,INT_MAX));
    dist[0][0] = 0; //start
    pq.push({0,{0,0}});
    while(!pq.empty()){
        int row = pq.top().second.first;
        int col = pq.top().second.second;
        int diff = pq.top().first;
        pq.pop();

        if(row == n-1 && col == m-1) return diff;

        vector<int>drow = {-1,0,1,0};
        vector<int>dcol = {0,1,0,-1};
        for (int i = 0; i < 4; i++)
        {
            int nrow = row + drow[i];
            int ncol = col + dcol[i];
            if(nrow>=0 && nrow<n && ncol>=0 && ncol<m){
                int newEffort = max(diff,abs(mat[row][col] - mat[nrow][ncol]));
                if(newEffort < dist[nrow][ncol]){
                    dist[nrow][ncol] = newEffort;
                    pq.push({newEffort,{nrow,ncol}});
                }
            }
        }
        
    }
    return 0;
}

int main()
{
    int n,m;
    cin>>n>>m;
    vector<vector<int>>mat(n,vector<int>(m));
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            cin>>mat[i][j];
        }
        
    }
    
    cout<<minEffort(mat);
    
    return 0;
}