#include<iostream>
#include<bits/stdc++.h>
using namespace std;

int recursion(int days, int last, vector<vector<int>>&task){
    if(days == 0){
        int maxi = 0;
        for (int i = 0; i < 3; i++)
        {
            if(i != last){
                maxi = max(maxi , task[0][i]);
            }
        }
        return maxi;
    }

    int maxi =0;
    for (int i = 0; i < 3; i++)
    {
        if(i != last){
            int points = task[days][i] + recursion(days-1,i,task);
            maxi = max(maxi, points);
        }
    }
    return maxi;
}

int memoization(int days, int last, vector<vector<int>>&dp, vector<vector<int>>&task){
    if(days == 0){
        int maxi = 0;
        for (int i = 0; i < 3; i++)
        {
            if(i != last){
                maxi = max(maxi , task[0][i]);
            }
        }
        return maxi;
    }

    if(dp[days][last] != -1) return dp[days][last];

    int maxi =0;
    for (int i = 0; i < 3; i++)
    {
        if(i != last){
            int points = task[days][i] + recursion(days-1,i,task);
            maxi = max(maxi, points);
        }
    }
    return dp[days][last] = maxi;
}

int tabulation(int days,vector<vector<int>>&dp, vector<vector<int>>&task){
    dp[0][0] = max(task[0][1], task[0][2]);
    dp[0][1] = max(task[0][0], task[0][2]);
    dp[0][2] = max(task[0][0], task[0][1]);
    dp[0][3] = max(task[0][0], max(task[0][1], task[0][2]));

    for (int i = 1; i <= days-1; i++) //for days
    {
        for (int j = 0; j <= 3; j++) //for last
        {
            int maxi = 0;
            for (int k = 0; k < 3; k++) //for tasks
            {
                if(k != j){
                    int points = task[i][k] + dp[i-1][k];
                    maxi = max(maxi, points);
                }
            }
            dp[i][j] = maxi;
        }
        
    }
    return dp[days-1][3];
}

int spaceopt(int days,vector<vector<int>>&task){
    vector<int>prev(4,0);
    prev[0] = max(task[0][1], task[0][2]);
    prev[1] = max(task[0][0], task[0][2]);
    prev[2] = max(task[0][0], task[0][1]);
    prev[3] = max(task[0][0], max(task[0][1], task[0][2]));

    for (int i = 1; i <= days-1; i++) //for days
    {
        vector<int>curr(4,0);
        for (int j = 0; j <= 3; j++) //for last
        {
            curr[j] = 0;
            for (int k = 0; k < 3; k++) //for tasks
            {
                if(k != j){
                    curr[j] = max(curr[j],task[i][k] + prev[k]);
                }
            }
            prev = curr;
        }
        
    }
    return prev[3];
}

int main()
{
    int days;
    cin>>days;
    vector<vector<int>>task(days,vector<int>(3));
    for (int i = 0; i < days; i++)
    {
        for (int j = 0; j < 3; j++)
        {
            cin>>task[i][j];
        }        
    }
    
    // cout<<recursion(days-1,3,task);
    vector<vector<int>>dp(days,vector<int>(4,-1));
    cout<<memoization(days-1,3,dp,task);
    
    return 0;
}