#include<iostream>
#include<bits/stdc++.h>
using namespace std;

list<int> brute(vector<int> &arr, int n){
    list<int> ans;
    for (int i = 0; i < n; i++)
    {
        int count =0;
        if(find(ans.begin(), ans.end(), arr[i]) == ans.end()){
            for (int j = 0; j < n; j++)
            {
                if(arr[i] == arr[j]){
                    count++;
                }
            }
            if(count > n/3){
                ans.emplace_back(arr[i]);
            }
            
        }
        if(ans.size() == 2) break;
    }

    return ans;
    
    
}

void better1(vector<int> &arr, int n){
    map<int,int> mpp;
    for (int i = 0; i < n; i++)
    {
        mpp[arr[i]]++;
    }
    
    for(auto it: mpp){
        if(it.second > n/3){
            cout<<it.first<<" ";
        }
    }
    
}

void better2(vector<int> &arr, int n){
    map<int,int> mpp;
    list<int> lst;
    for (int i = 0; i < n; i++)
    {
        mpp[arr[i]]++;
        if(mpp[arr[i]] == n/3 + 1){
            lst.push_back(arr[i]);
        }
    }

    for(auto it: lst){
        cout<<it<<" ";
    }
    
    
}

void optimal(vector<int> &arr, int n){
    int count1 = 0;
    int element1;
    int count2 = 0;
    int element2;

    for (int i = 0; i < n; i++)
    {
        if(count1 ==  0 && arr[i] != element2){
            count1 = 1;
            element1 = arr[i];
        }
        else if(count2 ==  0 && arr[i] != element1){
            count2 = 1;
            element2 = arr[i];
        }
        else if(element1 == arr[i]) count1++;
        else if(element2 == arr[i]) count2++;
        else count1--, count2--;
    }
    cout<<element1<<" "<<element2;
    
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
    
    // list<int> result = brute(arr, n);

    // for (int val : result) {
    //     cout << val << " ";
    // }

    optimal(arr,n);
    
    return 0;
}