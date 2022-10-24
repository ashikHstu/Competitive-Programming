#include <bits/stdc++.h>
using namespace std;
#define ll long long int
#define pb push_back

#define FasterIO          ios::sync_with_stdio(0);cin.tie(0);cout.tie(0)
#define TIME              clock()*1.0/CLOCKS_PER_SEC
#define pi                acos(-1.0)
#define mem(a,b)           memset(a,b,sizeof(a))
#define all(a)             a.begin(),a.end()
#define Sort(x)            sort(x.begin(),x.end())
#define Reverse(x)         reverse(x.begin(),x.end())
#define SortA(ar,s)        sort(ar,ar+s)
#define SortD(ar,s)        sort(ar,ar+s,greater<int>())
#define gcd(a,b)           __gcd(a,b)
#define lcm(a,b)           (a*(b/gcd(a,b)))
#define sq(x)              (x)*(x)
#define CEIL(a,b)          ((a/b)+((a%b)!=0))

void solve()
{
    ll ar[4];
    for(int i=0;i<3;i++)cin>>ar[i];
    sort(ar,ar+3);
    ll dif1=ar[2]-ar[1];
    ll dif2=ar[2]-ar[0];

ll cur=1;
while(dif1!=0 && dif2!=0)
{
    if(dif1%2==1 && dif2%2==1)
    {
        cout<<"NO\n";
        return;
    }
    else if(dif1%2==0 && dif2%2==0)
    {
        dif1+=cur;
        dif2+=cur;
        if(dif1>100000000000000LL || dif2>10000000000000LL)
       {

        cout<<"NO\n";
        return;
       }
    }
    dif1/=2;
    dif2/=2;
    cur*=2;
}

  
    cout<<"YES\n";



}

int main()
{
    int tc=1;
    cin>>tc;
    for(int i=1;i<=tc;i++)
    {
        solve();
    }

    return 0;
}


