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
    int n,k;cin>>n>>k;
    string st;
    cin>>st;
   string res;
   int chochen[n+2]={0};
    if(k%2==0)
    {
        int curK=k;
        for(int i=0;i<n;i++)
        {
            if(st[i]=='0' && curK>0)
            {
                res.push_back('1');
                chochen[i]=1;
                curK--;
            }
            else {
                res.push_back(st[i]);
            }
        }
        if(curK%2==0)
        {
            chochen[n-1]+=curK;
        }
        else {
            chochen[n-1]+=curK;
            res[n-1]='0';
        }


    }
    else {

         int curK=k;
        for(int i=0;i<n;i++)
        {
            if(st[i]=='1' && curK>0)
            {
           
                res.push_back('1');

                chochen[i]=1;
                curK--;
            }
            else {
                if(st[i]=='0')
                res.push_back('1');
                else
                res.push_back('0');
            }
        }
        if(curK%2==0)
        {
            chochen[n-1]+=curK;
        }
        else {
            chochen[n-1]+=curK;
            res[n-1]='0';
        }



    }


cout<<res<<endl;
for(int i=0;i<n;i++)
cout<<chochen[i]<<" ";
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


