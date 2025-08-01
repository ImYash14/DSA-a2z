#include<iostream>
#include<bits/stdc++.h>
using namespace std;

class jobs{
    public:
    int id;
    int deadline;
    int profit;
};

bool comp(jobs val1, jobs val2){//compare based on jobs profit
    return val1.profit > val2.profit;
}

pair<int,int> greedy(jobs arr[], int n){
    sort(arr,arr+n,comp);//sort the jobs array based on decreasing profit
    int totalprofit = 0;
    int countjobs = 0;
    int maxdeadline = -1;
    for (int i = 0; i < n; i++)
    {
        maxdeadline = max(maxdeadline, arr[i].deadline);
    }
    vector<int>hasharr(maxdeadline + 1,-1);//for marking the days with job id

    for (int i = 0; i < n; i++) //for the job ids
    {
        for (int j = arr[i].deadline; j >0; j--) //check if the given job id can be performed or not
        {
            //if this if-statement is not performed
            //means, that day was assigned to some other job id
            //hence we will check for the lesser deeadlines for the current job id
            if(hasharr[j] == -1){//if job not assigned for that day
                countjobs = countjobs+1;
                hasharr[j] = arr[i].id; //mark that day with current job id
                totalprofit = totalprofit + arr[i].profit;
                break; //break out after the job is assigned
            }
        }
        
    }
    return {countjobs,totalprofit};   
}

int main()
{
    int n;
    cout<<"enter the no. of jobs: ";
    cin>>n;

    jobs*arr = new jobs[n];
    for (int i = 0; i < n; i++)
    {
        cin>>arr[i].id>>arr[i].deadline>>arr[i].profit;
    }
    
    pair<int,int>output = greedy(arr,n);
    cout<<output.first<<" "<<output.second;

    return 0;
}