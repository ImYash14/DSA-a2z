#include<iostream>
#include<bits/stdc++.h>
using namespace std;

void DFS(int row,int col,vector<vector<int>>&vis,vector<vector<char>>&mat){
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
        && !vis[nrow][ncol] && mat[nrow][ncol] == 'O'){
            DFS(nrow,ncol,vis,mat);
        }
    }
    
}

void convertOtoX(vector<vector<char>>&mat){
    int n = mat.size();
    int m = mat[0].size();
    vector<vector<int>>vis(n,vector<int>(m,0));

    //for 0th col & last col
    for (int i = 0; i < n; i++)
    {
        if(mat[i][0] == 'O' && !vis[i][0]){
            DFS(i,0,vis,mat);
        }
        if(mat[i][m-1] == 'O' && !vis[i][m-1]){
            DFS(i,m-1,vis,mat);
        }
    }

    //for 0th row & last row
    for (int i = 0; i < m; i++)
    {
        if(mat[0][i] == 'O' && !vis[0][i]){
            DFS(0,i,vis,mat);
        }
        if(mat[n-1][i] == 'O' && !vis[n-1][i]){
            DFS(n-1,i,vis,mat);
        }
    }
    
    //for marking the remaining Os that are surrounded by Xs
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            if(mat[i][j] == 'O' && !vis[i][j]){
                mat[i][j] = 'X';
            }
        }
        
    }   
    
}

int main()
{
    int n, m;
    cin>>n>>m;
    vector<vector<char>>mat(n,vector<char>(m));
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            cin>>mat[i][j];
        }
        
    }

    convertOtoX(mat);
    cout<<endl;

    for(auto it : mat){
        for(char ch : it){
            cout<<ch<<" ";
        }
        cout<<endl;
    }
    
    
    return 0;
}