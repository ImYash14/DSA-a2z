#include<iostream>
#include<math.h>
using namespace std;

void bruteForce(int n1, int n2){
    int gcd =1;
    for (int i = 1; i <= min(n1,n2); i++)
    {
        if(n1%i == 0 && n2%i == 0)
        {
            gcd =i;
        }
    }
    cout<<gcd;
    
}

void Euclidean(int n1, int n2){
    while(n1>0 && n2>0)
    {
        if(n1>n2) n1%n2;
        else n2%n1;
    }
    if(n1==0) cout<<n2;
    if(n2==0) cout<<n1;
}

int main()
{
    int n1,n2;
    cout<<"enter the  two no.: ";
    cin>> n1;
    cin>> n2;

    Euclidean(n1,n2);
    
    return 0;
}