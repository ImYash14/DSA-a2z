#include<iostream>
#include<bits/stdc++.h>
using namespace std;

int fun(int start, int goal){
    //step1->take xor of start and goal
    int ans = start^goal;

    //step2->count the set bits in ans
    int count =0;
    while(ans != 0){
        ans = (ans & (ans-1));
        count++;
    }
    return count;
}

int main()
{
    int start;
    cout<<"enter the start: ";
    cin>>start;

    int goal;
    cout<<"enter the goal: ";
    cin>>goal;

    cout<<fun(start,goal);
    return 0;
}