#include<iostream>
using namespace std;

int main()
{
    // string s;
    // cout<<"enter the string: ";
    // cin>>s;

    // //query size already known as 26 for lowercase letters
    // //precompute
    // int hash[26] ={0};
    // for (int i = 0; i < s.size(); i++)
    // {
    //     hash[s[i] - 'a']++;
    // }

    
    // int q;
    // cout<<"enter the size of query: ";
    // cin>>q;
    
    // for (int i = 0; i < q; i++)
    // {
    //     char c;
    //     cin>>c;
    //     //fetch
    //     cout<<hash[c-'a']<<endl;

    // }

    string s;
    cout<<"enter the string: ";
    cin>>s;

    //query size already known as 256 for all characters
    //precompute
    int hash[256] ={0};
    for (int i = 0; i < s.size(); i++)
    {
        hash[s[i]]++;
    }

    
    int q;
    cout<<"enter the size of query: ";
    cin>>q;
    
    for (int i = 0; i < q; i++)
    {
        char c;
        cin>>c;
        //fetch
        cout<<hash[c]<<endl;

    }


    return 0;
}