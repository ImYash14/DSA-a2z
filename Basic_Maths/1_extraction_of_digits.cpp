#include<iostream>
using namespace std;

void digitExtractor(int n){
    while (n>0)
    {
        int digit = n%10;
        cout<<digit<<endl;

        n=n/10;
        cout<<n<<endl;
    }
    
}
int main()
{
    int n;
    cout<<"enter a no.: ";
    cin>>n;
    digitExtractor(n);
    
    return 0;
}