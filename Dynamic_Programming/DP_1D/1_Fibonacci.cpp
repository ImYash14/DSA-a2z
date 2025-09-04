#include<iostream>
#include<bits/stdc++.h>
using namespace std;

//Memoization
int fibonacci(int n, vector<int>&dp){
    if(n <= 1) return n;

    //check if subproblem is already solved
    if(dp[n] != -1) return dp[n];

    //else
    //store the result of subproblem
    return dp[n] = fibonacci(n-1,dp) + fibonacci(n-2,dp);
}

//Tabulation
int fibonacci2(int n, vector<int>&dp){
    //base case
    dp[0] = 0;
    dp[1] = 1;

    //recurrence relation
    for (int i = 2; i <= n; i++)
    {
        dp[i] = dp[i-1] + dp[i-2];
    }
    return dp[n];
}

//Space optimization
int fibonacci3(int n){
    int prev2 = 0; //n-2
    int prev = 1; //n-1

    for (int i = 2; i <=n; i++)
    {
        int curr = prev + prev2;
        prev2 = prev;
        prev = curr;
    }
    
    return prev;

}

int main()
{
    int n;
    cin>>n;

    //declare the dp array for the subproblem size
    vector<int>dp(n+1,-1);

    // cout<<fibonacci(n,dp);
    // cout<<fibonacci2(n,dp);
    cout<<fibonacci3(n);

    return 0;
}