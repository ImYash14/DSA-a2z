#include<iostream>
#include<bits/stdc++.h>
using namespace std;

int brute(int num){
    int count =0;
    while(num >0){
        if(num%2 == 1) count++;
        num = num/2;
    }
    return count;
}

int better(int num){
    int count =0;
    while(num > 0){
        count += (num & 1);
        num = num>>1;
    }
    return count;
}

int newMethod(int num){
    int count =0;
    while(num != 0){
        num = (num & (num-1));
        count++;
    }
    return count;
}
int main()
{
    int num;
    cout<<"enter the num: ";
    cin>>num;
    // cout<<__builtin_popcount(num);
    // cout<<brute(num);
    // cout<<better(num);
    cout<<newMethod(num);
    return 0;
}