#include<iostream>
#include<bits/stdc++.h>
using namespace std;

bool isPalindrome(string s, int start, int end){
    while(start <= end){
        if(s[start] != s[end]) return false;
        else{
            start++;
            end--;
        }
    }
    return true;
}

void fun1(int index,string s,vector<string>&ds, vector<vector<string>>&ans){
    if(index == s.size()){
        ans.push_back(ds);
        return;
    }

    for (int i = index; i < s.size(); i++)
    {
        //check if the substrings are palindrome or not
        if(isPalindrome(s,index,i) == true){
            //take the substring
            ds.push_back(s.substr(index, i-index+1));
            fun1(i+1,s,ds,ans);

            //while returning
            ds.pop_back();
        }
    }
    
}

vector<vector<string>> fun(string s){
    vector<vector<string>>ans;
    vector<string>ds;
    fun1(0,s,ds,ans);
    return ans;
}
int main()
{
    string s;
    cout<<"enter the string: ";
    cin>>s;
    
    vector<vector<string>>output = fun(s);
    for(auto it: output){
        for(string str : it){
            cout<<str<<" ";
        }
        cout<<endl;
    }
    
    
    return 0;
}