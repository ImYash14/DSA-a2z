#include<iostream>
#include<bits/stdc++.h>
using namespace std;

void fun1(int col, vector<string>&board,vector<vector<string>>&ans,vector<int>&leftrow,vector<int>&upperDig,vector<int>&lowerDig, int n){
    if(col == n){
        ans.push_back(board);
        return;
    }

    for (int row = 0; row < n; row++)
    {
        if(leftrow[row] ==0 && upperDig[(n-1)+(col-row)]==0 && lowerDig[row+col]==0){
            board[row][col] = 'Q';
            //marking the hasharrays
            leftrow[row] = 1;
            upperDig[(n-1)+(col-row)] =1;
            lowerDig[row+col] =1;

            fun1(col+1,board,ans,leftrow,upperDig,lowerDig,n);
            //while returning
            board[row][col] ='.';
            //un-marking the hasharrays
            leftrow[row] = 0;
            upperDig[(n-1)+(col-row)] =0;
            lowerDig[row+col] =0;
        }
    }
    
}

vector<vector<string>> fun(int n){
    vector<vector<string>>ans;
    vector<string> board(n);
    string s(n,'.');
    for (int i = 0; i < n; i++)
    {
        board[i] = s;
    }
    
    //hasharrays
    vector<int>leftrow(n,0); //for left
    vector<int>upperDig(2*n -1,0); //for upper-left diagonal
    vector<int>lowerDig(2*n -1,0); //for lower-left diagonal  
    
    fun1(0,board,ans,leftrow,upperDig,lowerDig,n);

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