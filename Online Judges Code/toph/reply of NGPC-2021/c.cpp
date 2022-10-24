#include <bits/stdc++.h>
using namespace std;
#define ll long long int
#define m 1000000007
ll bigMod(long long a, long long b) {
    a %= m;
    long long res = 1;
    while (b > 0) {
        if (b & 1)
            res = res * a % m;
        a = a * a % m;
        b >>= 1;
    }
    return res;
}


ll findSol(int a,int b)
{
    if(b==0)return 0;
    ll r1=bigMod(2,a);
    ll r2=bigMod(2,b-1);

    return (r1*r2)%m;


}


int main()
{
    int n,q;cin>>n>>q;
    int ar[n+2];
    int even=0,odd=0;

    for(int i=0;i<n;i++)
    {
        cin>>ar[i];


        if(ar[i]&1)odd++;
        else even++;

    }

    for(int i=0;i<q;i++)
    {
        int index,upd;
        cin>>index>>upd;
        if(ar[index-1]%2==0 && upd%2==1)
        {
            even--;
            odd++;
        }
        else if(ar[index-1]%2==1 && upd%2==0)
        {
            even++;
            odd--;
        }

        cout<<findSol(even,odd)<<endl;

    }


}
