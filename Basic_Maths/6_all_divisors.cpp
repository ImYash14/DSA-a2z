#include<iostream>
#include<vector>
#include<algorithm>
#include<math.h>
using namespace std;

int main()
{
    int n;
    cout<<"enter the num: ";
    cin>>n;

    // for (int i = 1; i <= n; i++)
    // {
    //     if(n%i ==0) cout<<i<<" ";
    // }

    // for (int i = 1; i <=sqrt(n); i++)
    // {
    //     if(n%i == 0) {
    //         cout<<i<<" ";
    //         if(n/i != i) cout<<n/i<<" ";
    // }
    // }


    vector<int> vec;
    for (int i = 1; i*i <=n ; i++) // O(sqrt(n))
    {
        if(n%i ==0) vec.push_back(i);
        if(n/i != i) vec.push_back(n/i);

    }
    
    sort(vec.begin(),vec.end()); //O(no. of factors*log(n))

    for(auto it:vec){     //O(no.of factors)
        cout<<it<<" "; 
    }
    
    
    
    return 0;
}