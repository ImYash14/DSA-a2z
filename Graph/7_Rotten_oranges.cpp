#include<iostream>
#include<bits/stdc++.h>
using namespace std;

int rotOranges(vector<vector<int>>&mat,int n,int m){
    vector<vector<int>>ans = mat;
    queue<pair<int,int>>q;
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            if(ans[i][j] == 2){
                q.push({i,j}); //push initial rotten oranges position
            }
        }
        
    }

    int timer = 0;
    while(!q.empty()){
        int size = q.size();
        for (int i = 0; i < size; i++)
        {
            int row = q.front().first;
            int col = q.front().second;
            q.pop();

            vector<int>delrow = {-1,0,1,0};
            vector<int>delcol = {0,1,0,-1};
            for (int i = 0; i < 4; i++)
            {
                int nrow = row + delrow[i];
                int ncol = col + delcol[i];

                if(nrow>=0 && nrow<n && ncol>=0 && ncol<n
                && ans[nrow][ncol] != 2 && ans[nrow][ncol] == 1){
                    ans[nrow][ncol] = 2;
                    q.push({nrow,ncol});
                }
            }
        }
        //increase timer only if there are still some oranges in queue
        if(!q.empty()) timer++; //oranges rotten in unit time
    }
    
    //check if there is still any fresh oranges left in matrix
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            if(ans[i][j] == 1) return -1;
        }
        
    }
    return timer;
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

    cout<<rotOranges(mat,n,m);
    
    
    return 0;
}