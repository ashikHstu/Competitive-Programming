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

void printRes(int l)
{

    cout<<"! "<<l<<endl;
            cout.flush();
}

void solve()
{
    int n;
    cin>>n;
    int l=1,r=n;
    while(l<=r)
    {
        if(l==r)
        {
            printRes(l);
            return;
        }
        int mid=(l+r)/2;
        cout<<"? "<<l<<" "<<mid<<endl;
        cout.flush();
        int range=mid-l+1;
        int ct=0;
        for(int i=0; i<range; i++)
        {
            int v;
            cin>>v;
            if(v>=l && v<=mid)ct++;
        }

        if(r==l+1)
        {
            if(ct%2==1)
            {
                printRes(l);
            }
            else
            {
                printRes(r);
            }
            return;

        }

       // cout<<"step ct : "<<ct<<endl;
        if(ct%2==1)
        {
            r=mid;
        }
        else
        {
            l=mid;
        }
    }
}

int main()
{
    int tc=1;
    cin>>tc;
    for(int i=1; i<=tc; i++)
    {
        solve();
    }

    return 0;
}



