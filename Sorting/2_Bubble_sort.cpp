#include<iostream>
using namespace std;

void bubbleSort(int n, int arr[]){
    for (int i = n-1; i >= 1; i--) //for outer loop
    {
        int didSwap =0;
        for (int j = 0; j <= i-1; j++) //for inner loop
        {
            if(arr[j] > arr[j+1]){
                swap(arr[j], arr[j+1]);
                didSwap =1;
            }
        }
        if(didSwap == 0){
            break;
        }
        cout<<"swap happened"<<endl;
               
    }
    
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

    bubbleSort(n,arr);

    for (int i = 0; i < n; i++)
    {
        cout<<arr[i]<<" ";
    }
    

    
    return 0;
}