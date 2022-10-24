#include <bits/stdc++.h>
using namespace std;

long long int bigMod(long long int n,int m,long long int p)
{
    if(p>15)
    return n;
    long long int mv=1<<p;
    return n%mv;

}


int main()
{
    long long int n,m;
    cin>>n>>m;

    cout<<bigMod(m,2,n)<<endl;
    return 0;
}

