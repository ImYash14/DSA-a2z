#include<iostream>
#include<vector>
#include<set>
using namespace std;

void brute(vector<int> &arr, int n){
    set<int> st;
    //first pass
    for (int i = 0; i < n; i++)
    {
        st.insert(arr[i]);
    }
    
    //second pass
    int index =0;
    for(auto it: st){
        arr[index] = it;
        index++;
    }
    cout<<index<<endl;
    
}

void optimal(vector<int> &arr, int n){
    int i = 0;
    for (int j = 1; j < n; j++){

        if(arr[j] != arr[i]){
            arr[i+1] = arr[j];
            i++;
        }
    }
    cout<<i+1<<endl;
    
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
    
    // optimal(arr, n);
    brute(arr, n);

    for (int i = 0; i < n; i++)
    {
        cout<<arr[i]<<" ";
    }
    
    
    return 0;
}