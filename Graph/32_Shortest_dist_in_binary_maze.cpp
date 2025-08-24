#include<iostream>
#include<bits/stdc++.h>
using namespace std;

int shortestDistance(pair<int,int>src,pair<int,int>dest,vector<vector<int>>&maze){
    int n = maze.size();
    int m = maze[0].size();

    vector<vector<int>>dist(n,vector<int>(m,INT_MAX));
    dist[src.first][src.second] = 0;
    queue<pair<int,pair<int,int>>>q; //(dist,(row,col))
    q.push({0,{src.first,src.second}});

    while(!q.empty()){
        int row = q.front().second.first;
        int col = q.front().second.second;
        int d = q.front().first;
        q.pop();

        if(row == dest.first && col == dest.second){
            return dist[row][col];
        }

        //to move in 4-direction 
        vector<int>drow = {-1,0,1,0};
        vector<int>dcol = {0,1,0,-1};
        for (int i = 0; i < 4; i++)
        {
            int nrow = row + drow[i];
            int ncol = col + dcol[i];
            if(nrow>=0 && nrow<n && ncol>=0 && ncol<m && maze[nrow][ncol] == 1){
                if(d + 1 < dist[nrow][ncol]){
                    dist[nrow][ncol] = d+1;
                    q.push({d+1,{nrow,ncol}});
                }
            }
        }
        
    }
    return -1;
}

int main()
{
    int n,m;
    cin>>n>>m;
    vector<vector<int>>maze(n,vector<int>(m));
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            cin>>maze[i][j];
        }
        
    }
    
    cout<<shortestDistance({0,1},{2,2},maze);
    
    return 0;
}