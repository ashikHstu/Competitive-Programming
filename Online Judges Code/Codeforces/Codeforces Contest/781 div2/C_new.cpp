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

void solve(int kase)
{
    int n;
    cin>>n;
    int ar[n+2];
    int ct[n+2]= {0};
    for(int i=1; i<n; i++)
    {
        cin>>ar[i];
        ct[ar[i]]++;
    }
    vector<int>vec;
    for(int i=1; i<=n; i++)
    {
        if(ct[i]>0)
        {
            vec.pb(ct[i]);
        }
    }

    vec.pb(1);
    sort(all(vec));



    priority_queue<int>pq;

    int mustRemoved=vec.size();
    for(int i=0; i<mustRemoved; i++)
    {
        vec[i]-=(i+1);
        if(vec[i]>0)
        {
            pq.push(vec[i]);
        }
    }


    int secondRemoved=0;
    while(!pq.empty())
    {
        int t=pq.top();

        pq.pop();

        if(t-secondRemoved<=0)
            continue;
        t-=1;
        secondRemoved++;

        if(t-secondRemoved>0)
            pq.push(t);
    }



    cout<<mustRemoved+secondRemoved<<endl;


}

int main()
{
    int tc=1;
    cin>>tc;
    for(int i=1; i<=tc; i++)
    {
        solve(i);
    }

    return 0;
}


