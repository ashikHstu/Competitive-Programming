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
    string st[8];
    for(int i=0;i<8;i++)
    {
        cin>>st[i];
    }

    int okOne=0;
    int okTwo=0;
    for(int i=0;i<8;i++)
{
    int ct=0;
    int x=-1,y=-1;
    for(int j=0;j<8;j++)
    {
          if(st[i][j]=='#'){
            ct++;
            x=i;
            y=j;
          }
    }

    if(ct==1 && okTwo)
    {
        cout<<x+1<<" "<<y+1<<endl;
        return ;
    }
    else if(ct==2)
    {
        okTwo=1;
    }
}
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


