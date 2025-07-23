#include<iostream>
#include<bits/stdc++.h>
using namespace std;

int optimal(int num, int i){
    return (num ^(1<<i));
}
int main()
{
    int num;
    cout<<"enter the num: ";
    cin>>num;

    int i;
    cout<<"enter the bit: ";
    cin>>i;

    cout<<optimal(num,i);
    return 0;
}