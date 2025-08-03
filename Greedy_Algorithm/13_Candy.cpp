#include<iostream>
#include<bits/stdc++.h>
using namespace std;

int brute(vector<int>&ratings, int n){
    vector<int>left(n,0); 
    vector<int>right(n,0); 
    left[0] = 1;
    right[n-1] = 1;

    //for the left neighbours
    for (int i = 1; i < n; i++)
    {
        if(ratings[i] > ratings[i-1]){
            left[i] = left[i-1]+1;
        }
        else{
            left[i] = 1;
        }
    }

    //for the right neighbours
    for (int i = n-2; i>= 0; i--)
    {
        if(ratings[i] > ratings[i+1]){
            right[i] = right[i+1]+1;
        }
        else{
            right[i] =1;
        }
    }

    //take max of left and right
    int sum =0;
    for (int i = 0; i < n; i++)
    {
        sum = sum + max(left[i],right[i]);
    }
    
    return sum;    
}

int better(vector<int>&ratings, int n){
    vector<int>left(n,0);
    left[0] = 1;

    //for the left neighbours
    for (int i = 0; i < n; i++)
    {
        if(ratings[i] > ratings[i-1]){
            left[i] = left[i-1]+1;
        }
        else{
            left[i] = 1;
        }
    }

    //calculate for right and sum in one go
    int current =1; //tells about value at current index
    int right =1; //current is one place ahead of right from back direction
    int sum = max(1,left[n-1]);//bc we left out n-1 from the back
    for (int i = n-2; i >=0; i--)
    {
        if(ratings[i] > ratings[i+1]){
            current = right+1;
            right = current;
        }
        else{
            current =1;
            right = current;
        }
        sum = sum + max(left[i],right);
    }
    
    return sum;
}

int optimal(vector<int>&ratings, int n){
    int sum =1;
    int i=1;
    while(i<n){
        //for plateau
        if(ratings[i]==ratings[i-1]){
            sum += 1;
            i++;
            continue;
        }

        //for increasing slope
        int peak =1;
        while(i<n && ratings[i] > ratings[i-1]){
            peak += 1;
            sum = sum + peak;
            i++;
        }

        //for decreasing slope
        int down = 1;
        while(i<n && ratings[i] < ratings[i-1]){
            sum = sum + down;
            down += 1;
            i++;
        }

        if(down > peak){
            sum = sum + (down-peak);
        }
    }
    return sum;
}

int main()
{
    int n;
    cout<<"enter the no. of childrens: ";
    cin>>n;
    vector<int>ratings(n);
    for (int i = 0; i < n; i++)
    {
        cin>>ratings[i];
    }

    // cout<<brute(ratings,n);
    // cout<<better(ratings,n);
    cout<<optimal(ratings,n);
    
    return 0;
}