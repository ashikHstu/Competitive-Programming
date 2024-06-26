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
    int n;cin>>n;
   
   int ct[11]={0};
    for(int i=0;i<n;i++)
    {
        int v;cin>>v;
        ct[v%10]++;
    }

    for(int i=0;i<10;i++)
    {
        for(int j=0;j<10;j++)
        {
            for(int k=0;k<10;k++)
            {
                if((i+j+k)%10==3)
                {
                    ct[i]--;
                    ct[j]--;
                    ct[k]--;
                    if(ct[i]>=0 && ct[j]>=0 && ct[k]>=0)
                    {
                        cout<<"YES\n";
                        return;
                    }

                    ct[i]++;
                    ct[j]++;
                    ct[k]++;
                }
            }
        }
    }

    cout<<"NO\n";
    


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


