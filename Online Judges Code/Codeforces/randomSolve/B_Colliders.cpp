/**        بِسْمِ اللهِ الرَّحْمٰنِ الرَّحِيْمِ (In the name of God, the Most Gracious, the Most Merciful.)       */
/*
      Institution : Hajee Mohammad Danesh Science and Technology University,Dinajpur,Bangladesh.
      Name        : Ashikur Rahman Bhuyain (Asif)
      Email       : ashik.cse.hstu@gmail.com
*/

#include <bits/stdc++.h>
using namespace std;
#define ll long long int

#define MinHeap          priority_queue <int, vector<int>, greater<int> >
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
#define NUMLEN(Num)        to_string(Num).size()

#define POSL(x,v)          (lower_bound(x.begin(),x.end(),v)-x.begin())
#define POSU(x,v)          (upper_bound(x.begin(),x.end(),v)-x.begin())
#define min3(a,b,c)        min(a,min(b,c))
#define min4(a,b,c,d)      min(a,min(b,min(c,d)))
#define max3(a,b,c)        max(a,max(b,c))
#define max4(a,b,c,d)      max(a,max(b,max(c,d)))
#define ABS(x)             ((x)<0?-(x):(x))
#define pb                 push_back
#define nl                 printf("\n")

///vector
#define Lower_bound(vec,value) lower_bound(vec.begin(),vec.end(),value)
#define Upper_bound(vec,value) upper_bound(vec.begin(),vec.end(),value)
#define mnv(v) *min_element(all(v))
#define mxv(v) *max_element(all(v))

const int mod = 1e9 + 7;
const int maxn=100005;


const int N = 1001;
vector<int> lp(N+1);
vector<ll> pr;

void sieve()
{
    for (ll i=2; i <= N; ++i) {
    if (lp[i] == 0) {
        lp[i] = i;
        pr.push_back(i);
    }
    for (ll j=0; j < (int)pr.size() && pr[j] <= lp[i] && i*pr[j] <= N; ++j) {
        lp[i * pr[j]] = pr[j];
    }
}

}

vector<int>pct[maxn+3];
int n,q;
int one;

void handleOne(int op)
{
    if(op==1)
    {
        if(one==0)
        {
             cout<<"Success\n";
        }
        else {
            cout<<"Already on\n";
        }
        one=1;
    }

    else {
        if(one==0)
        {
            cout<<"Already off\n";
        }
        else {
            cout<<"Success\n";
        }

        one=0;
    }
}

void tryToAdd()
{
     int v;cin>>v;

     if(v==1)
     {
        handleOne(1);
        return;
     }

     int cv=v;
     int conflict=-1;
     vector<int>curP;
     for(int i=2;i*i<=v;i++)
     {
        if(v%i==0)
        {
            if(pct[i].size()!=0)
            {conflict=pct[i][0];
              break;
            }
            while(v%i==0)v/=i;
            curP.pb(i);
        }
     }
     if(v>1){
        if(pct[v].size()!=0)conflict=pct[v][0];
        curP.pb(v);
     }

     if(conflict!=-1)
     {
        if(conflict==cv)
        cout<<"Already on\n";
        else
        cout<<"Conflict with "<<conflict<<endl;
        return;
     }

     for(int i=0;i<curP.size();i++)
     {
        pct[curP[i]].pb(cv);
     }
     cout<<"Success\n";
 
}

void tryToRemove()
{
     int v;cin>>v;
     int cv=v;

   if(v==1)
   {
    handleOne(2);
    return;
   }

     for(int i=2;i*i<=v;i++)
     {
        if(v%i==0)
        {
            if(pct[i].size()==0)
            {
                cout<<"Already off\n";
                return;
            }
            if(pct[i][0]!=cv)
            {
                  cout<<"Already off\n";
                return;
            }

            pct[i].clear();
            while(v%i==0)
            v/=i;
        }
     }
     
     if(v>1)
     {
        int i=v;
        if(pct[i].size()==0)
            {
                cout<<"Already off\n";
                return;
            }
            if(pct[i][0]!=cv)
            {
                  cout<<"Already off\n";
                return;
            }

            pct[i].clear();

     }

     cout<<"Success\n";


}


void solve()
{
    one=0;
    cin>>n>>q;
      
     for(int i=0;i<q;i++)
     {
        char ch;cin>>ch;
        if(ch=='+')tryToAdd();
        else tryToRemove();
     } 



}

int main()
{
    //sieve();
    int tc=1;
    //cin>>tc;
    for(int i=1;i<=tc;i++)
    {
        solve();
    }

    return 0;
}

 
 /*"Success isn't permanent, failure isn't fatal,
                                      it's the courage to continue that counts"*/
