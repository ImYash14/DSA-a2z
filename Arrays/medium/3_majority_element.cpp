#include<iostream>
#include<vector>
#include<map>
using namespace std;

void brute(vector<int> &arr, int n){
    for (int i = 0; i < n; i++)
    {
        int count =0;
        for (int j = 0; j < n; j++)
        {
            if(arr[i] == arr[j]){
                count++;
            }
        }
        if(count > n/2){
            cout<<arr[i];
        }
        
    }
    
}

void better(vector<int> &arr, int n){
    map<int,int> mpp;
    for (int i = 0; i < n; i++)
    {
        mpp[arr[i]]++;
    }

    for(auto it: mpp){
        if(it.second > n/2){
            cout<<it.first;
        }
    }
    

}

void optimal(vector<int> &arr, int n){
    int element;
    int count =0;

    //moore's voting algorithm
    for (int i = 0; i < n; i++)
    {
        if(count == 0){
            count =1;
            element = arr[i];           
        }
        else if(element==arr[i]){
            count++;
        }
        else{
            count--;
        }
    }
    
    //for finding that if the left element is majority or not
    //we do iteration of whole array
    int count1 =0;
    for (int i = 0; i < n; i++)
    {
        if(element == arr[i]){
            count1++;
        }
    }
    if(count1 > n/2){
        cout<<element;
    }
    else
    cout<<-1;
    
    
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
    optimal(arr,n);

    
    return 0;
}