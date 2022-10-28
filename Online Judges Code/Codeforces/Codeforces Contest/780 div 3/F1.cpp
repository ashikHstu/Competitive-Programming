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
    int n;
    cin>>n;
    string st;
    cin>>st;
    int res=0;

    for(int j=0; j<n; j++)
    {
        int pls=0,mns=0;
        int ct=0;
        int canP=0;
        for(int i=j; i<n; i++)
        {
            if(st[i]=='-')
            {
                mns++;
                ct++;
                if(ct==2)
                {
                    canP++;
                    ct=0;
                }
            }
            else
            {
                pls++;
            }


            if(mns==pls)
            {
                res++;
            }
            else if(mns>pls){
                int ex=mns-pls;
                if(ex%3==0 && canP>=(ex/3))res++;
            }
        }
    }


    //cout<<"res : ";
    cout<<res<<endl;

}

int main()
{
    int tc=1;
    cin>>tc;
    for(int i=1; i<=tc; i++)
    {
        solve();
    }

    return 0;
}

