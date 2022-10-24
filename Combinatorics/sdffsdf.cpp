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
ll n;
ll ar[2000+2][2000+2];
ll Left[2002][2002],Right[2002][2002];

void findSumFrom(ll start,ll end)
{
    ll ts=start,te=end;
    ll sum=0;
    while(start<=n && end<=n)
    {
        sum+=ar[start][end];
        start++;
        end++;

    }

    start=ts;
    end=te;


      while(start<=n && end<=n)
    {
        Left[start][end]=max(Left[start][end],sum);
        start++;
        end++;

    }


    start=ts;
    end=te;
    sum=0;

     while(start>0 && end<=n)
    {

        sum+=ar[start][end];
        start--;
        end++;

    }


      start=ts;
    end=te;


     while(start>0 && end<=n)
    {
       Right[start][end]=max(Right[start][end],sum);
        start--;
        end++;

    }
}


void solve()
{
    cin>>n;
    for(int i=1;i<=n;i++)
    {
        for(int j=1;j<=n;j++)
        {
            cin>>ar[i][j];
        }
    }

    for(int i=1;i<=n;i++)
    {
        findSumFrom(1,i);
        findSumFrom(i,1);
        findSumFrom(n,i);
    }



cout<<endl<<endl;
    for(int i=1;i<=n;i++)
    {

        for(int j=1;j<=n;j++)
        {

            cout<<Left[i][j]<<" ";
        }cout<<endl;
    }


    cout<<endl<<endl;
    for(int i=1;i<=n;i++)
    {

        for(int j=1;j<=n;j++)
        {

            cout<<Right[i][j]<<" ";
        }cout<<endl;
    }





}

int main()
{
    int tc=1;
    //cin>>tc;
    for(int i=1;i<=tc;i++)
    {
        solve();
    }

    return 0;
}


