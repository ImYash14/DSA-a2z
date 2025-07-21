#include<iostream>
using namespace std;


void bruteForce(int n){
    int count = 0;
    for (int i = 1; i <= n; i++)
    {
        if(n%i == 0){
            count++;
        }
        
    }
    if(count==2) cout<<"it is a prime no.";
        else cout<<"not a prime no.";

}

void betterApproach(int n){
    int count =0;
    for (int i = 1; i*i<=n; i++)
    {
        if(n%i == 0){
            count++;
            if(n/i != i) count++;
        }
    }
    if(count==2) cout<<"it is a prime no.";
        else cout<<"not a prime no.";
    
}

int main()
{
    int n;
    cout<<"enter the number: ";
    cin>>n;
    
    betterApproach(n);
    
    
    return 0;
}