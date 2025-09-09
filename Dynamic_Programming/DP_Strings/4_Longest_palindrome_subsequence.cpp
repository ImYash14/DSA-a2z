#include<iostream>
#include<bits/stdc++.h>
using namespace std;

int spaceopt(string&s1, string&s2){
    int n = s1.size();
    int m = s2.size();

    //right shift indexes by 1
    //new base case of recursion
    //if(i==0 || j==0) return 0;

    vector<int>prev(m+1,0);
    //base case
    for (int j = 0; j <= m; j++)
    {
        prev[j] = 0;
    }
    
    //for loop for states in recerse of recursion
    for (int i = 1; i <= n; i++)
    {
        vector<int>curr(m+1,0);
        for (int j = 1; j <= m; j++)
        {
            if(s1[i-1] == s2[j-1]) curr[j] = 1 + prev[j-1];
            else curr[j] = 0 + max(prev[j], curr[j-1]);
        }
        prev = curr;
    }
    return prev[m];
}

int main()
{
    string s;
    cin>>s;

    string s2 =s;
    reverse(s2.begin(),s2.end());
    cout<<spaceopt(s,s2);
    
    return 0;
}