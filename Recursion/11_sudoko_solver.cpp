#include<iostream>
#include<bits/stdc++.h>
using namespace std;

bool isValid(int row, int col,char c,vector<vector<char>>&board,int n){
    for (int i = 0; i < n; i++) //for sudoko size
    {
        //check in the rows
        if(board[row][i] == c) return false;

        //check in columns
        if(board[i][col] == c) return false;

        //check in 3x3 board
        if(board[3*(row/3) + (i/3)][3*(col/3) + (i%3)] == c)
            return false;
    }
    return true;
    
}

bool fun1(vector<vector<char>>&board,int n){
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            if(board[i][j] == '.'){
                //try all the chars till true
                for (char c = '1'; c <= '9'; c++) 
                {
                    if(isValid(i,j,c,board,n)){
                        board[i][j] = c;
                        if(fun1(board,n) == true){
                            return true;
                            //while returning if true
                            //no need to pop back that char
                        }
                        else{
                            board[i][j] = '.';
                            //while returning if false
                            //pop back the added char
                        }
                    }
                }
                
                return false; //if valid char is not find
            }
        }
        
    }
    return true; //base case
    
}

void fun(vector<vector<char>>&board,int n){
    fun1(board,n);
}
int main()
{
   vector<vector<char>> board = {
    {'5','3','.','.','7','.','.','.','.'},
    {'6','.','.','1','9','5','.','.','.'},
    {'.','9','8','.','.','.','.','6','.'},
    {'8','.','.','.','6','.','.','.','3'},
    {'4','.','.','8','.','3','.','.','1'},
    {'7','.','.','.','2','.','.','.','6'},
    {'.','6','.','.','.','.','2','8','.'},
    {'.','.','.','4','1','9','.','.','5'},
    {'.','.','.','.','8','.','.','7','9'}
    };

    int n = 9; //sudoko size
    fun(board,n);
    for(auto it: board){
        for(char num: it){
            cout<<num<<" ";
        }
        cout<<endl;
    }
    return 0;
}