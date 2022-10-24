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
    int n,m;cin>>n>>m;
    int ar[n+2][m+2],ar2[n+2][m+2];
int curX,curY,X,Y;
X=Y=curX=curY=-1;
bool ok=true;
    for(int i=0;i<n;i++)
    {
        for(int j=0;j<m;j++)
        {
            cin>>ar[i][j];
            ar2[i][j]=ar[i][j];
        }
        sort(ar2[i],ar2[i]+m);
        vector<int>curC;
        for(int j=0;j<m;j++)
        {
            if(ar2[i][j]!=ar[i][j])
            {
                curC.pb(j);
            }
        }
        if(curC.size()>2)ok=false;
        else if(curC.size()==2){
             if(X!=-1)
             {
                 if(curC[0]!=X)ok=false;
                 if(curC[1]!=Y)ok=false;
             }
             else {
                 X=curC[0];
                 Y=curC[1];
             }

        }

    }
    if(!ok)
    {
        cout<<"-1"<<endl;
        //cout<<"Minus One"<<endl;
        return;
    }

     if(X==-1)
     {
         cout<<"1 1"<<endl;
        // cout<<"Default One"<<endl;
         return;
     }


//cout<<"value of X and Y : "<<X<<" , "<<Y<<endl;

     for(int i=0;i<n;i++)
     {
         swap(ar[i][X],ar[i][Y]);
         for(int j=0;j<m-1;j++)
         {
             if(ar[i][j]>ar[i][j+1])
             {
                 cout<<"-1\n";
                // cout<<"Minus two"<<endl;
                 return;
             }
         }
     }

     cout<<X+1<<" "<<Y+1<<endl;




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


