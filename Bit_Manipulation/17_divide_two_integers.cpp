#include<iostream>
#include<bits/stdc++.h>
using namespace std;

int brute(int dividend, int divisor){
    int sum =0;
    int count = 0;
    while(sum <= dividend){
        sum += divisor;
        count++;
    }
    return count-1;
}

int optimal(int dividend, int divisor){
    if(dividend == divisor) return 1;

    bool sign =true; // positive
    if(dividend >= 0 && divisor < 0) sign = false; //negative
    if(dividend < 0 && divisor >= 0) sign = false; //negative

    long n = abs((long)dividend);
    long d = abs((long)divisor);
    long ans =0;
    while(n >= d){
        int count =0;
        while(n >= (d<<(count+1))){
            count++;
        }
        ans = ans + (1<<count);
        n = n - (d<<count);
    }
    
    if(ans == (1<<31) && sign) return INT_MAX;
    if(ans == (1<<31) && !sign) return INT_MIN;

    if(sign) return ans;
    else return (-1)*ans;

    return -1;
}

int main()
{
    int dividend;
    cout<<"enter the dividend: ";
    cin>>dividend;

    int divisor;
    cout<<"enter the divisor: ";
    cin>>divisor;

    // cout<<brute(dividend,divisor);
    cout<<optimal(dividend,divisor);

    return 0;
}