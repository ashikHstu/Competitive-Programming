#include <bits/stdc++.h>
using namespace std;
#define ll long long int
#define pb push_back_back

#define FasterIO          ios::sync_with_stdio(0);cin.tie(0);cout.tie(0)
#define TIME              clock()*1.0/CLOCKS_PER_SEC
#define pi                acos(-1.0)
#define mem(a,b)           memset(a,b,sizeof(a))
#define all(a)             a.begin(),a.end()
#define Sort(x)            sort(x.begin(),x.end())
#define Reverse(x)         reverse(x.begin(),x.end())
#define SortA(ar,s)        sort(ar,ar+s)
#define SortD(ar,s)        sort(ar,ar+s,greater<ll>())
#define gcd(a,b)           __gcd(a,b)
#define lcm(a,b)           (a*(b/gcd(a,b)))
#define sq(x)              (x)*(x)
#define CEIL(a,b)          ((a/b)+((a%b)!=0))
#define inf (1LL<<62)

ll dp[3003][3003];
deque<pair<ll,ll>>dq[3003];


void solve()
{
    FasterIO;
    ll n,m,l,t;
    cin>>n>>m>>l>>t;
    string st[n+2];
    for(ll i=0; i<n; i++)
    {
        cin>>st[i];
    }

    for(ll i=0; i<n; i++)
    {
        for(ll j=0; j<m; j++)
            dp[i][j]=inf;
    }

    dp[0][0]=0;
    dq[m].push_back({0,0});
    dq[0].push_back({0,0});

    for(ll i=0; i<n; i++)
    {
        for(ll j=(i==0)?1:0; j<m; j++)
        {
            if(st[i][j]=='#')
            {
                while(!dq[m].empty())
                    dq[m].pop_back();
                while(!dq[j].empty())
                    dq[j].pop_back();
                continue;
            }

            while(!dq[m].empty() && dq[m].front().second<j-l)
                dq[m].pop_front();
            while(!dq[j].empty() && dq[j].front().second<i-l)
                dq[j].pop_front();

            ll x=-1,y=-1;
            if(!dq[m].empty())
                y=dq[m].front().second;
            if(!dq[j].empty())
                x=dq[j].front().second;

            if(y!=-1)
                dp[i][j]=min(dp[i][j],dp[i][y]+t+(j-y));
            if(x!=-1)
                dp[i][j]=min(dp[i][j],dp[x][j]+t+(i-x));

            if(dp[i][j]<inf)
            {
                while(!dq[m].empty() && dq[m].back().first>=dp[i][j]-j)
                    dq[m].pop_back();
                dq[m].push_back({dp[i][j]-j,j});

                while(!dq[j].empty() && dq[j].back().first>=dp[i][j]-i)
                    dq[j].pop_back();
                dq[j].push_back({dp[i][j]-i,i});
            }


        }

       while(!dq[m].empty())dq[m].pop_front();

    }

    if(dp[n-1][m-1]==inf)cout<<"-1"<<endl;
    else cout<<dp[n-1][m-1]<<endl;




}

int32_t main()
{
    ll tc=1;
    // cin>>tc;
    for(ll i=1; i<=tc; i++)
    {
        solve();
    }

    return 0;
}

