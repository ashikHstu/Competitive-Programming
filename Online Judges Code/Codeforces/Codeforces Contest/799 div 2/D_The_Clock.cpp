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

bool isPalindrome(int h,int m)
{
    int h1=h%10;
    h/=10;
    int m1=m%10;
    m/=10;
    if(h==m1 && h1==m)
    {
        return true;
    }
    return false;
}

void solve()
{
    ll h,m,s;cin>>h;
    char ch;cin>>ch;
    cin>>m>>s;

    map<pair<int,int>,int>mp;
    int res=0;
    while(mp[{h,m}]==0)
    {
        //cout<<"h , m : "<<h<<", "<<m<<endl;
        if(isPalindrome(h,m))
        res++;
        mp[{h,m}]++;
        int exH=s/60;
        int exm=s%60;
        m+=exm;
        if(m>=60)
        {
            m%=60;
            exH++;
        }
        h+=exH;
        h%=24;

    }

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


