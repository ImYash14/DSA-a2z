#include<iostream>
#include<vector>
using namespace std;

void brute(vector<int> &arr, int n){
    for (int i = 1; i < n; i++)// for checking
    {
        int flag =0;
        for (int j = 0; j < n-1; j++)// for array
        {
            if(arr[j] == i){
                flag = 1;
                break;
            }

        }
        if(flag==0) cout<<i<<" ";
        
    }
    
}

void better(vector<int> &arr, int n){
    vector<int> hash(n+1);
    for (int i = 0; i < n+1; i++)
    {
        hash[i] =0;
    }
    
    for (int i = 0; i < n-1; i++)
    {
        hash[arr[i]] =1;
    }

    for (int i = 1; i < n; i++)
    {
        if(hash[i] == 0){
            cout<<i<<" ";
        }
    }
        
}

void optimal(vector<int> &arr, int n){
    //sum method
    // int sum = (n*(n+1))/2;
    // int s2 =0;
    // for (int i = 0; i < n-1; i++)
    // {
    //      s2 += arr[i];
    // }
    // cout<<sum-s2;

    //xor method
    int xor1 =0;
    int xor2 =0;
    for (int i = 0; i < n-1; i++)
    {
        xor1 = xor1^(i+1);
        
        xor2 = xor2^arr[i];
    }
    xor1 = xor1^n;
    int res = xor1^xor2;
    cout<<res;
    
    
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

    //brute(arr,n);
    //better(arr,n);
    optimal(arr,n);
    
    return 0;
}