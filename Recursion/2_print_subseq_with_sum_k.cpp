#include<iostream>
#include<bits/stdc++.h>
using namespace std;

void fun(int index, int sum, vector<int>&ds, vector<int>&arr,int n, int k){
    if(index == n){
        if(sum == k){
            for(auto it : ds){
                cout<<it<<" ";
            }
            cout<<endl;
        }
        return;
    }

    //for take
    ds.push_back(arr[index]);
    sum = sum + arr[index];
    fun(index+1,sum,ds,arr,n,k);
    
    //while coming back
    ds.pop_back(); //remove that ele from ds
    sum = sum - arr[index]; //subtract the sum for that element

    //for not-take
    fun(index+1,sum,ds,arr,n,k);

}
int main()
{
    int n;
    cout<<"enter the size of arr: ";
    cin>>n;
    vector<int>arr(n);
    for (int i = 0; i < n; i++)
    {
        cin>>arr[i];
    }
    int k;
    cout<<"enter the sum: ";
    cin>>k;
    vector<int>ds;
    
    fun(0,0,ds,arr,n,k);
    return 0;
}