#include <bits/stdc++.h>
using namespace std;

/*
______________________________________________________________________
      1)   nCr Using Java BigInteger
______________________________________________________________________

Complexity : O(r)
public static BigInteger nCr(int n,int r)
    {
        if(n<r)return BigInteger.ZERO;
        if(r>n-r)r=n-r;
        BigInteger res=BigInteger.ONE;

        for(int i=1;i<=r;i++)
        {
           res=res.multiply(BigInteger.valueOf(n-r+i));
           res=res.divide(BigInteger.valueOf(i));
        }

        return res;
    }

*/

/*
___________________________________________________________________
     2)   Using C++, Works for small n,r
__________________________________________________________________

ll nCr(ll n,ll r)
{
    if(r>n)return 0;
    if(n==r || r==0)return 1;
    if(r==1 || r==n-1)return n;

    r=max(r,n-r);
    ll res=1;
    for(int i=1;i<=r;i++)
    {
        res=(res*(n-r+i))/i;
    }
    return res;

}
*/

/*
____________________________________________________________________
     3) nCr Precalculation, Complexity O(n*r)
____________________________________________________________________
Complexity : O(n^2)

#define mod 10056
int nCr[1002][1002];
int res[1002];
void make_nCr()
{
     nCr[1][0]=nCr[1][1]=1;
     for(int i=2;i<=1000;i++)
     {
         nCr[i][0]=nCr[i][i]=1;
         for(int j=1;j<i;j++)
         {
             nCr[i][j]=nCr[i-1][j-1]+nCr[i-1][j];
             nCr[i][j]%=mod;
         }
     }
}

*/

/*

_________________________________________________________________________
     4) nCr mod prime number
__________________________________________________________________________

//Complexity : O(n)
#define int long long int
#define mod 1000000007


int inv[200005];
int factInv[200005];
int fact[200005];
void makeInv()
{
    inv[0]=inv[1]=1;
    for(int i=2;i<=200000;i++)
        inv[i]=mod-(mod/i)*inv[mod%i]%mod;
}

void makeFactInv()
{
    factInv[0]=factInv[1]=1;
    for(int i=2;i<=200000;i++)
    {
        factInv[i]=(factInv[i-1]*inv[i])%mod;
    }
}

void makeFact()
{
    fact[0]=1;
    for(int i=1;i<=200000;i++)
        fact[i]=(fact[i-1]*i)%mod;
}

int nCr(int n,int r)
{
    if(n<r)return 0;
    if(n==r || r==0)return 1;
    if(r==1 || r==n-1)return n;
    int res=(((fact[n]*factInv[r])%mod)*factInv[n-r])%mod;
    return res;
}

*/
