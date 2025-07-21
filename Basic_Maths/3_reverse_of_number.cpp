#include<iostream>
using namespace std;

void reverseNum(int n){
    int revNum = 0;
    while (n>0)
    {
        int digit = n%10;
        n=n/10;

        revNum = revNum*10 + digit;

    }
    cout<<revNum;
    
}
int main()
{
    int n;
    cout<<"enter a no.: ";
    cin>>n;
    reverseNum(n);
    
    return 0;
}