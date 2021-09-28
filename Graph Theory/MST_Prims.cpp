#include <bits/stdc++.h>
using namespace std;
#define SIZE 1001
int visited[SIZE]={0};
vector<int>edge[SIZE];
vector<int>cost[SIZE];
struct data
{
    int v,w;
    bool operator < (data p)const{
       return w>p.w;
    }
};
int prims(int src,int n)
{
    priority_queue<data>pq;
    int u,v,p;
    int sum=0;
    for(int i=0;i<n-1;i++)
    {
        u=src;
        visited[src]=1;
        for(int j=0;j<edge[u].size();j++)
        {
            v=edge[u][j];
            if(visited[v]==0)
            {
                data d;
                d.v=v;
                d.w=cost[u][j];
                pq.push(d);
            }
        }
        while(visited[src] )
        {
            data T =pq.top();
            pq.pop();
            src=T.v;
            p=T.w;
        }
         sum+=p;

    }
    return sum;
}
int main()
{
    int n,e,n1,n2,w;
    cin>>n>>e;
    for(int i=0;i<e;i++)
    {
        cin>>n1>>n2>>w;
        edge[n1].push_back(n2);
        edge[n2].push_back(n1);
        cost[n1].push_back(w);
        cost[n2].push_back(w);
    }
    cout<<"total cost is : "<<prims(1,n);
    return 0;
}

