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
    vector<set<int>>pos(26);

    int n=st.size();

   for(int i=0;i<n;i++)
   {
       pos[st[i]-'a'].insert(i);
   }

   int q;cin>>q;
   for(int i=0;i<q;i++)
   {
       int type;cin>>type;
       if(type==1)
       {
           int p;
           char ch;
           cin>>p>>ch;
           p--;
           pos[st[p]-'a'].erase(p);
           st[p]=ch;
           pos[st[p]-'a'].insert(p);



       }
       else {

               int ct=0;
           int l,r;cin>>l>>r;
           for(int j=0;j<26;j++)
           {
               auto it=pos[j].lower_bound(l);
               if(it!=pos[j].end() && *it<=r)
               {
                   ct++;
               }
           }

           cout<<ct<<endl;
       }
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



