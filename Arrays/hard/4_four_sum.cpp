#include<iostream>
#include<bits/stdc++.h>
using namespace std;

vector<vector<int>> brute(vector<int> &arr, int n, int target){
    set<vector<int>> st;
    for (int i = 0; i < n; i++)
    {
        for (int j = i+1; j < n; j++)
        {
            for (int k = j+1; k < n; k++)
            {
                for (int l = k+1; l < n; l++)
                {
                    if(arr[i] + arr[j] +arr[k] +arr[l] == target){
                        vector<int> temp = {arr[i], arr[j], arr[k], arr[l]};
                        sort(temp.begin(), temp.end());
                        st.insert(temp);
                    }
                }
                
            }
            
        }
        
    }
    vector<vector<int>> ans(st.begin(), st.end());
    return ans;
    
}

vector<vector<int>> better(vector<int> &arr, int n, int target){
    set<vector<int>> st;
    for (int i = 0; i < n; i++)
    {
        for (int j = i+1; j < n; j++)
        {
            set<int> hashset;            
            for (int k = j+1; k < n; k++)
            {
                int fourth = target-(arr[i] + arr[j] + arr[k]);
                if(hashset.find(fourth) != hashset.end()){
                    vector<int> temp = {arr[i], arr[j], arr[k], fourth};
                    sort(temp.begin(), temp.end());
                    st.insert(temp);
                }
                hashset.insert(arr[k]);
            }
            
        }
        
    }
    vector<vector<int>> ans(st.begin(), st.end());
    return ans;
    
}

vector<vector<int>> optimal(vector<int> &arr, int n , int target){
    sort(arr.begin(), arr.end());
    vector<vector<int>> ans;
    for (int i = 0; i < n; i++)
    {
        if(i>0 && arr[i] == arr[i-1]) continue;
        for (int j = i+1; j < n; j++)
        {
            if(j>i+1 && arr[j] == arr[j-1]) continue;
            int k = j+1;
            int l = n-1;
            while(k<l){
                int sum = arr[i] + arr[j] + arr[k] + arr[l];
                if(sum < target) k++;
                else if(sum > target) l--;
                else{
                    vector<int> temp = {arr[i], arr[j], arr[k], arr[l]};
                    ans.push_back(temp);
                    k++;
                    l--;
                    while(k<l && arr[k] == arr[k-1]) k++;
                    while(k<l && arr[l] == arr[l+1]) l--;
                }
            }
        }
        
    }
    return ans;
    
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
    int target;
    cout<<"enter the target: ";
    cin>>target;

    // vector<vector<int>> result = brute(arr, n, target);
    // vector<vector<int>> result = better(arr, n, target);
    vector<vector<int>> result = optimal(arr, n, target);

    for(auto it : result){
        for(int num : it){
            cout<<num<<" ";
        }
        cout<<"\n";
    }
    
    return 0;
}