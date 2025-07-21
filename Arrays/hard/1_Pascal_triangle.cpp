#include<iostream>
#include<bits/stdc++.h>
using namespace std;

int nCr(int row, int col){
    //type1-> for given row and column, print element
    int res =1;
    for (int i = 0; i < col; i++)
    {
        res = res*(row - i);
        res = res/(i+1);
    }
    return res;
    
}

void brute1(int n){
    //type2-> for given row no. , print entire row
    for (int i = 1; i <= n; i++)
    {
        nCr(n-1,i-1);
    }
    
}

void optimal1(int n){
    //type2->for given row no., print entire row
    int ans =1;
    cout<<ans;
    for (int i = 1; i < n; i++)
    {
        ans = ans*(n-i);
        ans = ans/i;
        cout<<ans;
    }
    
}

void brute2(int n){
    //type3-> print pascal triangle for a given n
    int ans;
    for (int i = 1; i <= n; i++) //for row
    {
        for (int j = 1; j <= i; j++)  //for column
        {
           ans = (nCr(i-1,j-1));
           cout<<ans<<" ";
        }
        cout<<endl;
        
    }
    
}

void optimal2(int n){
    //type3-> print pascal triangle for a given n
    for (int i = 1; i <= n; i++) //for row
    {
        cout<<optimal1<<endl;
        
    }
    
}
int main()
{
    // int row, col;
    // cout<<"enter the row no. and column no.: ";
    // cin>>row;
    // cin>>col;

    int n;
    cout<<"enter the row no.: ";
    cin>>n;

    // nCr(row-1,col-1);
    // brute(n);
    // optimal(n);
    // brute2(n);
    optimal2(n);
    return 0;
}