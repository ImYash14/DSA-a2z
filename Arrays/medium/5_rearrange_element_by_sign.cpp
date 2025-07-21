#include<iostream>
#include<vector>
#include<list>
using namespace std;

void brute(vector<int> &arr, int n){
    // vector<int> pos;
    // vector<int> neg;
    
    // //step1
    // for (int i = 0; i < n; i++)
    // {
    //     if(arr[i]>0) pos.push_back(arr[i]);
    //     else neg.push_back(arr[i]);
    // }

    // //step2
    // for (int i = 0; i < n; i++)
    // {
    //    if(i%2==0) arr[i] = pos[i];
    //    else arr[i] = neg[i];
    // }

    vector<int> pos;
    vector<int> neg;
    
    // Step 1: Separate positive and negative numbers
    for (int i = 0; i < n; i++) {
        if (arr[i] > 0) pos.push_back(arr[i]);
        else neg.push_back(arr[i]);
    }

    // Step 2: Merge alternately
    int i = 0, p = 0, ng = 0;
    while (p < pos.size() && ng < neg.size()) {
        if (i % 2 == 0) arr[i++] = pos[p++];
        else arr[i++] = neg[ng++];
    }

    // Step 3: Append remaining elements (if any)
    while (p < pos.size()) arr[i++] = pos[p++];
    while (ng < neg.size()) arr[i++] = neg[ng++];
    
    

}

void optimal(vector<int> &arr, int n){
    vector<int> ans(n);
    int pos = 0;
    int neg = 1;

    for (int i = 0; i < n; i++)
    {
        if(arr[i]<0){
            ans[neg] = arr[i];
            neg+=2;
        }
        else{
            ans[pos] = arr[i];
            pos+=2;
        }
    }

    for (int i = 0; i < n; i++)
    {
        cout<<ans[i]<<" ";
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
    
    optimal(arr,n);

    // for (int i = 0; i < n; i++)
    // {
    //     cout<<arr[i]<<" ";
    // }
    
    // return 0;
}