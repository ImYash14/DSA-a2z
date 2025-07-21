#include<bits/stdc++.h>
using namespace std;

void brute(){
    //1.generate all permutations in sorted array -> O(n!)
    //2.linear search -> O(n)
    //3.next index
}

void better(vector<int> &arr, int n){
    next_permutation(arr.begin(),arr.end());
}

void reverse(vector<int> &arr,int front, int end){
    int temp;
    while(front < end)
    {
        arr[temp] = arr[front];
        arr[front] = arr[end];
        arr[end] = arr[temp];
        front++;
        end--;
    }
    
}
void optimal(vector<int> &arr, int n){
    //find breakpoint
    int index =-1;
    for (int i = n-2; i >=0; i--)
    {
        if(arr[i] < arr[i+1]){
            index =i;
            break;
        }
    }
    if(index == -1){
        reverse(arr,0,arr[n-1]);
        return;
    }
    

    //find greater than breakpoint but smallest
    for (int i = n-1; i >= index; i--)
    {
        if(arr[i] > arr[index]){
            swap(arr[i],arr[index]);
            break;
        }
    }

    //place remaining in sorted order
    reverse(arr,arr[index+1],arr[n-1]);
    
    
}
int main()
{
    int n;
    cout<<"enter the size of array: ";
    cin>> n;

    vector<int> arr(n);

    for (int i = 0; i < n; i++)
    {
        cin>>arr[i];
    }

    optimal(arr,n);

    for (int i = 0; i < n; i++)
    {
        cout<<arr[i]<<" ";
    }
    
    
    return 0;
}