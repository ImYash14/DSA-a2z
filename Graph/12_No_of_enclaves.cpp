#include<iostream>
#include<bits/stdc++.h>
using namespace std;

void DFS(int row,int col,vector<vector<int>>&vis,vector<vector<int>>&mat){
    vis[row][col] = 1;

    int n = mat.size();
    int m = mat[0].size();
    vector<int>drow = {-1,0,1,0};
    vector<int>dcol = {0,1,0,-1};
    for (int i = 0; i < 4; i++)
    {
        int nrow = row + drow[i];
        int ncol = col + dcol[i];
        if(nrow>=0 && nrow<n && ncol>=0 && ncol<m
        && mat[nrow][ncol] == 1 && !vis[nrow][ncol]){
           DFS(nrow,ncol,vis,mat);
        }
    }
    
}

int countEnclaves(vector<vector<int>>&mat){
    int n = mat.size();
    int m = mat[0].size();

    vector<vector<int>>vis(n,vector<int>(m,0));

    //for 0th col & last col
    for (int i = 0; i < n; i++)
    {
        if(mat[i][0] == 1 && !vis[i][0]){
            DFS(i,0,vis,mat);
        }
        if(mat[i][m-1] == 1 && !vis[i][m-1]){
            DFS(i,m-1,vis,mat);
        }
    }

    //for 0th row & last row
    for (int i = 0; i < m; i++)
    {
        if(mat[0][i] == 1 && !vis[0][i]){
            DFS(0,i,vis,mat);
        }
        if(mat[n-1][i] == 1 && !vis[n-1][i]){
            DFS(n-1,i,vis,mat);
        }
    }

    //count the remaining lands that are not visited
    int count =0;
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            if(mat[i][j] == 1 && !vis[i][j]){
                count++;
            }
        }
        
    }
    return count;
    
}

int usingBFS(vector<vector<int>>&mat){
    int n = mat.size();
    int m = mat[0].size();

    vector<vector<int>>vis(n,vector<int>(m,0));
    queue<pair<int,int>>q;
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            //0th row, last row, 0th col, last col
            if((i==0 || i==n-1 || j==0 || j==m-1) && mat[i][j] == 1){
                q.push({i,j});
                vis[i][j] = 1;
            }
        }
        
    }

    vector<int>drow = {-1,0,1,0};
    vector<int>dcol = {0,1,0,-1};
    
    //BFS
    while(!q.empty()){
        int row = q.front().first;
        int col = q.front().second;
        q.pop();

        for (int i = 0; i < 4; i++)
        {
            int nrow = row + drow[i];
            int ncol = col + dcol[i];
            if(nrow>=0 && nrow<n && ncol>=0 && ncol<m
            && mat[nrow][ncol] == 1 && !vis[nrow][ncol]){
                vis[nrow][ncol] = 1;
                q.push({nrow,ncol});
            }
        }
        
    }

    //count the remaining lands that are not visited
    int count =0;
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            if(mat[i][j] == 1 && !vis[i][j]){
                count++;
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
    
    // cout<<countEnclaves(mat);
    cout<<usingBFS(mat);
    
    return 0;
}