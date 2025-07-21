#include<iostream>
using namespace std;

void palindromeNum(int n){
    if(n<0) cout<<"not a palindrome";
    int dup = n;
    int revNum = 0;
    while (n!=0)
    {
        int digit = n%10;
        n=n/10;

        revNum = revNum*10 + digit;

    }
    cout<<revNum;
    if(dup == revNum) cout<<"it is a palindrome";
    else cout<<"not a palindrome";
    
}
int main()
{
    int n;
    cout<<"enter a no.: ";
    cin>>n;
    palindromeNum(n);
    
    return 0;
}