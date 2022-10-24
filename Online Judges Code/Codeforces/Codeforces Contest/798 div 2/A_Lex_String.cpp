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
    int n,m,k;
    cin>>n>>m>>k;
    string st1,st2;
    cin>>st1>>st2;
    sort(all(st1));
    sort(all(st2));
    string res;
    int ap=0,bp=0;
    int ac=0,bc=0;
    while(ap<n && bp<m)
    {
         if(ac<k && bc<k)
         {
            if(st1[ap]<st2[bp])
            {
                res.push_back(st1[ap]);
                ap++;
                ac++;
                bc=0;
            }
            else {
                res.push_back(st2[bp]);
                bp++;
                bc++;
                ac=0;
            }
         }
         else if(ac<k)
         {
            res.push_back(st1[ap]);
            ac++;
            ap++;
            bc=0;
            
         }
         else if(bc<k)
         {
            res.push_back(st2[bp]);
            bc++;bp++;
            ac=0;
         }

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


