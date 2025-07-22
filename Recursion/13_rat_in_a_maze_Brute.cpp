#include<iostream>
#include<bits/stdc++.h>
using namespace std;

//Note->writing vis[i][j]!=0 is wrong in if statement

void brute(int i, int j,string dir,vector<vector<int>>&vis,vector<string>&ans,vector<vector<int>>&maze, int n){
    if(i == n-1 && j == n-1){
        ans.push_back(dir);
        return;
    }
    //order->DLRU
    //for down
    if(i+1<n && !vis[i+1][j] && maze[i+1][j] == 1){
        //marking the current before moving to the next
        vis[i][j] =1;
        brute(i+1,j,dir+'D',vis,ans,maze,n);
        //while returning 
        //unmarking the current because now it is not in our path
        vis[i][j] =0;
    }

    //for left
    if(j-1>=0 && !vis[i][j-1] && maze[i][j-1] == 1){
        vis[i][j] =1;
        brute(i,j-1,dir+'L',vis,ans,maze,n);
        vis[i][j] =0;
    }

    //for right
    if(j+1<n && !vis[i][j+1] && maze[i][j+1] == 1){
        vis[i][j] =1;
        brute(i,j+1,dir+'R',vis,ans,maze,n);
        vis[i][j] =0;
    }

    //for up
    if(i-1>=0 && !vis[i-1][j] && maze[i-1][j] == 1){
        vis[i][j] =1;
        brute(i-1,j,dir+'U',vis,ans,maze,n);
        vis[i][j] =0;
    }
}

vector<string> fun(vector<vector<int>>&maze,int n){
    vector<string>ans;
    string dir;
    vector<vector<int>>vis(n,vector<int>(n,0));
    if(maze[0][0] == 1){
        brute(0,0,"",vis,ans,maze,n);
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