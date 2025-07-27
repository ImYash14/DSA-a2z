#include<iostream>
#include<bits/stdc++.h>
using namespace std;

vector<int> brute(vector<int>&arr, int n){
    vector<int>nge(n,-1);
    for (int i = 0; i < n; i++)
    {
       bool found = false;
        for (int j = i+1; j < n; j++)
        {
            if(arr[j] > arr[i]){
                nge[i] = arr[j];
                found = true;
                break;
            }
        }
        if(!found){
            for (int k = 0; k < i; k++)
            {
                if(arr[k] > arr[i]){
                    nge[i] = arr[k];
                    break;
                }
            }
        }
        
    }
    return nge;
    
}

vector<int>better(vector<int>&arr, int n){
    vector<int>nge(n,-1);
    for (int i = 0; i < n; i++)
    {
        //this loop also traverses the hypothetical circular array
        for (int j = i+1; j <=(i+ n-1); j++)
        {
            int index = j%n; //for hypothetical indexes
            if(arr[index] > arr[i]){
                nge[i] = arr[index];
                break;
            }
        }
        
    }
    return nge;
    
}

vector<int> optimal(vector<int>&arr, int n){
    vector<int>nge(n);
    stack<int>st;
    for (int i = 2*n-1; i >=0; i--) //for hypothetical arr also
    {
        while(!st.empty() && st.top() <= arr[i%n]){
            st.pop();
        }

        if(i<n){ //for original arr we need nge
            if(st.empty()) nge[i] = -1;
            else nge[i] = st.top();
        }

        st.push(arr[i%n]);
    }
    return nge;
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
    
    // vector<int>output = brute(arr,n);
    // vector<int>output = better(arr,n);
    vector<int>output = optimal(arr,n);
    for(auto it : output){
        cout<<it<<" ";
    }

    return 0;
}