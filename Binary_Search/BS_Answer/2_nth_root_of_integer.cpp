#include<iostream>
#include<bits/stdc++.h>
using namespace std;

int fun(int i, int n){
    int ans =1;
    for (int k = 0; k < n; k++)
    {
        ans = ans*i;
    }
    return ans;
    
}

int brute(int num, int n){
    for (int i = 1; i <= num; i++)
    {
        if(fun(i,n) == num){
            return i;
        }
        else if(fun(i,n) > num){
            break;
        }
    }
    return -1;
    
}

int fun1(int mid, int n, int num){
    long long ans =1;
    for (int k = 0; k < n; k++)
    {
        ans = ans*mid;
        if(ans > num) return 2; // ans greater than num
    }
    if(ans == num) return 1; // ans equals to num
    return 0; // answer less than num
    
}
int optimal(int num, int n){
    int low = 1;
    int high = num;
    int ans =-1;
    while(low<=high){
        int mid = (low+high)/2;
        if(fun1(mid,n,num) == 0){
           low = mid+1;
        }
        else if(fun1(mid,n,num) == 1){
            return mid;
        }
        else{
            high = mid -1;
        }
    }
    return -1;
}
int main()
{
    int num;
    cout<<"enter the number: ";
    cin>>num;
    
    int n;
    cout<<"enter the root: ";
    cin>>n;

    // cout<<brute(num,n);
    cout<<optimal(num,n);
    
    return 0;
}