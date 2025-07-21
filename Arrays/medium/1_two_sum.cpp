#include<iostream>
#include<vector>
#include<map>
#include<algorithm>
using namespace std;

void brute(vector<int> &arr, int n, int target){
    for (int i = 0; i < n; i++)
    {
        for (int j = i+1; j < n; j++)
        {
            if(i==j) continue;
            if(arr[i]+arr[j] == target){
                cout<<arr[i]<<" "<<arr[j];
            }
            else cout<<"no";
        }
        
    }
    
}

void better(vector<int> &arr, int n, int target){
    map<int,int> mpp;
    for (int i = 0; i < n; i++)
    {
        int num = arr[i];
        int more = target - num;
        if(mpp.find(more) != mpp.end()){
            cout<<mpp[i]<<" "<<mpp[more];
        }
        mpp[arr[i]] = i;
    }
    
}

void optimal(vector<int> &arr, int n, int target){
    int front = 0;
    int end = n-1;

    sort(arr.begin(), arr.end());

    while(front < end){
        int sum = arr[front] + arr[end];
        if(sum ==target){
            cout<<"yes";
        }
        else if(sum<target){
            front++;
        }
        else end--;
    }
    cout<<"no";
}
int main()
{
    int n;
    cout<<"enter the size of array: ";
    cin>>n;
    vector<int> arr;

    for (int i = 0; i < n; i++)
    {
        cin>>arr[i];
    }
    
    int target;
    cout<<"enter the target: ";
    cin>>target;

    //better(arr,n,target);
    optimal(arr,n,target);
    
    return 0;
}