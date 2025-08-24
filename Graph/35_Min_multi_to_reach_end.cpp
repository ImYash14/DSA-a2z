#include<iostream>
#include<bits/stdc++.h>
using namespace std;

int minMultiplications(int start, int target, vector<int>&arr){
    queue<pair<int,int>>q; //(steps,num)
    vector<int>dist(1e5,INT_MAX); // (0 to 9999)
    dist[start] = 0;
    q.push({0,start});

    while(!q.empty()){
        int steps = q.front().first;
        int node = q.front().second;
        q.pop();

        if(node == target) return steps;

        for(auto it : arr){
           int num = (it*node)%100000;
           if(steps + 1 < dist[num]){
                dist[num] = steps + 1;
                q.push({steps+1,num});
           }
        }
    }
    return -1;
}

int main()
{
    int start,target;
    cin>>start>>target;
    int n;
    cin>>n;
    vector<int>arr(n);
    for (int i = 0; i < n; i++)
    {
        cin>>arr[i];
    }
    
    cout<<minMultiplications(start,target,arr);
    
    return 0;
}