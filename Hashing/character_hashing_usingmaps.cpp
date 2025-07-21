#include<iostream>
#include<map>
using namespace std;

int main()
{
    string s;
    cout<<"enter the string: ";
    cin>>s;

    //query size already known as 256 for all characters
    //precompute
    map<char, int> mpp;
    for (int i = 0; i < s.size(); i++)
    {
        mpp[s[i]]++;
    }

    
    int q;
    cout<<"enter the size of query: ";
    cin>>q;
    
    for (int i = 0; i < q; i++)
    {
        char c;
        cin>>c;
        //fetch
        cout<<mpp[c]<<endl;

    }
    return 0;
}