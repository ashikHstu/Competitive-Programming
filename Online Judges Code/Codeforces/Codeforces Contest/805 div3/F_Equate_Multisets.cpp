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
    int n;
    cin>>n;
    int ar[n+2],b[n+2];
    map<int,int>mp;
   
   for(int i=0;i<n;i++)
   {
    int v;cin>>v;
    while(v%2==0)v/=2;

    mp[v]++;
   }
    
    priority_queue<int>pq;
    for(int i=0;i<n;i++)
    {
        int q;
        cin>>q;
        pq.push(q);
    }
int removed=0;
     while(!pq.empty())
     {
        int f=pq.top();
        pq.pop();
        if(mp[f]>0)
        {
            mp[f]--;
            removed++;
        }
        else {
            if(f==1)
            {
                cout<<"NO\n";
                return;
            }
            pq.push((f/2));
        }
     }

     if(removed==n)
     cout<<"YES\n";
     else cout<<"NO\n";



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


