#include<iostream>
using namespace std;

bool checkPalindrome(int i, string arr[],int n){
    if(i>= n/2) return true;
    if(arr[i] != arr[n-i-1]) return false;
    else
    return checkPalindrome(i+1, arr, n);
}
int main()
{
    
    int n;
    
    cout<<"enter the size of array: ";
    cin>>n;

    string arr[50];
    for (int i = 0; i < n; i++)
    {
        cin>>arr[i];
        
    }

    checkPalindrome(0,arr,n);
}