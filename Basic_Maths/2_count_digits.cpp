#include<iostream>
using namespace std;

void digitCounter(int n){
    int count =0;
    while (n>0)
    {
        int digit = n%10;
        //cout<<digit<<endl;
        count++;

        n=n/10;
        //cout<<n<<endl;
    }
    cout<<count;
    
}
int main()
{
    int n;
    cout<<"enter a no.: ";
    cin>>n;
    digitCounter(n);
    
    return 0;
}