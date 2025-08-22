#include<iostream>
#include<bits/stdc++.h>
using namespace std;

vector<vector<string>> wordladder(string start,string target,vector<string>&wordlist){
    set<string>st(wordlist.begin(),wordlist.end());

    queue<vector<string>>q;
    q.push({start});
    vector<string>usedonlevel;
    usedonlevel.push_back(start);

    vector<vector<string>>ans;
    int level =0;
    while(!q.empty()){
        vector<string>vec = q.front();
        q.pop();

        //erase all words from set
        //which are used in previous level to transform
        if(vec.size() > level){
            level++;
            for(auto it : usedonlevel){
                st.erase(it);
            }
        }

        string word = vec.back();
        if(word == target){ //if found the target word
            if(ans.size() == 0){ //if first sequence found
                ans.push_back(vec);
            }
            else if(ans[0].size() == vec.size()){
                ans.push_back(vec);
            }
        }

        for (int i = 0; i < word.size(); i++)
        {
            char original = word[i];
            for (char ch = 'a'; ch <= 'z'; ch++)
            {
                word[i] = ch;
                if(st.find(word) != st.end()){
                    vec.push_back(word);
                    q.push(vec); //push new sequence formed in queue
                    usedonlevel.push_back(word); //mark as visited for that word

                    //remember to pop the last added word,so that multiple sequences can be formed
                    vec.pop_back(); 
                }
            }
            word[i] = original;
        }
        
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