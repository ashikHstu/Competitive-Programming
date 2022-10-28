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
    string st;cin>>st;
    int p;
    cin>>p;
    int sum=0;
    vector<pair<int,int>>vec;
    for(int i=0;i<st.size();i++)
    {
        vec.pb({(st[i]-'a'+1),i});
        sum+=(st[i]-'a'+1);
    }

    sort(all(vec));
    reverse(all(vec));

    vector<int>ri;
    
    for(int i=0;i<vec.size();i++)
    {
        if(sum<=p)break;
        sum-=(vec[i].first);
        ri.pb(vec[i].second);
    }
    sort(all(ri));
    int in=0;
    for(int i=0;i<st.size();i++)
    {
        if(in<ri.size())
        {
            if(ri[in]==i)
                in++;
                else cout<<st[i];
        }
        else cout<<st[i];
    }cout<<endl;
 

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

