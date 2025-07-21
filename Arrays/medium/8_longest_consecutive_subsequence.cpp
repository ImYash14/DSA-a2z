#include<iostream>
#include<bits/stdc++.h>
using namespace std;

int linearSearch(vector<int> &arr, int num,int n){
    for (int i = 0; i < n; i++)
    {
        if(arr[i]==num){
            return true;
        }
    }
    return false;
}

void brute(vector<int> &arr, int n){ 
    int longest =1;

    for (int i = 0; i < n; i++)
    {
        int count =1;
        int x = arr[i];
        while(linearSearch(arr,x+1,n)==true){
            x = x+1;
            count++;
            longest = max(count,longest);
        }
    }
    cout<<longest;
    
}

void better(vector<int> &arr, int n){
    sort(arr.begin(),arr.end());
    
    int count =0;
    int longest =1;
    int lastSmaller = INT_MIN;

    for (int  i = 0; i < n; i++)
    {
        if(arr[i]-1 == lastSmaller){
            count++;
            lastSmaller=arr[i];
        }
        else if(arr[i] != lastSmaller){
            count =1;
            lastSmaller = arr[i];
        }
        longest= max(count,longest);
    }
    cout<<longest;
    
}

void optimal(vector<int> &arr, int n){
    int longest =1;
    set<int>st;
    for (int i = 0; i < n; i++)
    {
        st.insert(arr[i]);
    }

    for(auto it: st){
        if(st.find(it-1) == st.end()){ //if there is no one less the element
            int count =1;
            int x = it;
            while(st.find(x+1) != st.end()){ //for the given element, if there is subsequence
                x = x+1;
                count++;
            }
            longest = max(count, longest);
        }
    }
    cout<<longest;
    
}
int main()
{
    int n;
    cout<<"enter the size of array: ";
    cin>>n;
    vector<int> arr(n);

    for (int i = 0; i < n; i++)
    {
        cin>>arr[i];
    }

    // optimal(arr,n);
    better(arr,n);
    
    return 0;
}