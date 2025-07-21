#include<iostream>
using namespace std;

void firstNsum(int i, int sum){
   //parameterized method
    if(i<1)
    {
        cout<<sum;
        return;
    }
    else
    firstNsum(i-1,sum+i);
    
}

int firstNsum1(int n){
    //functional method
    if(n==0) return 0;
    else
    return n + firstNsum1(n-1);
}
int main()
{
    int n;
    cout<<"enter the no.: ";
    cin>>n;
    cout<<firstNsum1(n);
    
    return 0;
}