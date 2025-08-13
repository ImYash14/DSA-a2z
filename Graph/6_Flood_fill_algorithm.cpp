#include<iostream>
#include<bits/stdc++.h>
using namespace std;

void DFS(int row,int col,vector<vector<int>>&ans,int iniColor,int newColor,int delrow[],int delcol[]){
    ans[row][col] = newColor;
    
    int n = ans.size();
    int m = ans[0].size();
    for (int i = 0; i < 4; i++)
    {
        int nrow = row + delrow[i];
        int ncol = col + delcol[i];
        if(nrow>=0 && nrow<n && ncol>=0 && ncol<m
        && ans[nrow][ncol] == iniColor && ans[nrow][ncol] != newColor){
            DFS(nrow,ncol,ans,iniColor,newColor,delrow,delcol);
        }
    }
    
}

void BFS(int row,int col,vector<vector<int>>&ans,int iniColor,int newColor,int delrow[],int delcol[]){
    ans[row][col] = newColor;
    queue<pair<int,int>>q;
    q.push({row,col});
    while(!q.empty()){
        int row = q.front().first;
        int col = q.front().second;
        q.pop();

        int n = ans.size();
        int m = ans[0].size();
        for (int i = 0; i < 4; i++)
        {
            int nrow = row + delrow[i];
            int ncol = col + delcol[i];
            if(nrow>=0 && nrow<n && ncol>=0 && ncol<m
            && ans[nrow][ncol] == iniColor && ans[nrow][ncol] != newColor){
                ans[nrow][ncol] = newColor;
                q.push({nrow,ncol});
            }
        }
    }
}

vector<vector<int>> floodfill(vector<vector<int>>&image,int srow,int scol,int newColor){
    vector<vector<int>>ans = image;
    int iniColor = ans[srow][scol];

    //for finding neighbours 4-directionally
    int delrow[4] = {-1,0,1,0};
    int delcol[4] = {0,1,0,-1};

    // DFS(srow,scol,ans,iniColor,newColor,delrow,delcol);
    BFS(srow,scol,ans,iniColor,newColor,delrow,delcol);
    return ans;
}

int main()
{
    int n,m;
    cin>>n>>m;
    int newColor;
    cin>>newColor;
    vector<vector<int>>image(n,vector<int>(m));
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            cin>>image[i][j];
        }
        
    }
    
    vector<vector<int>>output = floodfill(image,2,0,newColor);
    for(auto it: output){
        for(int num : it){
            cout<<num<<" ";
        }
        cout<<endl;
    }
    
    return 0;
}