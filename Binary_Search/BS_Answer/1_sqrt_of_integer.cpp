#include<iostream>
#include<bits/stdc++.h>
using namespace std;

int brute(int num){
    int ans =1;
    for (int i = 1; i <= num; i++)
    {
        if(i*i <= num){
            ans = i;
        }
        else break;
    }
    return ans;
    
}

int optimal(int num){
    int low =0;
    int high = num;
    int ans;
    while(low <= high){
        int mid = (low+high)/2;
        if(mid*mid == num) return mid;
        else if(mid*mid < num){
            ans = mid;
            low = mid+1;
        }
        else{
            high = mid -1;
        }
    }
    return ans;
}
int main()
{
    int num;
    cout<<"enter the number: ";
    cin>>num;

    // cout<<brute(num);
    cout<<optimal(num);
    return 0;
}