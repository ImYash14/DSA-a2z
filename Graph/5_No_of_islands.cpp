#include<iostream>
#include<bits/stdc++.h>
using namespace std;

void BFS(int i, int j,vector<vector<int>>&vis,vector<vector<int>>&mat,int n,int m){
    vis[i][j] =1;
    queue<pair<int,int>>q;
    q.push({i,j});
    while(!q.empty()){
        int row = q.front().first;
        int col = q.front().second;
        q.pop();

        //search for neighbour lands for current row and col
        for (int delrow = -1; delrow <= 1; delrow++)
        {
            for (int delcol = -1; delcol <= 1; delcol++)
            {
                int nrow = row + delrow;
                int ncol = col + delcol;

                if(nrow>=0 && nrow<n && ncol>=0 && ncol<m
                && mat[nrow][ncol] == 1 && !vis[nrow][ncol]){
                    vis[nrow][ncol] =1;
                    q.push({nrow,ncol});
                }
            }
            
        }
        
    }
}

void DFS(int i, int j,vector<vector<int>>&vis,vector<vector<int>>&mat,int n,int m){
    vis[i][j] =1;

    //search for neighbour lands for current row and col
        for (int delrow = -1; delrow <= 1; delrow++)
        {
            for (int delcol = -1; delcol <= 1; delcol++)
            {
                int nrow = i + delrow;
                int ncol = j + delcol;

                if(nrow>=0 && nrow<n && ncol>=0 && ncol<m
                && mat[nrow][ncol] == 1 && !vis[nrow][ncol]){
                    DFS(nrow,ncol,vis,mat,n,m);
                }
            }
            
        }
    
}

int islands(vector<vector<int>>&mat,int n, int m){
    int count = 0;
    vector<vector<int>>vis(n,vector<int>(m,0));
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            if(mat[i][j] == 1 && !vis[i][j]){
                count++; //new island starts
                // BFS(i,j,vis,mat,n,m);
                DFS(i,j,vis,mat,n,m);
            }
        }
        
    }
    return count;
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

    cout<<islands(mat,n,m);
    
    
    return 0;
}