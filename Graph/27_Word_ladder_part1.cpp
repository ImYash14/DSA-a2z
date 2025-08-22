#include<iostream>
#include<bits/stdc++.h>
using namespace std;

int wordladder(string start, string target, vector<string>&wordlist){
    set<string>st(wordlist.begin(),wordlist.end());
    queue<pair<string,int>>q; //(word,steps)
    q.push({start,1});
    st.erase(start); //mark as visited
    while(!q.empty()){
        string word = q.front().first;
        int steps = q.front().second;
        q.pop();

        if(word == target) return steps;

        //try all possible combinations on each chars of word
        for (int i = 0; i < word.size(); i++)
        {
            char original = word[i];
            for (char ch = 'a'; ch <= 'z'; ch++)
            {
                word[i] = ch;
                //if this combination is in the wordlist
                if(st.find(word) != st.end()){
                    q.push({word,steps + 1}); //transformation
                    st.erase(word); //mark as visited
                }
            }
            word[i] = original; 
        }        
    }
    return 0;
}

int main()
{
    string start,target;
    cin>>start>>target;
    int n;
    cin>>n;
    vector<string>wordlist(n);
    for (int i = 0; i < n; i++)
    {
        cin>>wordlist[i];
    }
    
    cout<<wordladder(start,target,wordlist);
    
    return 0;
}