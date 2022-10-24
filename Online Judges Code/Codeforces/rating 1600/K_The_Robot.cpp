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
   string st;
   cin>>st;
   int n=st.size();
   vector<pair<int,int>>possible;
    pair<int,int>p={0,0};
    for(int i=0;i<n;i++)
    {
        if(st[i]=='L')
        {
            p.first--;
        }
        else if(st[i]=='R')p.first++;
        else if(st[i]=='U')p.second++;
        else if(st[i]=='D')p.second--;

        possible.pb(p);
    }

    for(int i=0;i<n;i++)
    {
        pair<int,int>cur={0,0};
        pair<int,int>tmp=cur;
        for(int j=0;j<n;j++)
        {
            if(st[j]=='L')  tmp.first--;
        else if(st[j]=='R')tmp.first++;
        else if(st[j]=='U')tmp.second++;
        else if(st[j]=='D')tmp.second--;

        if(tmp!=possible[i])
        {
           cur=tmp;
        }
        else {
            tmp=cur;
        }
        }

        if(cur.first==0 && cur.second==0)
        {
             cout<<possible[i].first<<" "<<possible[i].second<<endl;
            return;
         }
    }

    cout<<"0 0\n";


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


