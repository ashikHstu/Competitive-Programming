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
ll n;
ll ar[2000+2][2000+2];
ll Left[2002][2002],Right[2002][2002];

void findSumFrom(ll start,ll end)
{
    ll ts=start,te=end;
    ll sum=0;
    while(start<=n && end<=n)
    {
        sum+=ar[start][end];
        start++;
        end++;

    }

    start=ts;
    end=te;


      while(start<=n && end<=n)
    {
        Left[start][end]=max(Left[start][end],sum);
        start++;
        end++;

    }


    start=ts;
    end=te;
    sum=0;

     while(start>0 && end<=n)
    {

        sum+=ar[start][end];
        start--;
        end++;

    }


      start=ts;
    end=te;


     while(start>0 && end<=n)
    {
       Right[start][end]=max(Right[start][end],sum);
        start--;
        end++;

    }
}


int main()
{
    FasterIO;
    cin>>n;
    for(int i=1;i<=n;i++)
    {
        for(int j=1;j<=n;j++)
        {
            cin>>ar[i][j];
        }
    }

    for(int i=1;i<=n;i++)
    {
        findSumFrom(1,i);
        findSumFrom(i,1);
        findSumFrom(n,i);
    }

    
    vector<ll>L,R;
    vector<pair<ll,ll>>L_ind,R_ind;
    for(int i=1;i<=n;i++)
    {
        for(int j=1;j<=n;j++)
        {
            ll cur=Left[i][j]+Right[i][j]-ar[i][j];

            if((i+j)%2==0)
            {
                L.pb(cur);
                L_ind.pb({i,j});
            }
            else
            {
            R.pb(cur);
            R_ind.pb({i,j});
            } 
        }
    }

    ll mx=0,res=0;
    int ind1=-1,ind2=-1;
    for(int i=0;i<L.size();i++)
    {
        if(res<=L[i])
        {
            res=L[i];
            ind1=i;
        }
    }

    for(int i=0;i<R.size();i++)
    {
        if(mx<=R[i])
        {
            mx=R[i];
            ind2=i;
        }
    }


cout<<res+mx<<endl;

cout<<L_ind[ind1].first<<" "<<L_ind[ind1].second<<" "<<R_ind[ind2].first<<" "<<R_ind[ind2].second<<endl;



  return 0;
}


