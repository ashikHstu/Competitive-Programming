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
    map<string,int>mp;
    string st[n+2];
    vector<int>ok(n+2,0);
    for(int i=0;i<n;i++)
    {
        cin>>st[i];
        mp[st[i]]++;
    }

    for(int i=0;i<n;i++)
    {
        string temp;
        
        for(int j=0;j<st[i].size();j++)
        {
            string temp2;
            temp.push_back(st[i][j]);
            for(int k=j+1;k<st[i].size();k++)
            {
                temp2.pb(st[i][k]);
            }

            if(mp[temp] && mp[temp2])
            {
                ok[i]=1;
            }
        }
    }

    for(int i=0;i<n;i++)cout<<ok[i]<<"";
    cout<<endl;


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


