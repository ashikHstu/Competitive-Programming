#include <bits/stdc++.h>
using namespace std;
#define infinity 1<<28
#define mx 100
void FloyedWarshal(int n,int g[][mx])
{
    for(int k=1;k<=n;k++)
    {
        for(int i=1;i<=n;i++)
        {
            for(int j=1;j<=n;j++)
            {
                g[i][j]=min(g[i][j],g[i][k]+g[k][j]);
            }
        }
    }
}
int main()
{
   int g[mx][mx];
   int numNode,numEdge;
   cin>>numNode>>numEdge;
   for(int i=1;i<=numNode;i++)
   {
       for(int j=1;j<=numNode;j++)
       {
           if(i==j)g[i][j]=0;
           else g[i][j]=infinity;
       }
   }
   for(int i=0;i<numEdge;i++)
   {
       int u,v,w;
       cin>>u>>v>>w;
       g[u][v]=w;
       //g[v][u]=w;
   }
   FloyedWarshal(numNode,g);
   for(int i=1;i<=numNode;i++)
   {
       for(int j=1;j<=numNode;j++)
       {
           cout<<g[i][j]<<" ";
       }cout<<endl;
   }
   return 0;
}
