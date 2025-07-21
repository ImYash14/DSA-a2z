#include<iostream>
#include <vector>
using namespace std;

void explainVectors(){
    vector<int>v;
    v.push_back(1);
    v.emplace_back(2);

    vector<pair<int,int>>vec;
    vec.push_back({1,2});
    vec.emplace_back(1,2);  // no curly bracess required

    vector<int> v(5,100); //5 instances of 100

    vector<int>v1(5); //5 instances of 0;
    vector<int>v2(v1);

    cout<<v[0]<<endl;
    vector<int>::iterator xy = v.begin(); //points to memory address of the vector
    xy++;
    cout<<*(xy)<<endl;// gives the first element
    xy= xy+2;
    cout<<*(xy)<<endl;

    vector<int>::iterator xy = v.end(); //points at memory address after last
    // rend and rbegin also for reverse



    for(vector<int>::iterator it= v.begin(); it != v.end(); it++){
        cout<<*(it)<<" ";
    }
    for(auto it =v.begin(); it !=v.end(); it++){
        cout<<*(it)<<" ";
    }
    for(auto it:v){
        cout<<it<<" "; 
    }



    //{10,20,30,40,50}
    v.erase(v.begin()+1); //20 will be removed and the vector will be reshuffled to 10,30,40,50
    v.erase(v.begin()+2, v.begin()+4); //10,20,50



    vector<int>V(2,100); // {100,100}
    v.insert(v.begin(),300); //{300,100,100}
    v.insert(v.begin()+1, 2, 10); // { 300,10,10,100,100}

    vector<int> copy(2,50); //{50,50}
    v.insert(v.begin(),copy.begin(),copy.end()); //{50,50,300,10,10,100,100}

    //{10,20}
    cout<<v.size();//2
    v.pop_back(); //10

    //v1(10,20) v2(30,40)
    v1.swap(v2); // v1(30,40) v2(10,20)

    v.clear();//erases the entire vector

    cout<<v.empty(); // returns true or false
}
int main()
{
    explainVectors();
    
    return 0;
}