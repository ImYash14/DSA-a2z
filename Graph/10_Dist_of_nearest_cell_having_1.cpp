#include <iostream>
#include <bits/stdc++.h>
using namespace std;


//wrong code line->26
// for (int i = 0; i < n; i++)
// {
//     for (int j = 0; j < m; j++)
//     {
//         if (mat[i][j] == 1)
//         {
//             q.push({i, j});
//         }
//     }
// }
// int distance = 0;
// while (!q.empty())
// {
//     int size = q.size();
//     for (int i = 0; i < size; i++)
//     {
//         int row = q.front().first;
//         int col = q.front().second;
//         vis[row][col] = 1;
//         dist[row][col] = 0;
//         q.pop();
//         vector<int> drow = {-1, 0, 1, 0};
//         vector<int> dcol = {0, 1, 0, -1};
//         for (int i = 0; i < 4; i++)
//         {
//             int nrow = row + drow[i];
//             int ncol = col + dcol[i];
//             if (nrow >= 0 && nrow < n && ncol >= 0 && ncol < m && !vis[nrow][ncol])
//             {
//                 vis[nrow][ncol] = 1;
//                 dist[nrow][ncol] = distance + 1;
//                 q.push({nrow, ncol});
//             }
//         }
//     }
// }
// }

void BFS(vector<vector<int>> &vis, vector<vector<int>> &dist, vector<vector<int>> &mat)
{
    int n = mat.size();
    int m = mat[0].size();

    queue<pair<int, int>> q; //(row,col)
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            if (mat[i][j] == 1)
            {
                q.push({i, j});
                vis[i][j] = 1;
                dist[i][j] = 0;
            }
        }
    }

    vector<int> drow = {-1, 0, 1, 0};
    vector<int> dcol = {0, 1, 0, -1};

    while (!q.empty())
    {
        int row = q.front().first;
        int col = q.front().second;
        q.pop();

        for (int i = 0; i < 4; i++)
        {
            int nrow = row + drow[i];
            int ncol = col + dcol[i];
            if (nrow >= 0 && nrow < n && ncol >= 0 && ncol < m && !vis[nrow][ncol])
            {
                vis[nrow][ncol] = 1;
                dist[nrow][ncol] = dist[row][col] + 1;
                q.push({nrow, ncol});
            }
        }
    }
}

vector<vector<int>> nearestDistance(vector<vector<int>> &mat)
{
    int n = mat.size();
    int m = mat[0].size();
    vector<vector<int>> dist(n, vector<int>(m));
    vector<vector<int>> vis(n, vector<int>(m, 0));

    BFS(vis, dist, mat);
    return dist;
}

int main()
{
    int n, m;
    cin >> n >> m;
    vector<vector<int>> mat(n, vector<int>(m));
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            cin >> mat[i][j];
        }
    }

    vector<vector<int>> output = nearestDistance(mat);
    for (auto it : output)
    {
        for (int num : it)
        {
            cout << num << " ";
        }
        cout << endl;
    }

    return 0;
}