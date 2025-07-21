#include<iostream>
using namespace std;

int factorial1(int n){
    if(n==0) return 1;
    else
    return n*factorial1(n-1);
}

void factorial2(int i, int prod){
    if(i<1)
    {
        cout<<prod;
        return;
    }
    else
    factorial2(i-1, prod*i);
}
int main()
{
    int n;
    cout<<"enter the no.:";
    cin>>n;
    factorial2(n,1);
    
    return 0;
}