#include<iostream>
#include<bits/stdc++.h>
using namespace std;

class StockSpanner{
    public:
    vector<int>arr;
    StockSpanner(){
        arr = {}; //initially empty
    }

    int next(int val){
        arr.push_back(val);
        int count =1; //because we need less than equalto, so we include current day as well
        for (int i = arr.size()-2; i>=0; i--) //bc we already included current day before
        {
            if(arr[i] <= val) count++;
            else break; //because we want consecutive days
        }
        return count;
    }
};

class OptimizedStockSpanner{
    private:
    vector<int> findPGE(vector<int>&arr){
        stack<int>st;
        vector<int>ans(arr.size());
        for(int i =0; i<arr.size(); i++){
            while(!st.empty() && arr[st.top()] <= arr[i]){//because we want days<=,so we skip them
                st.pop();
            }
            if(st.empty()) ans[i] =-1;
            else ans[i] = st.top();
            st.push(i);
        }
        return ans;
    }

    public:
    vector<int>arr;
    OptimizedStockSpanner(){
        arr ={};
    }

    int next(int val){
        arr.push_back(val);
        vector<int>pge = findPGE(arr);//returns the arr of index of prev greater elements
        int days =0;
        for (int i = 0; i < arr.size(); i++)
        {
            days = i-pge[i];
        }
        return days;
    }
};

class optimalStockSpan{
    stack<pair<int,int>>st; //<price,days>
    public:
    vector<int>arr;

    optimalStockSpan(){
        
    }

    int next(int val){
        arr.push_back(val);
        int days =1;
        
        while(!st.empty() && st.top().first <= val){
            days = days + st.top().second;
            st.pop();
        }
        st.push({val,days});
        
        return days;
    }
};

int main()
{
    // StockSpanner s;
    // OptimizedStockSpanner s;
    optimalStockSpan s;
    cout<<s.next(7)<<endl;
    cout<<s.next(2)<<endl;
    cout<<s.next(1)<<endl;
    cout<<s.next(3)<<endl;
    cout<<s.next(3)<<endl;
    cout<<s.next(1)<<endl;
    cout<<s.next(8)<<endl;

    
    return 0;
}