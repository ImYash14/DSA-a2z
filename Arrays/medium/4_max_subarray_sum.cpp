#include<iostream>
#include<vector>
using namespace std;

void brute(vector<int> &arr, int n){
    int maxi = INT_MIN;
    for (int i = 0; i < n; i++)
    {
        for (int j = i; j < n; j++)
        {
            int sum =0;
            for (int k = i; k < j; k++)
            {
                sum = sum + arr[k];
            }
            maxi = max(sum,maxi);
            
        }
        
    }
    cout<<maxi;
    
}

void better(vector<int> &arr, int n){
    int maxi = INT_MIN;
    for (int i = 0; i < n; i++)
    {
        int sum =0;
        for (int j = i; j < n; j++)
        {
            sum+=arr[j];
            maxi = max(sum,maxi);
        }
        
    }
    cout<<maxi;
    
}

void optimal(vector<int> &arr, int n){
    int maxi =INT_MIN;
    int sum =0;
    for (int i = 0; i < n; i++)
    {
        sum  +=arr[i];
        if(sum >= maxi){
            maxi = sum;
        }
        if(sum < 0){
            sum = 0;
        }
        
    }
    if(maxi < 0) cout<<0;
    else cout<<maxi;
    
}

void printSubarray(vector<int> &arr, int n){
    int maxi =INT_MIN;
    int sum =0;
    int ansStart = -1;
    int ansEnd = -1;
    int start;
    for (int i = 0; i < n; i++)
    {
        if(sum == 0){
            start =i;
        }
        sum  += arr[i];

        if(sum >= maxi){
            maxi = sum;
            ansStart = start;
            ansEnd = i;
        }
        if(sum < 0){
            sum = 0;
        }
        
    }

    for (int i = ansStart; i <= ansEnd; i++)
    {
        cout<<arr[i]<<" ";
    }
    
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
    //optimal(arr,n);
    printSubarray(arr,n);
    
    return 0;
}