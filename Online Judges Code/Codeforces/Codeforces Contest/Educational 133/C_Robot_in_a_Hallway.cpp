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
   ll ar[3][n+2];
   ll forward[3][n+2];
 ll backward[3][n+2];
 ll zFormat[3][n+2];

 for(int i=1;i<=2;i++)
   {
    for(int j=1;j<=n;j++)cin>>ar[i][j];
   }

 zFormat[1][1]=forward[1][1]=backward[1][1]=0;
 zFormat[2][1]=max(1LL,ar[2][1]+1);
    for(int i=2;i<=n;i++)
    {
        if(i%2==0)
        {
            zFormat[2][i]=max(zFormat[2][i-1]+1,ar[2][i]+1);
            zFormat[1][i]=max(zFormat[2][i]+1,ar[1][i]+1);
        }
        else {
           zFormat[1][i]=max(zFormat[1][i-1]+1,ar[1][i]+1);
            zFormat[2][i]=max(zFormat[1][i]+1,ar[2][i]+1); 
        }
    }
    ll res;
    if(n%2==0)
    {
        res=zFormat[1][n];
    }
    else {
        res=zFormat[2][n];
    }

 
   ll done=0;
   for(int i=2;i<=n;i++)
   {
    done=max(ar[1][i],done);
    done++;
    forward[1][i]=done;
   }

   for(int i=n;i>0;i--)
   {
    done=max(ar[2][i],done);
    done++;
    forward[2][i]=done;
   }

   res=min(res,forward[2][1]);


   done=0;
    for(int i=1;i<=n;i++)
   {
    done=max(ar[2][i],done);
    done++;
    backward[2][i]=done;
   }
backward[1][1]=0;
   for(int i=n;i>1;i--)
   {
    done=max(ar[1][i],done);
    done++;
    backward[1][i]=done;
   }



 

   res=min(res,backward[1][2]);

    ll cur=backward[2][2];
    ll curX=2,curY=2;
    for(int i=1;i<n;i++)
    {

        if(i%2==0)
        {
            // backward dekhi 
            ll lagchilo=backward[2][i]-backward[1][i];
                     lagchilo=abs(lagchilo);
            ll opt=n-i+n-i+1;
            ll ext=lagchilo-opt;
             
             ll newPaichi=zFormat[2][i]-backward[2][i];
             ext-=newPaichi;
             if(ext<0)ext=0;
             res=min(res,ext+opt+zFormat[2][i]);

           // Forward dekhi
            lagchilo=forward[1][i]-forward[2][i+1];
                     lagchilo=abs(lagchilo);
           opt=n-i+n-i;
         ext=lagchilo-opt;
             
              newPaichi=zFormat[1][i]-forward[1][i];
             ext-=newPaichi;
             if(ext<0)ext=0;
             res=min(res,ext+opt+zFormat[1][i]);


        }

        else {
             // backward dekhi 
            ll lagchilo=backward[2][i]-backward[1][i+1];
            lagchilo=abs(lagchilo);
            ll opt=n-i+n-i;
            ll ext=lagchilo-opt;
             
             ll newPaichi=zFormat[2][i]-backward[2][i];
             ext-=newPaichi;
             if(ext<0)ext=0;
             res=min(res,ext+opt+zFormat[2][i]);

           
            lagchilo=forward[2][i]-forward[1][i];
           
           opt=n-i+n-i+1;
         ext=lagchilo-opt;
             
              newPaichi=zFormat[1][i]-forward[1][i];
             ext-=newPaichi;
             if(ext<0)ext=0;
            
             res=min(res,ext+opt+zFormat[1][i]);
           

        }

  
        

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


