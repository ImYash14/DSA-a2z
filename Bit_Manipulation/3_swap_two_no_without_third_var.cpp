#include<iostream>
#include<bits/stdc++.h>
using namespace std;

void swap2num(int &a, int &b){ //pass by reference
    a = a^b;
    b = a^b;
    a = a^b;
}

int main()
{
    int a,b;
    cout<<"enter the two no.: ";
    cin>>a;
    cin>>b;

    swap2num(a,b);
    cout<<a<<" "<<b;

    return 0;
}