#include<iostream>
#include<bits/stdc++.h>
using namespace std;

int brute(string s){
    int maxLen = 0;
    for (int i = 0; i < s.size(); i++)
    {
        int len =0;
        vector<int>hasharr(256,0);
        for (int j = i; j < s.size(); j++)
        {
            if(hasharr[s[j]] == 1) break;//already visited, repeating
            len = j-i+1;
            maxLen = max(maxLen, len);
            hasharr[s[j]] = 1; //mark visited
        }
        
    }
    return maxLen;
}

int optimal(string s){
    int maxLen =0;
    map<char,int>mpp;
    int l=0;
    int r=0;
    while(r<s.size()){
        if(mpp.find(s[r]) == mpp.end()){ //if not found in the map
            mpp[s[r]] = r; //add in the map
            maxLen = max(maxLen,r-l+1);
        }
        else if(mpp.find(s[r]) != mpp.end()){//if found in the map, repeating
            //case1-> if dup was found but it is not in our window
            if(mpp[s[r]] < l){
                mpp[s[r]] = r; //update with current index
                maxLen = max(maxLen,r-l+1);
            }
            
            //case2-> if dup was found and it is inside the window
            l = mpp[s[r]] + 1; // if(mpp[s[r]] > l)//shrink the window
            mpp[s[r]] =r; //update with current index
        }

        r++;
    }
    return maxLen;
}

int optimal2(string s){
    int maxLen =0;
    vector<int>hasharr(256,-1);
    int l=0;
    int r=0;
    while(r<s.size()){
        if(hasharr[s[r]] != -1){ //if found in hash
            if(hasharr[s[r]] >= l){//if dup was found and it is inside the window
                l = hasharr[s[r]] + 1;
            }
        }
        maxLen = max(maxLen, r-l+1);
        hasharr[s[r]] = r; //updation if needed and marking in hash is done in this step
        r++;
    }
    return maxLen;
}

int main()
{
    string s;
    cout<<"enter the string: ";
    cin>>s;

    // cout<<brute(s);
    cout<<optimal(s);
    // cout<<optimal2(s);

    return 0;
}