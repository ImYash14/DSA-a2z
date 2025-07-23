#include<iostream>
#include<bits/stdc++.h>
using namespace std;

int binary2Dec(string s){
    int n = s.size();
    int ans =0;
    int power =1;
    for (int i = n-1; i>=0; i--)
    {
        if(s[i] == '1'){
            ans = ans + power;
        }
        power = power*2;
    }
    return ans;
}

void reverse(string &s){
    int n = s.size();
    int low =0;
    int high = n-1;
    while(low<high){
        int temp = s[low];
        s[low] = s[high];
        s[high] = temp;
        low++;
        high--;
    }
}

int optimal(int num, int i){
    return (num | (1<<i));
}

int brute(int num, int i){
    string binary ="";
    while(num > 0){
        if(num%2 == 1) binary += '1';
        else binary += '0';

        num = num/2;
    }
    binary[i] = '1'; //set the ith bit
    reverse(binary);
    int ans =binary2Dec(binary);
    return ans;
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
    cout<<optimal(num,i);

    return 0;
}