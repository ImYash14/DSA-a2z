#include<iostream>
#include<vector>
using namespace std;

void brute(vector<int> arr1, vector<int> arr2, int n1, int n2){
    vector<int> vis(n2);
    for (int i = 0; i < n2; i++)
    {
        vis[i] =0;
    }
    
    vector<int> inter;
    for (int i = 0; i < n1; i++)
    {
        for (int j = 0; j < n2; j++)
        {
            if(arr1[i] == arr2[j] && vis[j] == 0){
                inter.push_back(arr1[i]);
                vis[j] = 1;
                break;

            }
            if(arr2[j]>arr1[i]){
                break;
            }
        }
        
    }

    for (int i = 0; i < inter.size(); i++)
    {
        cout<<inter[i]<<" ";
    }
    
    
}

void optimal(vector<int> &arr1, vector<int> &arr2, int n1, int n2){
    int i =0;
    int j =0;
    vector<int> inter;
    while(i<n1 && j<n2){
        if(arr1[i]<arr2[j]) i++;
        else if(arr2[j] < arr1[i]) j++;
        else
        inter.push_back(arr1[i]);
        i++;
        j++;
    }

    for (int i = 0; i < inter.size(); i++)
    {
        cout<<inter[i]<<" ";
    }
    
}
int main()
{
    int n1;
    cout << "enter the size of first array: ";
    cin >> n1;
    vector<int> arr1(n1);
    for (int i = 0; i < n1; i++)
    {
        cin >> arr1[i];
    }

    int n2;
    cout << "enter the size of second array: ";
    cin >> n2;
    vector<int> arr2(n2);
    for (int i = 0; i < n1; i++)
    {
        cin >> arr2[i];
    }

    //brute(arr1, arr2, n1, n2);
    optimal(arr1,arr2,n1,n2);
    return 0;
}