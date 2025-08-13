#include <iostream>
#include <bits/stdc++.h>
using namespace std;

int main()
{
    int n, m;
    cout << "enter the no. of nodes: ";
    cin >> n;
    cout << "enter the no. of edges: ";
    cin >> m;

    // using matrix
    //  vector<vector<int>>mat(n+1,vector<int>(n+1));
    //  for (int i = 0; i < m; i++)
    //  {
    //      int u,v;
    //      cin>>u>>v;
    //      mat[u][v] =1;
    //      mat[v][u] =1;
    //  }

    // for weighted graphs
    //  vector<vector<int>>mat(n+1,vector<int>(n+1));
    //  for (int i = 0; i < m; i++)
    //  {
    //      int u,v,weight;
    //      cin>>u>>v;
    //      mat[u][v] = weight;
    //      mat[v][u] = weight;
    //  }

    // using vector
    // vector<vector<int>> adj(n + 1);
    // for (int i = 0; i < m; i++)
    // {
    //     int u, v;
    //     cin >> u >> v;
    //     adj[u].push_back(v);
    //     adj[v].push_back(u); // for directed graph, no need of this line
    // }
    // for (auto it : adj)
    // {
    //     for (int num : it)
    //     {
    //         cout << num << " ";
    //     }
    //     cout << endl;
    // }

    // for weighted graphs
    vector<vector<pair<int, int>>> arr(n + 1);
    for (int i = 0; i < m; i++)
    {
        int u, v, weight;
        cin >> u >> v >> weight;
        arr[u].push_back({v, weight});
        arr[v].push_back({u, weight});
    }

    for (int u = 1; u <= n; u++)
    {
        cout << u << " -> ";
        for (auto &edge : arr[u])
        {
            cout << "(" << edge.first << ", " << edge.second << ") ";
            // edge.first = neighbor vertex
            // edge.second = weight
        }
        cout << "\n";
    }

    return 0;
}