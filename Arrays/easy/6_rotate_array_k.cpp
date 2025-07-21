#include<iostream>
#include<vector>
using namespace std;

void brute(vector<int> &arr, int n, int k){
    k = k%n;
    vector<int> temp(k);
    for (int i = 0; i <= k-1; i++)
    {
        temp[i] = arr[i];
    }
    
    //shifting
    for (int i = k; i < n; i++)
    {
        arr[i-k] = arr[i];
    }

    //put temp back
    int j=0;
    for (int i = n-k; i < n; i++)
    {
        arr[i] = temp[j];
        j++;
    }   
    
}

void reverse(int arr[], int front, int end){
    while(front<=end){
        int temp = arr[front];
        arr[front] = arr[end];
        arr[end] = temp;
        front ++;
        end--;
    }
}
void optimal(int arr[], int n, int k){
    k= k%n;
    reverse(arr,0,n-k-1);
    reverse(arr,n-k,n-1);
    reverse(arr,0, n-1);
}
int main()
{
    int n;
    cout<<"enter the size of array: ";
    cin>>n;

    vector<int> arr(n);
    // int arr[50];
    for (int i = 0; i < n; i++)
    {
        cin>>arr[i];
    }

    int k;
    cout<<"enter no. of places to rotate: ";
    cin>>k;

    brute(arr,n,k);
    // optimal(arr,n,k);
    
    for (int i = 0; i < n; i++)
    {
        cout<<arr[i]<<" ";
    }
    
    
    return 0;
}