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
    int res=0;
    string st[n+2];
    for(int i=0;i<n;i++)cin>>st[i];
     
     for(int i=0;i<n/2;i++)
     {
         
        for(int j=i;j<n-1-i;j++)
        { 

            int z=0;
         int on=0;
            if(st[i][j]=='0')z++;
            else on++;
       
           if(st[j][n-1-i]=='0')z++;
            else on++;
             
           if(st[n-1-i][n-1-j]=='0')z++;
           else on++;

           if(st[n-1-j][i]=='0')z++;
           else on++;
           
           int mn=min(z,on);
           res+=mn;
           // cout<<"z & on : "<<z<<" , "<<on<<endl;
           if(mn==z)
           {
            st[i][j]='0';
       
           st[j][n-1-i]=='0';
            
             
           st[n-1-i][n-1-j]='0';

           st[n-1-j][i]='0';
           }
           else {
            st[i][j]='1';
       
           st[j][n-1-i]=='1';
            
             
           st[n-1-i][n-1-j]='1';

           st[n-1-j][i]='1';
           }

           //cout<<"per j step res : "<<res<<endl;

        }

       // cout<<"Step res : "<<res<<endl;
     }
    cout<<res<<endl;

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


