#include<iostream>
#include<bits/stdc++.h>
using namespace std;

void DFS(string word,string start, vector<string>&sequence,map<string,int>&mpp,
vector<vector<string>>&ans){
    if(word == start){
        vector<string>temp = sequence;
        reverse(temp.begin(),temp.end());
        ans.push_back(temp);
        return;
    }

    string nextword = word;
    int currlevel = mpp[word];
    for (int i = 0; i < word.size(); i++)
    {
        char org = nextword[i];
        for (char ch = 'a'; ch <= 'z'; ch++)
        {
            nextword[i] = ch;
            if((mpp.find(nextword) != mpp.end()) && mpp[nextword] == currlevel-1){
                sequence.push_back(nextword);
                DFS(nextword,start,sequence,mpp,ans);

                //while returning
                sequence.pop_back();
            }
        }
        nextword[i] = org;
    }
    

}

vector<vector<string>> wordladder(string start,string target,vector<string>&wordlist){
    //step1->perform word ladder part1
    //and for every word,find the steps
    set<string>st(wordlist.begin(),wordlist.end());
    queue<string>q;
    q.push(start);
    st.erase(start);

    map<string,int>mpp; //(word,level)
    mpp[start] = 0;
    while(!q.empty()){
        string word = q.front();
        q.pop();
        int level = mpp[word];

        //optimization
        if(word == target) break;

        for (int i = 0; i < word.size(); i++)
        {
            char original = word[i];
            for (char ch = 'a'; ch <= 'z'; ch++)
            {
                word[i] = ch;
                if(st.find(word) != st.end()){
                    q.push(word);
                    mpp[word] = level + 1;
                    st.erase(word);
                }
            }
            word[i] = original;
        }
        
    }

    //step2->backtrack in the map from end to begin
    vector<vector<string>>ans;
    if(mpp.find(target) != mpp.end()){
        vector<string>sequence;
        sequence.push_back(target);
        DFS(target,start,sequence,mpp,ans);
    }
    return ans;
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
    
    vector<vector<string>>output = wordladder(start,target,wordlist);
    for(auto it : output){
        for(string s : it){
            cout<<s<<" ";
        }
        cout<<endl;
    }
    
    return 0;
}