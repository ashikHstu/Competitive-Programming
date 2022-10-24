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

string stringSubtraction(string st1,string st2)
{
    //cout<<"st1 : "<<st1<<endl;
   // cout<<"St2 : "<<st2<<endl;
    int len1=st1.size();
    int len2=st2.size();
    reverse(all(st1));
    reverse(all(st2));
    int borrow=0;
    string res="";
    for(int i=0;i<len2;i++)
    {
        int d1=st1[i]-'0';
        int d2=st2[i]-'0';
        d2+=borrow;
        if(d2>d1){
            borrow=1;
            d1=10+d1;
        }
        else {
            borrow=0;
        }

        int dif=d1-d2;
        res.pb(dif+'0');

    }

  

    reverse(all(res));
    return res;
 


}

void solve()
{
    int n;cin>>n;
    string st;
    cin>>st;
    string ss="";
    if(st[0]=='9')
    {
        for(int i=0;i<=n;i++)ss.push_back('1');
    }
    else {
        for(int i=0;i<n;i++)ss.push_back('9');
 
    }

    cout<<stringSubtraction(ss,st)<<endl;
   
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


