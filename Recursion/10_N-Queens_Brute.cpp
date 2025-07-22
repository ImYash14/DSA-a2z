#include<iostream>
#include<bits/stdc++.h>
using namespace std;

bool isSafe(int row, int col, vector<string>&board, int n){
    int duprow = row;
    int dupcol = col;

    //for upper-left diagonal
    while(row>=0 && col>=0){
        if(board[row][col] == 'Q') return false;
        row--;
        col--;
    }

    row = duprow;
    col = dupcol;
    //for left half of row
    while(col>=0){
        if(board[row][col] == 'Q') return false;
        col--;
    }

    row = duprow;
    col = dupcol;
    //for lower-left diagonal
    while(row<n && col>=0){
        if(board[row][col] == 'Q') return false;
        row++;
        col--;
    }

    return true;
}

void fun1(int col, vector<string>&board, vector<vector<string>>&ans,int n){
    if(col == n){
        ans.push_back(board);
        return;
    }

    for (int row = 0; row < n; row++)
    {
        if(isSafe(row,col,board,n)){
            board[row][col] = 'Q';
            fun1(col+1,board,ans,n);

            //while returning
            board[row][col] = '.';
        }
    }
    
}

vector<vector<string>> fun(int n){
    vector<vector<string>>ans;
    vector<string>board(n);
    string s(n,'.');
    for (int i = 0; i < n; i++)
    {
        board[i] = s;
    }
    fun1(0,board,ans,n);
    return ans;
}
int main()
{
    int n;
    cout<<"enter the no. of queens: ";
    cin>>n;

    vector<vector<string>>output = fun(n);
    for(auto it: output){
        for(string x : it){
            cout<<x<<" ";
        }
        cout<<endl;
    }
    return 0;
}