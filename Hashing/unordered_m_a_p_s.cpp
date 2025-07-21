#include<iostream>
#include<vector>
#include<map>
#include<unordered_map>
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
    unordered_map<int, int> mpp;
    for (int i = 0; i < n; i++)
    {
        mpp[arr[i]]++;
    }

    for(auto it: mpp){
        cout<<it.first<<"->"<<it.second<<endl;
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