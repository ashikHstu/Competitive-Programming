#include <bits/stdc++.h>
using namespace std;
#define MAXN 10001
 struct edge
 {
     int u,v,w;
     bool operator <(const edge &p) const
     {
         return w<p.w;
     }
 };

 int parent[MAXN];
 vector<edge>e;
 void makeset(int n)
 {
     for(int i=1;i<=n;i++)parent[i]=i;

 }
 int Find(int node)
 {
     if(node==parent[node])
        return node;
     else return parent[node]=Find(parent[node]);
 }
 int kruskal(int n)
 {
     sort(e.begin(),e.end());
     makeset(n);
     int ct=0,sum=0;
     for(int i=0;i<(int)e.size();i++)
     {
         int u=Find(e[i].u);
         int v=Find(e[i].v);
         if(u!=v)
         {
             parent[u]=v;
             ct++;
             sum+=e[i].w;
             if(ct==n-1)return sum;
         }
     }
     return sum;
 }
 int main()
 {
     int n,ed;
     cin>>n>>ed;
     int w,v,u;
     for(int i=0;i<ed;i++)
     {
         cin>>u>>v>>w;
         edge get;
         get.u=u;
         get.v=v;
         get.w=w;
         e.push_back(get);
     }
     cout<<"Krushkal cost is : "<<kruskal(n)<<endl;
     return 0;
 }

