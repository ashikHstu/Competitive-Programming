
/*
      Institution : Hajee Mohammad Danesh Science and Technology University,Dinajpur,Bangladesh.
      Name        : Ashikur Rahman Bhuyain (Asif)
      Email       : ashik.cse.hstu@gmail.com
*/

#include <bits/stdc++.h>
using namespace std;



#define ll long long int

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




#define ABS(x)             ((x)<0?-(x):(x))
#define pb                 push_back
#define nl                 printf("\n")


int parent[100055];
int Rank[100055];

void makeParent(int n)
{
    for(int i=0; i<=n; i++)
        parent[i]=i;
}

int findParent(int p)
{
    if(parent[p]==p)return p;
    return parent[p]=findParent(parent[p]);
}

void unionSet(int a, int b){
    int pa=findParent(a);
    int pb=findParent(b);
    if(pa==pb)return;
    else if(Rank[pa]>Rank[pb])
    {
        parent[pa]=pa;
        parent[pb]=pa;
    }
    else if(Rank[pa]<Rank[pb])
    {
        parent[pb]=pb;
        parent[pa]=pb;
    }
    else
    {
        if(pa>pb)
        {
            parent[pa]=pa;
            parent[pb]=pa;
        }
        else if(pa<pb)
        {
            parent[pb]=pb;
            parent[pa]=pb;
        }
    }
}

void solve()
{

    int n,q;
    cin>>n>>q;
    makeParent(n+3);
    int ar[n+3];
    int curR=n;
    for(int i=0; i<n; i++)
    {
        cin>>ar[i];
        Rank[ar[i]]=curR;
        curR--;
    }




    for(int i=0; i<q; i++)
    {
        int type;
        cin>>type;
        if(type==1)
        {

            int a,b;
            cin>>a>>b;
            unionSet(a,b);
        }
        else if(type==2)
        {
            int id;
            cin>>id;
            Rank[id]++;
            int pid=findParent(id);
            if(id==pid)continue;
            if(Rank[pid]<Rank[id])
            {
                parent[id]=id;
                parent[pid]=id;
            }
            else if(Rank[pid]==Rank[id] && id>pid)
            {
                parent[id]=id;
                parent[pid]=id;
            }
        }
        else
        {
            int need;
            cin>>need;
            int p=findParent(need);


            cout<<p<<"\n";
        }
    }


}

int main()
{
    FasterIO;

    int tc=1;
    // cin>>tc;
    for(int i=1; i<=tc; i++)
    {
        solve();
    }

    return 0;
}


/*"Success isn't permanent, failure isn't fatal,
                                     it's the courage to continue that counts"*/

