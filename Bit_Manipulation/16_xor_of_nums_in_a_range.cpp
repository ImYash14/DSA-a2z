#include<iostream>
#include<bits/stdc++.h>
using namespace std;

int brute(int n){
    int ans =0;
    for (int i = 1; i <= n; i++)
    {
        ans = ans^i;
    }
    return ans;
}

int optimal(int n){
    if(n%4 == 1) return 1;
    else if(n%4 == 2) return n+1;
    else if(n%4 == 3) return 0;
    else return n;

    return -1;
}

int followUp(int start, int end){
    return optimal(start-1)^optimal(end);
}

int main()
{
    // int n;
    // cout<<"enter the range: ";
    // cin>>n;

    // cout<<brute(n);

    //follow-up question
    //if the range is specified
    int start;
    cout<<"enter the starting point of range: ";
    cin>>start;
    
    int end;
    cout<<"enter the ending point of range: ";
    cin>>end;

    cout<<followUp(start,end);

    return 0;
}