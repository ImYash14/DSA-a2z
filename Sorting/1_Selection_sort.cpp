#include<iostream>
using namespace std;

void selectionSort(int n, int arr[]){
    for (int i = 0; i <=n-2; i++) //for outer loop
    {
        int didswap = 0;
        int min = i;
        for (int j = i; j <= n-1; j++) //for inner loop
        {
            if(arr[j] < arr[min]) min = j;
        }
        swap(arr[min],arr[i]);
        didswap = 1;

        if(didswap == 0) break;

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

    selectionSort(n,arr);

    for (int i = 0; i < n; i++)
    {
        cout<<arr[i]<<" ";
    }
    

    
    return 0;
}