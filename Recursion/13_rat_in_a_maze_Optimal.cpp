#include<iostream>
#include<bits/stdc++.h>
using namespace std;

void optimal(int i, int j, string move,vector<vector<int>>&vis,vector<vector<int>>&maze,vector<string>&ans,vector<int>&di,vector<int>&dj, int n){
    if(i == n-1 && j == n-1){
        ans.push_back(move);
        return;
    }

    string dir = "DLRU";
    for(int index =0; index<4; index++){
        int nexti = i + di[index];
        int nextj = j + dj[index];
        if(nexti>=0 && nextj>=0 && nexti<n && nextj<n && !vis[nexti][nextj] && maze[nexti][nextj] == 1){
            //marking the current before moving to next
            //so that it gets included in path
            vis[i][j] =1;
            optimal(nexti,nextj,move+dir[index],vis,maze,ans,di,dj,n);
            //while returning
            //unmarking the current where we are standing
            //because it is not included in the path
            vis[i][j] =0;

        }
    }
}

vector<string>fun(vector<vector<int>>&maze,int n){
    vector<string>ans;
    string move;
    vector<vector<int>>vis(n,vector<int>(n,0));
    vector<int>di = {1,0,0,-1};
    vector<int>dj = {0,-1,1,0};

    if(maze[0][0] == 1){
        optimal(0,0,"",vis,maze,ans,di,dj,n);
    }
    return ans;
}

int main()
{
    int n;
    cout<<"enter the size of of maze: ";
    cin>>n;
    vector<vector<int>>maze(n,vector<int>(n));
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            cin>>maze[i][j];
        }
        
    }

    vector<string>output = fun(maze,n);
    for(auto it: output){
        cout<<it<<" ";
    }
    return 0;
}