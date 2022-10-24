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
   int ar[n+2];
   map<int,int>mp;
   vector<int>vec[n+2];
   int ind=1;
   for(int i=0;i<n;i++)
   {
       cin>>ar[i];
       int v=ar[i];
       if(mp[v]==0)
       {
           mp[v]=ind;
           ind++;
//cout<<"here?"<<endl;
         
       }

       vec[mp[v]].push_back((i+1));
   }


   int res[n+2];

   for(int i=1;i<ind;i++)
   {
       int len=vec[i].size();
    //    cout<<"the len is : "<<vec[i][1]<<endl;
    //     cout<<"calling time"<<endl;
       if(len==1)
       {
           cout<<"-1\n";
           return;
       }

       for(int j=1;j<len;j++)
       {
           res[vec[i][j-1]]=vec[i][j];

       }
       res[vec[i][len-1]]=vec[i][0];

   }

   for(int i=1;i<=n;i++)
   {
       cout<<res[i]<<" ";
   }
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


