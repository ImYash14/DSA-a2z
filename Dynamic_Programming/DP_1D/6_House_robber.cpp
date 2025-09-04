#include<iostream>
#include<bits/stdc++.h>
using namespace std;

//max sum of non adjacent element
int spaceopt(int n, vector<int>&arr){
    int prev = arr[0]; //dp[i-1]
    int prev2 = 0; //dp[i-2]

    for (int i = 1; i <= n-1; i++)
    {
        int pick = arr[i];
        if(i >1) pick += prev2;
        int notpick = 0 + prev;

        int curr = max(pick, notpick);
        prev2 = prev;
        prev = curr;
    }
    return prev;
}

int houseRobber(vector<int>&arr){
    int n = arr.size();
    if(n == 1) return arr[0];

    vector<int>temp1,temp2;
    for (int i = 0; i < n; i++)
    {
        if(i != 0) temp1.push_back(arr[i]); //not considering first house
        if(i != n-1) temp2.push_back(arr[i]); //not considering last house
    }
    
    return max(spaceopt(n,temp1), spaceopt(n,temp2));
}

int main()
{
    int n;
    cin>>n;
    vector<int>arr(n);
    for (int i = 0; i < n; i++)
    {
        cin>>arr[i];
    }

    cout<<houseRobber(arr);
    
    
    return 0;
}