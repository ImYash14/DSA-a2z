#include<iostream>
#include<vector>
#include<map>
using namespace std;

int main()
{
    int n;
    cout<<"enter the size of the array: ";
    cin>>n;

    int arr[50];
    for (int i = 0; i < n; i++)
    {
        cin>>arr[i];
    }

    // precompute
    map<int, int> mpp;
    for (int i = 0; i < n; i++)
    {
        mpp[arr[i]]++;
    }

    int q;
    cout<<"enter the size of query: ";
    cin>>q;
    for (int i = 0; i < q; i++)
    {
        int number;
        cin>>number;
        //fetch;
        cout<<mpp[number]<<endl;
    }
       
    return 0;
}