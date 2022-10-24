/// Problem link : https://atcoder.jp/contests/abc218/tasks/abc218_e

#include <bits/stdc++.h>
using namespace std;
#define int long long int

int parent[200005];

void makeSet(int n)
{
    for(int i=0;i<=n;i++)parent[i]=i;
}

int findParent(int n)
{
    if(parent[n]==n)return n;
    else return parent[n]=findParent(parent[n]);
}

struct d
{
    int u,v;
     int w;
    d(int _u,int _v,int _w)
    {
        u=_u;
        v=_v;
        w=_w;
    }

    bool operator<(const d &p)const
    {
        return w<p.w;
    }

};

int32_t main()
{
    int n;

    cin>>n;
    makeSet(n);
    vector<d>edges;
    int m;cin>>m;

    for(int i=0;i<m;i++)
    {
        int u,v;
        int w;
        cin>>u>>v>>w;
        edges.push_back(d(u,v,w));
    }
    sort(edges.begin(),edges.end());
    int res=0;
    for(int i=0;i<m;i++)
    {
        int p1=findParent(edges[i].u);
        int p2=findParent(edges[i].v);
        if(p1!=p2)
        {
            parent[p1]=p2;
        }
        else {
                if(edges[i].w >0)
            res+=edges[i].w;
        }
    }

    //cout<<"res : ";
    cout<<res<<endl;

    return 0;


}

