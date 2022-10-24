/**        بِسْمِ اللهِ الرَّحْمٰنِ الرَّحِيْمِ (In the name of God, the Most Gracious, the Most Merciful.)       */
/*
      Institution : Hajee Mohammad Danesh Science and Technology University,Dinajpur,Bangladesh.
      Name        : Ashikur Rahman Bhuyain (Asif)
      Email       : asifurr087@gmail.com
*/

#include <bits/stdc++.h>
using namespace std;


const int N = 1e7+5;
int lp[N];
vector<int>primes;

void sieveN()
{
    for(int i=2;i<=N;i++)
    {
        if(lp[i]==0)
        {

            lp[i]=i;
            primes.push_back(i);
        }

        for(int j=0;j<(int)primes.size() && primes[j]<=lp[i] && i*primes[j]<=N;j++)
        {
            lp[i*primes[j]]=primes[j];
        }
    }
}


int main()
{
    sieveN();
    int n;cin>>n;
    int L[n+2],R[n+2];
    for(int i=1;i<=n;i++)
    {
        int v;cin>>v;
        int div=lp[v];

        int curd=1;

        while(v%div==0){
            v/=div;
            curd*=div;
        }

        if(v==1)
        {

            L[i]=R[i]=-1;
        }
        else {
            L[i]=v;
            R[i]=curd;
        }
    }

    for(int i=1;i<=n;i++)
        cout<<L[i]<<" ";cout<<endl;

    for(int i=1;i<=n;i++)cout<<R[i]<<" ";cout<<endl;

    return 0;
}


 /*"Success isn't permanent, failure isn't fatal,
                                      it's the courage to continue that counts"*/
