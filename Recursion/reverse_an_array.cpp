#include<iostream>
#include<algorithm>
using namespace std;

void reversearray(int i, int arr[], int n){
    if(i>= n/2) return;
    else
    swap(arr[i],arr[n-i-1]);

    reversearray(i+1,arr,n);
}
int main()
{
    int n;
    
    cout<<"enter the size of array: ";
    cin>>n;

    int arr[50];
    for (int i = 0; i < n; i++)
    {
        cin>>arr[i];
        
    }

    reversearray(0,arr,n);

    for (int i = 0; i < n; i++)
    {
        cout<<arr[i]<<" ";
    }
    
    
    return 0;
}