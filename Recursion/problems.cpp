#include<iostream>
using namespace std;



void printName(int i, int n){
    // print name 5 times
    if(i>n) return;
    else
    cout<<"yash"<<endl;
    
    printName(i+1,n);

}

void printNum(int i,int n){
    // print from 1 to n linearly
    if(i >n) return;
    else
    cout<<i<<endl;   
    printNum(i+1,n);
}

void printNumber(int i, int n){
    // print from n to 1 linearly
    if(i<1) return ;
    else
    cout<<i<<endl;
    printNumber(i-1,n);
    
   
}

void backtrack1(int i , int n){
    //print 1 to n using backtracking
    if(i<1) return;
    else
    backtrack1(i-1,n);
    cout<<i<<endl;
}

void backtrack2(int i, int n){
    //print n to 1 using backtracking
    if(i>n) return;
    else
    backtrack2(i+1,n);
    cout<<i<<endl;
}

int main()
{
    int n;
    int i;
    cout<<"enter the number: ";
    cin>>n;
    backtrack2(1,n);
    
    return 0;
}