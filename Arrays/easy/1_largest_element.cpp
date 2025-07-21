#include<iostream>
#include<vector>
#include<math.h>

using namespace std;

void brute(vector<int> &arr, int n){
    
    // sort(arr);
    // cout<<arr[n-1];

}

void optimal(vector<int> &arr,int n){
    int max = arr[0];

    for (int i = 0; i < n; i++)
    {
        if(arr[i] > max){
            max = arr[i];
        }
    }
    cout<<max;
    
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

    optimal(arr,n);
    
    return 0;
}