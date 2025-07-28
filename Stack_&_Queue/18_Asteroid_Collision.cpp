#include<iostream>
#include<bits/stdc++.h>
using namespace std;

vector<int> optimal(vector<int>&arr, int n){
    vector<int>st;
    for (int i = 0; i < n; i++)
    {
        if(arr[i] > 0){//for positive asteroids
            st.push_back(arr[i]);
        }
        else{//for negative asteroids

            //if top of stack is smaller than abs of current ele, destroy that asteroid
            while(!st.empty() && st.back()>0 && st.back()<abs(arr[i])){
                st.pop_back();
            }

            //if asteriods moving in opposite direction have same value,
            //cancel out each other
            if(!st.empty() && st.back()==abs(arr[i])){
                st.pop_back();
            }

            //if top of stack is -ve, then there will be no collision
            else if(st.empty() || st.back()<0){
                st.push_back(arr[i]);
            }
        }
    }
    return st;
}

int main()
{
    int n;
    cout<<"enter the size of array: ";
    cin>>n;
    vector<int>arr(n);
    for (int i = 0; i < n; i++)
    {
        cin>>arr[i];
    }

    vector<int>output = optimal(arr,n);
    for(auto it: output){
        cout<<it<<" ";
    }
    
    return 0;
}