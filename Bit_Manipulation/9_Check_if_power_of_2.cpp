#include<iostream>
#include<bits/stdc++.h>
using namespace std;

bool optimal(int num){
    if((num & (num-1)) == 0) return true;
    return false;
}

int main()
{
    int num;
    cout<<"enter the num: ";
    cin>>num;

    cout<<optimal(num);
    return 0;
}