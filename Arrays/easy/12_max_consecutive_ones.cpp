#include<iostream>
#include<vector>
using namespace std;

int optimal(vector<int> &arr, int n){
    int count =0;
    int max =0;
    for (int i = 0; i < n; i++)
    {
        if(arr[i] == 1){
            count++;
            if(count>max){
                max = count;
            }
        }
        else count =0;
    }

    return max;
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
    
    cout<<optimal(arr,n);
    
    return 0;
}