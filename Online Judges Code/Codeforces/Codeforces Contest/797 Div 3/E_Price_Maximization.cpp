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
    int n,k;
    cin>>n>>k;
    ll ar[n+2];
    ll rem[k+2]={0};
    ll res=0;
    for(int i=0;i<n;i++)
    {
        cin>>ar[i];
        res+=(ar[i]/k);
        rem[ar[i]%k]++;
    }


    int fh=k/2;
    int sh=k-fh;
    for(int i=1;i<=fh;i++)
    {
        if(i==fh && fh==sh)
        {
            int m=rem[i]/2;
            rem[i]=rem[i]%2;
            res+=m;
        }
        else {
            int tt=min(rem[i],rem[k-i]);
            rem[i]-=tt;
            rem[k-i]-=tt;
            res+=tt;
        }
    }
 ll extt=0;
     for(int i=1;i<=fh;i++)
    {
        int startt=k-i;
        if(fh==sh)
        startt++;

        extt+=(rem[startt]);
        int tt=min(rem[i],extt);
        res+=tt;
        rem[i]-=tt;
        extt-=tt;
            // for(int j=startt;j<k;j++)
            // {
            // int tt=min(rem[i],rem[j]);
            // rem[i]-=tt;
            // rem[j]-=tt;
            // res+=tt;
            // }
        
    }
    
    ll ex=extt;
    // for(int i=sh;i<k;i++)
    // {
    //     ex+=rem[i];
    // }
    res+=(ex/2);
     
    
    cout<<res<<endl;
    


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


