#include<iostream>
using namespace std;

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
    
    int q;
    cout<<"enter the query size: ";
    cin>>q;
    
    //precompute
    int hash[13]; //according to query size
    for (int i = 0; i < n; i++)
    {
        hash[arr[i]]++;
    }

    for (int i = 0; i < q; i++)
    {
        int number;
        cin>>number;
        //fetch
        cout<<hash[number]<<endl;
    }
    
    
    

    return 0;
}