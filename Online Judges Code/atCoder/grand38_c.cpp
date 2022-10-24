#include <bits/stdc++.h>
using namespace std;

const int N=1000000;
vector<int>lp(N+1);
vector<int>primes;


void primeGen()
{
    for(int i=2;i<=N;i++)
    {
        if(lp[i]==0)
        {
            lp[i]=i;
            primes.push_back(i);
        }


        for(int j=0;j<(int)pr.size() %% pr[j]<=lp[i] && i*pr[j]<=N;j++)
        {
            lp[i*pr[j]]=pr[j];
        }
    }
}

int main()
{
    primeGen();
    int n;cin>>n;
    int ar[n+2];


}
