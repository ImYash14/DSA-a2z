#include<iostream>
#include<vector>
#include<map>
using namespace std;

void brute1(vector<int> &arr, int n, int k){
    int len =0;
    for (int i = 0; i < n; i++)
    {
        for (int j = i; j < n; j++)
        {
            int sum =0;
            for (int x = i; x <= j; x++)            
            {
                sum += arr[x]; //for subarray           
                
            }
            if(sum == k){
                    len = max(len,j-i+1);
            }
        }
        
    }
    cout<<len;
    
}

void brute2(vector<int> &arr, int n, int k){
    int len =0;
    for (int i = 0; i < n; i++)
    {
        int sum =0;
        for (int j = i; j < n; j++)
        {
            sum += arr[j];
            if(sum == k){
                len = max(len,j-i+1);
            }
        }
        
    }
    cout<<len;
    
}

void better1(vector<int> &arr, int n, int k){
    long long int presum = 0;
    int maxlen =0;
    map<long long int, int> mpp;

    for (int i = 0; i < n; i++)
    {
        presum = presum + arr[i];
        if(presum == k){
            maxlen = max(maxlen, i+1);
        }
        long long int rem = presum - k;

        if(mpp.find(rem) != mpp.end()){
            int len = i - mpp[rem];
            maxlen = max(len , maxlen);
        }
        mpp[presum] =i;
    }

    cout<<maxlen;
        
}

void better2(vector<int> &arr, int n, int k){
    //this code is optimal for arrays containing positives and negatives
    //but not for arrays containing only positives and zeros
    long long int presum = 0;
    int maxlen =0;
    map<long long int, int> mpp;

    for (int i = 0; i < n; i++)
    {
        presum = presum + arr[i];
        if(presum == k){
            maxlen = max(maxlen, i+1);
        }
        long long int rem = presum - k;

        if(mpp.find(rem) != mpp.end()){
            int len = i - mpp[rem];
            maxlen = max(len , maxlen);
        }
        if(mpp.find(presum) == mpp.end()){
            mpp[presum] =i;
        }
    }

    cout<<maxlen;
        
}

void optimal(vector<int> &arr, int n, int k){
    int sum = 0; int len =0;
    int up =0, down = 0;

    while (up < n)
    {
        sum = sum+ arr[up];
        
        while(sum>k && down<= up){
            sum= sum-arr[down];
            down++;
        }
        if(sum == k){
            len = max(len,up - down +1);
        }
        
        up++;
    }

    cout<<len;
    
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

    int k;
    cout<<"enter the sum: ";
    cin>>k;

    optimal(arr,n,k);

    return 0;
}