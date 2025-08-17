#include<iostream>
#include<bits/stdc++.h>
using namespace std;

void DFS(int row,int col,vector<vector<int>>&vis,vector<pair<int,int>>&ans,vector<vector<int>>&mat,int baserow,int basecol){
    vis[row][col] = 1;
    ans.push_back({row-baserow,col-basecol});

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
            DFS(nrow,ncol,vis,ans,mat,baserow,basecol);
        }
    }
    
}

void BFS(int i,int j,vector<vector<int>>&vis,vector<pair<int,int>>&ans,vector<vector<int>>&mat,int baserow,int basecol){
    queue<pair<int,int>>q;
    q.push({i,j});
    
    int n = mat.size();
    int m = mat[0].size();
    vector<int>drow = {-1,0,1,0};
    vector<int>dcol = {0,1,0,-1};
    while(!q.empty()){
        int row = q.front().first;
        int col = q.front().second;
        ans.push_back({row-baserow,col-basecol});
        q.pop();

        for (int i = 0; i < 4; i++)
        {
            int nrow = row + drow[i];
            int ncol = col + dcol[i];
            if(nrow>=0 && nrow<n && ncol>=0 && ncol<m
            && mat[nrow][ncol] == 1 && !vis[nrow][ncol]){
                vis[nrow][ncol] =1;
                q.push({nrow,ncol});
            }
        }
        
    }
}

int distinctIslands(vector<vector<int>>&mat){
    int n = mat.size();
    int m = mat[0].size();
    vector<vector<int>>vis(n,vector<int>(m,0));

    set<vector<pair<int,int>>>st;
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            if(mat[i][j] == 1 && !vis[i][j]){
                vector<pair<int,int>>ans;
                // DFS(i,j,vis,ans,mat,i,j);
                BFS(i,j,vis,ans,mat,i,j);
                st.insert(ans);
            }
        }
        
    }
    return st.size();
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
    
    cout<<distinctIslands(mat);
    
    return 0;
}