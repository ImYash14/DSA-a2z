#include<iostream>
#include<bits/stdc++.h>
using namespace std;

bool fun(string s, int index, int count){
    if(count < 0) return false;
    if(index == s.size()){
        return (count==0);
    }

    if(s[index] == '('){
        return fun(s,index+1,count+1);
    }
    if(s[index] == ')'){
        return fun(s,index+1,count-1);
    }

    //for s[i]=='*'
    return fun(s,index+1,count+1)||fun(s,index+1,count-1)||fun(s,index+1,count);
}

bool brute(string s){
    //using recursion
    return fun(s,0,0);
}

bool optimal(string s){
    //maintain ranges
    int mini =0;
    int maxi =0;

    for (int i = 0; i < s.size(); i++)
    {
        if(s[i]=='('){
            mini = mini+1;
            maxi = maxi+1;
        }
        else if(s[i]==')'){
            mini = mini-1;
            maxi = maxi-1;
        }
        else{
            mini = mini-1;//for * ,at min, mini will decrease by 1
            maxi = maxi+1;//for * ,at max, maxi will increase by 1
        }

        if(mini<0) mini =0;
        if(maxi<0) return false;
    }
    return (mini == 0);
}

int main()
{
    string s;
    cout<<"enter the string: ";
    cin>>s;

    // cout<<brute(s);
    cout<<optimal(s);

    return 0;
}