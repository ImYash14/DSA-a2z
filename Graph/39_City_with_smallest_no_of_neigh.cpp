#include<iostream>
#include<bits/stdc++.h>
using namespace std;

int citywithSmallestNeighbour(int cities,vector<vector<int>>&arr,int threshold){
    vector<vector<int>>mat(cities,vector<int>(cities,INT_MAX));
    for(auto it : arr){
        mat[it[0]][it[1]] = it[2];
        mat[it[1]][it[0]] = it[2];
    }
    for(int i =0; i<cities; i++){
        mat[i][i] =0;
    }

    for(int via=0; via < cities; via++){
        for (int i = 0; i < cities; i++)
        {
            for (int j = 0; j < cities; j++)
            {
                if(mat[i][via] != INT_MAX && mat[via][j] != INT_MAX){
                    mat[i][j] = min(mat[i][j],mat[i][via] + mat[via][j]);
                }
            }
            
        }
        
    }

    int countMax = threshold+1;
    int city =-1;
    for (int i = 0; i < cities; i++)
    {
        int count = 0;
        for (int j = 0; j < cities; j++)
        {
            if(mat[i][j] <= threshold){
                count++;
            }
        }
        if(count <= countMax){
            countMax = count;
            city = i;
        }
    }
    return city;
}

int main()
{
    int cities,e;
    cin>>cities>>e;
    vector<vector<int>>arr;
    for (int i = 0; i < e; i++)
    {
        int from,to,dist;
        cin>>from>>to>>dist;
        arr.push_back({from,to,dist});
    }
    
    cout<<citywithSmallestNeighbour(cities,arr,4);
    
    return 0;
}