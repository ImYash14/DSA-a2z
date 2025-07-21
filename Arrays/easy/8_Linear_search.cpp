#include<iostream>
#include<vector>
using namespace std;

void binarySearch(vector<int> &arr, int n, int num){
    for (int i = 0; i < n; i++)
    {
        if(arr[i] == num){
            cout<<i;
        }
       
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
    
    int num;
    cout<<"enter the no. to search: ";
    cin>>num;

    binarySearch(arr,n,num);
    return 0;
}