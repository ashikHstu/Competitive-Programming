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
#define sz 200005

int ar[sz];
int n;

pair<int,int>tree[sz*4];

void build(int node,int b,int e)
{
    if(b==e)
    {
        tree[node]={ar[b],b};
        return;
    }
    int left=node*2;
    int right=left+1;
    int mid=(b+e)/2;
    build(left,b,mid);
    build(right,mid+1,e);
    tree[node]=min(tree[left],tree[right]);
}

void update(int node,int b,int e,int indx,int v)
{
    if(indx>e || indx<b || b>e)
        return;
    if(b==e)
    {
        tree[node]={v,indx};
        return;
    }

    int left=node*2;
    int right=left+1;
    int mid=(b+e)/2;

    if(indx<=mid)
        update(left,b,mid,indx,v);
    else update(right,mid+1,e,indx,v);

//    update(left,b,mid,indx,v);
//    update(right,mid+1,e,indx,v);
    tree[node]=min(tree[left],tree[right]);

}

pair<int,int>query(int node,int b,int e,int i,int j)
{
    if(i>e || j<b)
    {
        return {2000000005,-1};
    }

    if(i<=b && j>=e)
    {
        return tree[node];
    }

    int left=node*2;
    int right=left+1;
    int mid=(b+e)/2;
    pair<int,int>p1=query(left,b,mid,i,j);
    pair<int,int>p2=query(right,mid+1,e,i,j);
    return min(p1,p2);


}


void solve()
{
   cin>>n;

   for(int i=1;i<=n;i++)
   {
       cin>>ar[i];
   }


    build(1,1,n);


//    cout<<"built test : ";
//    for(int i=1;i<=n;i++)
//    {
//        cout<<query(1,1,n,i,i).first<<endl;
//    }



    int q;cin>>q;

    for(int i=0;i<q;i++)
    {
        int l,r;cin>>l>>r;

        vector<pair<int,int>>minV;
        int lm=min(r-l+1,31);

       // cout<<"printing pair of a query : "<<endl;
        for(int j=0;j<lm;j++)
        {
            pair<int,int>p=query(1,1,n,l,r);

         //   cout<<"index is : "<<p.second<<" "<<p.first<<endl;
            int ind=p.second;
            minV.pb(p);
            update(1,1,n,p.second,2000000002);
        }


        int mn=2000000002;
        for(int j=0;j<lm;j++)
        {
            for(int k=j+1;k<lm;k++)
            {
                int xo=(minV[j].first | minV[k].first);
                mn=min(xo,mn);
            }
        }


        cout<<mn<<endl;
        for(int j=0;j<lm;j++)
        {
            update(1,1,n,minV[j].second,minV[j].first);
        }

    }


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


