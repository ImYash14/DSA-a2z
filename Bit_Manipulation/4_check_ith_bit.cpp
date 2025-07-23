#include<iostream>
#include<bits/stdc++.h>
using namespace std;

bool useRightShift(int num, int i){
    if(((num>>i)&1) == 0) return false;
    return true;
}

bool useLeftShift(int num, int i){
    if((num & (1<<i)) != 0) return true;
    return false;
}

bool brute(int num, int i){
    //step1->convert the num to binary
    string binary = "";
    while(num > 0){
        if(num%2 == 1) binary += '1';
        else binary += '0';

        num = num/2;
    }
    // reverse(binary); no need to reverse while checking the ith bit

    //step2->check ith bit
    if(binary[i] == '0') return false;
    else return true;
    
    return false;
}

int main()
{
    int num;
    cout<<"enter the number: ";
    cin>>num;

    int i;
    cout<<"enter the bit: ";
    cin>>i;

    // cout<<brute(num,i);
    // cout<<useLeftShift(num,i);
    cout<<useRightShift(num,i);

    return 0;
}