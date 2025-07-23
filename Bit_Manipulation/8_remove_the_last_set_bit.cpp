#include<iostream>
#include<bits/stdc++.h>
using namespace std;

int optimal(int num){
    return (num & (num-1));
}

int main()
{
     int num;
    cout<<"enter the num: ";
    cin>>num;

    cout<<optimal(num);
    return 0;
}