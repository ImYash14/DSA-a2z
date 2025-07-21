#include<iostream>
using namespace std;

void armstrongNum(int n){
    int dup = n;
    int sum = 0;
    while (n>0)
    {
        int digit = n%10;
        n=n/10;

        sum = sum + (digit*digit*digit);

    }
    cout<<sum;
    if(dup == sum) cout<<"it is an armstrong num";
    else cout<<"not an armstrong num";
    
}
int main()
{
    int n;
    cout<<"enter a no.: ";
    cin>>n;
    armstrongNum(n);
    
    return 0;
}