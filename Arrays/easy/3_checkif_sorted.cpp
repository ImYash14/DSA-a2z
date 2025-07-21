#include<iostream>
#include<vector>
using namespace std;

bool checkSort(vector<int> &arr, int n){
    for (int i = 1; i < n; i++)
    {
        if(arr[i] >= arr[i-1]) {}
        else 
        {
            return false;
            break;
        }
    }
    cout<<"sorted";
    
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

    checkSort(arr,n);
    
    return 0;
}