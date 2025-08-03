#include<iostream>
#include<bits/stdc++.h>
using namespace std;

class item{
    public:
    int profit;
    int weight;
    int ppw;
};

bool comp(item a, item b){
    return a.ppw >= b.ppw;
}

double greedy(vector<vector<int>>&nums, int n, int W){
    item*arr = new item[n];
    for (int i = 0; i < n; i++)
    {
        arr[i].profit = nums[i][0];
        arr[i].weight = nums[i][1];
        arr[i].ppw = (double)nums[i][0]/nums[i][1];
    }
    
    sort(arr,arr+n,comp);

    double totalProfit = 0;
    int i =0;
    while(W != 0){
        if(arr[i].weight <= W){
            W = W-arr[i].weight;
            totalProfit = totalProfit + arr[i].profit;
        }
        else{
            totalProfit = totalProfit + arr[i].ppw * W;
            W =0;
            break;
        }
        i++;
    }
    return totalProfit;
}

int main()
{
    int n;
    cout<<"enter the no. of items: ";
    cin>>n;
    cout<<"enter the respective profit and weight of items: ";
    vector<vector<int>>nums(n,vector<int>(2));
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < 2; j++)
        {
            cin>>nums[i][j];
        }
        
    }

    int W;
    cout<<"enter the capacity of container: ";
    cin>>W;

    cout<<greedy(nums,n,W);
    
    return 0;
}