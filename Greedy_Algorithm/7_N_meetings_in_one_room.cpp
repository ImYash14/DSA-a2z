#include<iostream>
#include<bits/stdc++.h>
using namespace std;

class meetings{
    public:
    int starttime;
    int endtime;
    int pos;
};

//sort the arr based on increasing endtime
bool comp(meetings val1, meetings val2){
    return val1.endtime < val2.endtime;
}

vector<int>greedy(vector<int>&start, vector<int>&end, int n){
    meetings* arr = new meetings[n];
    for (int i = 0; i < n; i++)
    {
        arr[i].starttime = start[i];
        arr[i].endtime = end[i];
        arr[i].pos = i+1;//1 based indexing
    }

    //sort the arr based on increasing endtime
    sort(arr,arr+n,comp);

    //take a data structure for marking positions
    vector<int>ds = {arr[0].pos}; //marks the first as it has smallest endtime
    int freetime = arr[0].endtime; //time the meeting lasts
    int count = 1;//meetings count
    for (int i = 1; i < n; i++)
    {
        if(arr[i].starttime > freetime){
            count = count+1;
            freetime = arr[i].endtime;
            ds.push_back(arr[i].pos);
        }
    }
    return ds;
}

int main()
{
    int n;
    cout<<"enter the no. of meetings: ";
    cin>>n;
    vector<int>start(n);
    for (int i = 0; i < n; i++)
    {
        cin>>start[i];
    }
    vector<int>end(n);
    for (int i = 0; i < n; i++)
    {
        cin>>end[i];
    }

    vector<int>output = greedy(start,end,n);
    for(auto it : output){
        cout<<it<<" ";
    }   
    
    return 0;
}