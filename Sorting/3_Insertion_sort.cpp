#include<iostream>
using namespace std;

void insertionSort(int n, int arr[]){
    for (int i = 0; i <=n-1; i++) //for outer loop
    {
        int didswap = 0;
        int j = i;
        while(j>0 && arr[j-1] > arr[j])//here j cannot be 0 because j-1= -1
        {
            swap(arr[j-1],arr[j]);
            didswap=1;
            j--; //move left
        }
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

    insertionSort(n,arr);

    for (int i = 0; i < n; i++)
    {
        cout<<arr[i]<<" ";
    }
    

    
    return 0;
}