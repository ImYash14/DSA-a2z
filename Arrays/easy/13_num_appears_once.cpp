#include<iostream>
#include<vector>
#include<map>
using namespace std;

void brute(vector<int> &arr, int n){
    for (int i = 0; i < n; i++)
    {
        int num = arr[i];
        int count = 0;
        for (int j = 0; j < n; j++) //linear search
        {
            if(arr[j]==num) count++;
        }
        if(count == 1) 
        cout<<num<<" ";
        
    }
    
}

void better1(vector<int> &arr, int n){
    //step1
    int maxi = arr[0];
    for (int i = 0; i < n; i++)
    {
        maxi = max(maxi,arr[i]);
    }

    //step2
    vector<int> hash(maxi+1);
    for (int i = 0; i < hash.size(); i++)
    {
        hash[i] = 0;        
    }
    for (int i = 0; i < hash.size(); i++)
    {
        hash[arr[i]]++;        
    }

    //step3
    for (int i = 0; i < n; i++)
    {
        if(hash[arr[i]] == 1){
            cout<<arr[i]<<" ";
        }
    }
       
}

void better2(vector<int> &arr, int n){
    //step1
    map<long int, int> mpp;
    for (int i = 0; i < n; i++)
    {
        mpp[arr[i]]++;
    }

    //step2
    for (auto it: mpp)
    {
        if(it.second == 1){
            cout<<it.first<<" ";
        }
    }
    
    
}

void optimal(vector<int> &arr, int n){
    int xor1 = 0;
    for (int i = 0; i < n; i++)
    {
        xor1 = xor1^arr[i];
    }
    cout<<xor1;
    
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

    // brute(arr,n);
    optimal(arr,n);
    
    return 0;
}