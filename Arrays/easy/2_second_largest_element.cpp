#include<iostream>
#include<vector>
#include<math.h>

using namespace std;

void brute(vector<int> &arr, int n){
    int slargest;
    //sort(arr);
    int largest = arr[n-1];
    for (int i = n-2; i >= 0; i++)
    {
        if(arr[i] != largest) 
        slargest = arr[i];
        break;
    }
    cout<<slargest;
    

}

void better(vector<int> &arr, int n){
    //first pass
    int largest = arr[0];
    for (int i = 0; i < n; i++)
    {
        if(arr[i] > largest){
            largest = arr[i];
        }
    }

    //second pass
    int slargest = -1;
    for (int i = 0; i < n; i++)
    {
        if(arr[i] > slargest && arr[i] != largest){
            slargest = arr[i];
        }
    }
    cout<<slargest;
    
    
}

void optimal(vector<int> &arr,int n){
    int largest = arr[0];
    int slargest = -1;

    for (int i = 0; i < n; i++)
    {
        if(arr[i] > largest){
            slargest = largest;
            largest = arr[i];
        }
        else if(arr[i] < largest && arr[i] > slargest){
            slargest = arr[i];
        }
    }
    cout<<slargest;
    
    
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