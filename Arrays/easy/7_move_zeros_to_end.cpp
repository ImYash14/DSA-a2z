#include<iostream>
#include<vector>
using namespace std;

void brute(vector<int> &arr, int n){
    //step1
    vector<int> temp;
    for (int i = 0; i < n; i++)
    {
        if(arr[i] != 0){
            temp.push_back(arr[i]);
        }
    }

    //step2
    for (int i = 0; i < temp.size(); i++)
    {
        arr[i] = temp[i];
    }

    //step3
    for (int i = temp.size(); i < n; i++)
    {
        arr[i] =0;
    }
       
}

void optimal(vector<int> &arr, int n){
    //step1
    int j = -1;
    for (int i = 0; i < n; i++)
    {
        if(arr[i] == 0){
            j=i;
            break;
        }
    }

    if(j==-1) return;//no zeros found

    //step2
    for (int i = j+1; i < n; i++)
    {
        if(arr[i] != 0){
            swap(arr[i],arr[j]);
            j++;
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
    
    // brute(arr,n);
    optimal(arr,n);

    for (int i = 0; i < n; i++)
    {
        cout<<arr[i]<<" ";
    }
    
    return 0;
}