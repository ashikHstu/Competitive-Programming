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
/*
void solve()
{
    int n;
    cin>>n;
    int ar[n+2],b[n+2];
    stack<int>stk;
    for(int i=0;i<n;i++)
    {
        cin>>ar[i];
    }
     

    for(int i=0;i<n;i++)
    {
        cin>>b[i];
    }

    int cur=0;
    for(int i=0;i<n;i++)
    {
       if(ar[i]==b[cur])
       {
           cur++;
       }
       else {
           while(!stk.empty())
           {
               int t=stk.top();

               if(b[cur]==t && cur!=0 && b[cur-1]==t)
               {
                   stk.pop();
                 //  cout<<"for b, cur : "<<cur<<endl;
                   cur++;
               }
               else {
                   break;
               }
              
           }
            if(ar[i]==b[cur])
            {
           cur++;
           }
           else
               stk.push(ar[i]);
           
       }
    }
    
    while(cur<n)
    {
        if(!stk.empty())
        {
            int t=stk.top();
            stk.pop();
          //  cout<<"for b, outer cur : "<<cur<<endl;
          //  cout<<"t , b[cur], b[cur-1] : "<<t<<", "<<b[cur]<<" , "<<b[cur-1]<<endl;
            if(b[cur]==t && cur!=0 && b[cur-1]==t)
            {
             // cout<<"for b, inner"<<endl;
            cur++;
            }
            else
            {
                cout<<"NO\n";
                return;
            }
        }
        else {
            cout<<"NO\n";
            return;
        }
    }

    cout<<"YES"<<endl;
    

}
*/

void solve()
{
    int n;cin>>n;
    int ar[n+2];
    int b[n+2];
    for(int i=0;i<n;i++)
    {
        cin>>ar[i];
    }

    for(int i=0;i<n;i++)cin>>b[i];


    int cur=n-1;
    map<int,int>mp;
    for(int i=n-1;i>=0;i--)
    {
        mp[ar[i]]++;
        if(mp[b[i]]==0)
        {
            cout<<"NO"<<endl;
            return;
        }

    }

    cout<<"YES"<<endl;

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


