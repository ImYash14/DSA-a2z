#include<iostream>
#include<bits/stdc++.h>
using namespace std;

int brute(vector<vector<int>>&arr, int n){
    vector<int>KnowsMe(n); //someone knows him
    vector<int>IKnow(n); //he knows someone
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            if(arr[i][j] == 1){
                KnowsMe[j]++;
                IKnow[i]++;
            }
        }
        
    }

    for (int i = 0; i < n; i++)
    {
        if(KnowsMe[i]==n-1 && IKnow[i]==0){
            return i;
        }
    }
    return -1;   
}

int optimal(vector<vector<int>>&arr, int n){
    int top =0;
    int down = n-1;
    while(top<down){
        if(arr[top][down] == 1) top++;//if top knows down
        else if(arr[down][top] == 1) down--; //if down knows top
        else{
            top++;
            down--;
        }
    }
    if(top>down) return -1; //no celebrity was found

    //top=down
    for (int i = 0; i < n; i++)
    {
        if(top == i) continue;//for same persons, diagonal will always be 0
        if(arr[top][i]==0 && arr[i][top]==1){
            //a celebrity
        }
        else return -1;
    }
    return top;//or down
}

int main()
{
    int n;
    cout<<"enter the size of matrix: ";
    cin>>n;
    vector<vector<int>>arr(n,vector<int>(n));
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            cin>>arr[i][j];
        }
        
    }

    // cout<<brute(arr,n);
    cout<<optimal(arr,n);
    
    return 0;
}