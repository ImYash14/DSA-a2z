#include<iostream>
#include<bits/stdc++.h>
using namespace std;

pair<int,int> optimal(vector<int>&arr, int n){
    //bucket method
    //step1->take the xor of all ele in array
    long xorr = 0;
    for (int i = 0; i < n; i++)
    {
        xorr = xorr^arr[i];
    }

    //from the xor we get 1's at the bit indexes where the two ele were diff
    //step2->find the right most 1
    int rightMost = ((xorr & (xorr-1)) ^ xorr);

    //step3->differentiate the two ele based on the 1st bit
    int bucket1 = 0;
    int bucket2 =0;
    for (int i = 0; i < n; i++)
    {
        if((arr[i] & rightMost)){ //if non-zero
            bucket1 = (bucket1^arr[i]); //if 1st bit is 1
        }
        else{
            bucket2 = (bucket2^arr[i]); //if 1st bit is 0
        }
    }
    return {bucket1, bucket2};    
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
    
    pair<int,int>output = optimal(arr,n);
    cout<<output.first<<" "<<output.second;
   
    return 0;
}