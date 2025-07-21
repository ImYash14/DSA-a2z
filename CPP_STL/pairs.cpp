#include<iostream>
using namespace std;

void explainPairs(){
    pair<int,int>a = {1,3};
    cout<<a.first<<" "<<a.second<<endl;

    // pair<int,pair<int,int>> b = {2,{6,5}};
    // cout<<b.first<<" "<<b.second<<endl;

    pair<int,int>arr[]={{1,2},{2,3},{3,4}};
    cout<<arr[1].first<<endl;

}

int main()
{
    explainPairs();   
    return 0;
}