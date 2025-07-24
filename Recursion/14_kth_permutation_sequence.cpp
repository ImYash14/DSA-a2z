#include<iostream>
#include<bits/stdc++.h>
using namespace std;

//brute is recursion
string optimal(int n, int k){
    //step1->find factorial and store the numbers
    int fact =1;
    vector<int>nums;
    for (int i = 1; i < n; i++)
    {
        fact = fact*i;
        nums.push_back(i);
    }
    nums.push_back(n); //for n=4, {1,2,3,4}

    string ans = "";
    k = k-1; //for 0-indexing

    while(true){
        //step2->finding the block in which the k lies
        //k=16, fact =6, 16/6 = 2nd block(0-indexing)
        ans = ans + to_string(nums[k/fact]); //{3,_,_,_}

        //step3->remove that no. of that block from nums
        nums.erase(nums.begin() + k/fact); //{1,2,3,4}->{1,2,4}

        if(nums.size() == 0) break;

        //step4->update the k
        k = k%fact; //16%6 = 4

        //step5->update the factorial
        fact = fact/nums.size(); //6/3 = 2
    }
    return ans;
}
int main()
{
    int n;
    cout<<"enter the size of set: ";
    cin>>n;

    int k;
    cout<<"enter the sequence no.: ";
    cin>>k;

    cout<<optimal(n,k);
    return 0;
}