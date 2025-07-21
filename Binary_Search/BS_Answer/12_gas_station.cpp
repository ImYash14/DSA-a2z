#include<iostream>
#include<bits/stdc++.h>
using namespace std;

long double brute(vector<int>&arr, int n, int k){
    vector<int> howMany(n-1,0); //this will keep track of no.of stations on each sections
    for (int gas = 1; gas <= k; gas++)
    {
        long double maxVal =-1;
        long double maxIndex =-1;
        for (int i = 0; i < n-1; i++)
        {
            long double diff = arr[i+1] - arr[i];
            long double secLen = (diff/howMany[i] +1);
            if(maxVal < secLen){
                maxVal = secLen;
                maxIndex = i;
            }
        }
        howMany[maxIndex]++;        
    }
    
    long double maxAns =-1;
    for (int i = 0; i < n-1; i++)
    {
        long double diff = arr[i+1] -arr[i];
        long double secLen = (diff/howMany[i] + 1);
        maxAns = max(maxAns,secLen);
    }

    return maxAns;
    
}

int better(vector<int>&arr, int n, int k){
    vector<int> howMany(n-1,0);
    priority_queue<pair<long double,int>> pq;
    for (int i = 0; i < n-1; i++)
    {
        pq.push({arr[i+1]-arr[i],i});
    }

    for (int gas = 1; gas <= k; gas++)
    {
        int tp = pq.top().second; //max distance
        pq.pop();
        int secInd = tp;
        howMany[secInd]++; //for no. of stations in a section

        int inidiff = arr[secInd+1] - arr[secInd];
        int newsecLen = (inidiff/howMany[secInd] +1);
        pq.push({newsecLen,secInd});
    }
    return pq.top().first;
    
}

int maxMinus(vector<int>&arr, int n){
    int ans =-1;
    for (int i = 0; i < n-1; i++)
    {
        ans = max(ans, arr[i+1] - arr[i]);
    }
    return ans;
    
}

int fun(vector<int>&arr, int n, int distance){
    int stations =0;
    for(int i =1; i<=n; i++){
        int numinBw = (arr[i]-arr[i-1])/distance;
        if((arr[i]-arr[i-1])/distance == numinBw/distance){
            numinBw--;
        }
        stations+=numinBw;
    }
    return stations;
}
int optimal(vector<int>&arr, int n, int k){
    int low =0;
    int high = maxMinus(arr,n);
    while(high - low > 1e-6){
        long double mid = (low+high)/2.0;

        if(fun(arr,n,mid) <= k){
            high = mid;
        }
        else{
            low = mid;
        }
    }
    return high;
}
int main()
{
    int n;
    cout<<"enter the size of array of gas station locations: ";
    cin>>n;
    vector<int> arr(n);
    for (int i = 0; i < n; i++)
    {
        cin>>arr[i];
    }

    int k;
    cout<<"enter the no. of gas stations to be inserted: ";
    cin>>n;
    
    cout<<brute(arr,n,k);

    return 0;
}