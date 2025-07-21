#include<iostream>
#include<bits/stdc++.h>
using namespace std;

void optimal(vector<vector<int>> &arr, int n){
    int left =0; int right = n-1;
    int top = 0; int bottom = n-1;

    while(top<= bottom && left<=right){
    //left to right
    for (int i = left; i <= right; i++)
    {
        cout<<arr[top][i]<<" ";
    }
    top++;

    //top to bottom
    for(int i = top; i<=bottom; i++){
        cout<<arr[i][right]<<" ";
    }
    right--;

    //right to left
    if(top<=bottom){
    for(int i = right; i>=left; i--){
        cout<<arr[bottom][i]<<" ";
    }
    bottom--;
    }

    //bottom to top
    if(left<=right){
    for(int i = bottom; i>=top; i--){
        cout<<arr[i][left]<<" ";
    }
    left++;
    }

    
    }
    
}
int main()
{
    int n;
    cout<<"enter the size of 2d array: ";
    cin>>n;
    

    vector<vector<int>> arr(n, vector<int>(n)); 

    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            cin>>arr[i][j];
        }
        cout<<endl;
        
    }

    optimal(arr,n);

    return 0;
}