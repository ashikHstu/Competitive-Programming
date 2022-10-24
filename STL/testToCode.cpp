#include <bits/stdc++.h>
using namespace std;
#define ll long long int

struct data
{
    int u,v,w;
    data(int _u,int _v,int _w)
    {
        u=_u;
        v=_v;
        w=_w;
    }


};



int parent[200005];
void assignParent(int n)
{
    for(int i=0; i<=n; i++)
        parent[i]=i;
}

int findParent(int n)
{
    if(parent[n]==n)
        return n;
    else
        return parent[n]=findParent(parent[n]);
}


vector<data>vec;

vector<int>g[200005];
int color[200005];
void dfs(int i)
{
    color[i]=1;
    for(int v:g[i])
    {
        if(color[v]==0)
            dfs(v);
    }
}

void solve()
{
    ll n,m;
    cin>>n>>m;
    vec.clear();

    int nodeUsed[m+2]= {0};

    for(int i=0; i<m; i++)
    {
        int u,v,w;
        cin>>u>>v>>w;
        vec.push_back(data(u,v,w));
    }
    ll res=1;
    res=res<<30;
    res--;

   // cout<<"initial res : "<<res<<endl;
    for(int i=29; i>=0; i--)
    {

        assignParent(n);
        for(int i=0; i<=n; i++)
        {
            g[i].clear();
            color[i]=0;
        }

        for(int j=0; j<m; j++)
        {
            int v=vec[j].v;
            int u=vec[j].u;
            int w=vec[j].w;

            if(w&(1<<i) || nodeUsed[j])
            {

                continue;
            }



            int p1=findParent(u);
            int p2=findParent(v);
            if(p1!=p2)
            {
                parent[p1]=p2;
                g[u].push_back(v);
            g[v].push_back(u);

            }

        }

        int connect=0;
        for(int i=1; i<=n; i++)
        {
            if(color[i]==0)
            {
                connect++;
                dfs(i);
            }
        }
       // cout<<"connect : "<<connect<<endl;

        if(connect==1)
        {


            for(int j=0; j<m; j++)
            {
                int w=vec[j].w;

                if(w&(1<<i))
                {

                    nodeUsed[j]=1;
                }


            }



            res=res^(1ll<<i);
            //cout<<"ever connected?, updated res : "<<res<<endl;
        }
        else
        {
           // cout<<"not connected at : "<<i<<endl;
        }



    }

    cout<<res<<endl;




}

int main()
{
    int tc;
    cin>>tc;

    while(tc--)
    {
        solve();
    }

    return 0;
}
