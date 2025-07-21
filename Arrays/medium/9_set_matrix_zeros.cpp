#include<iostream>
#include<bits/stdc++.h>
using namespace std;

void markRow(vector<vector<int>> &arr, int m,int i){
    for (int j = 0; j < m; j++)
    {
        if(arr[i][j] != 0){
            arr[i][j] = -1;
        }
    }
    
}
void markCol(vector<vector<int>> &arr, int n,int j){
    for (int i = 0; i < n; i++)
    {
        if(arr[i][j] != 0){
            arr[i][j] = -1;
        }
    }
    
}
void brute(vector<vector<int>> &arr, int n, int m){
    //first mark all non zero as -1
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            if(arr[i][j] == 0){
                markRow(arr,m,i);
                markCol(arr,n,j);
            }
        }
        
    }
    
    //next mark all -1 as 0
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            if(arr[i][j] == -1){
                arr[i][j] =0;
            }
        }
        
    }
    
    
}

void better(vector<vector<int>> &arr, int n, int m){
    vector<int> row(n,0);
    vector<int> col(m,0);
    //1st iteration
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            if(arr[i][j] == 0){
                row[i] = 1;
                col[j] = 1;
            }
        }
        
    }

    //2nd iteration
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            if(row[i] == 1 || col[j] ==1){
                arr[i][j] = 0;
            }
        }
        
    }
    
    
}

void optimal(vector<vector<int>> &arr, int n, int m){
    int col0 = 1;
    //step1
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            if(arr[i][j] == 0){
                arr[i][0] = 0;

                if(j!=0){
                    arr[0][j] =0;
                }
                else{
                    col0 = 0;
                }
            }
        }
        
    }

    //step2
    for (int i = 1; i < n; i++)
    {
        for (int j = 1; j < m; j++)
        {
            if(arr[i][j] != 0){
                if(arr[i][0] == 0 || arr[0][j] ==0){
                    arr[i][j] =0;
                }
            }
        }
        
    }

    //step3
    if(arr[0][0] == 0){
        for (int j = 0; j < m; j++)
        {
            arr[0][j] =0;
        }
        
    }
    if(col0 == 0){
        for (int i = 0; i < n; i++)
        {
            arr[i][0] = 0;
        }
    }
    
    
}
int main()
{
    int n, m;
    cout<<"enter the size of 2d array: ";
    cin>>n;
    cin>>m;

    vector<vector<int>> arr(n, vector<int>(m)); 

    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            cin>>arr[i][j];
        }
        cout<<endl;
        
    }

    brute(arr,n,m);

    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            cout<<arr[i][j]<<" ";
        }
        cout<<endl;
    }
    
    
    return 0;
}