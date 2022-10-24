#include <bits/stdc++.h>
using namespace std;
#define ll long long int

void findMultiply(int a,int b,int &m)
{
    m=a*b;
}


int main()
{
    int a,b,m;
    cin>>a>>b;
    findMultiply(a,b,m);
cout<<"multiplication res : "<<m<<endl;
    return 0;
}
