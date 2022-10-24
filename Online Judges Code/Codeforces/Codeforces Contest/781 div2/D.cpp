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

int ask(int a, int b)
{
    cout << '?' << " " << a << " " << a + b << endl;
    cout.flush();
    int ans;
    cin >> ans;
    return ans;
}


void solve()
{


    int r=0;
    for (int i = 1; i <= 30; i++)
    {
        int ans = ask((1 << (i - 1)) - r, (1 << i));
        if (ans == (1 << i))
            r += (1 << (i - 1));
    }

    cout<<"! "<<r<<endl;
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


