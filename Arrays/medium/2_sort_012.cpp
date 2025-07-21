#include<iostream>
#include<vector>
using namespace std;

void better(vector<int> &arr, int n){
    int count0 , count1, count2 =0;

    for (int i = 0; i < n; i++)
    {
        if(arr[i]==0) {count0++;}
        else if(arr[i]==1) {count1++;}
        else count2++;
    }

    for (int i = 0; i < count0; i++)
    {
        arr[i] = 0;
    }
    for (int i = count0; i < count0 + count1; i++)
    {
        arr[i] =1;
    }

    for (int i = count0 + count1; i < n; i++)
    {
        arr[i] = 2;
    }
       
}

void optimal(vector<int> &arr, int n){
    int low =0;
    int mid = 0;
    int high = n-1;

    while(mid <= high){
        if(arr[mid]==0){
            swap(arr[mid],arr[low]);
            low++;
            mid++;
        }
        else if(arr[mid] == 1){
            mid++;
        }
        else
        {
            swap(arr[mid],arr[high]);
            high--;
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
        cin>>arr[i]; //only 0,1,2
    }

    optimal(arr,n);

    for (int i = 0; i < n; i++)
    {
        cout<<arr[i]<<" ";
    }
    
    
    return 0;
}