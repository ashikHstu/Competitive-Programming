#include <bits/stdc++.h>
using namespace std;

long long int toDeci(long long int number,long long int base)
{
    long long int p=1;
    long long int res=0;
    while(number>0)
    {
        long long int ld=number%10;
        number/=10;
        res+=(ld*p);
        p=p*base;
    }
    return res;
}

int main()
{
    long long int k,a,b;cin>>k>>a>>b;

    cout<<(long long int)toDeci(a,k)*toDeci(b,k)<<endl;
    return 0;
}
