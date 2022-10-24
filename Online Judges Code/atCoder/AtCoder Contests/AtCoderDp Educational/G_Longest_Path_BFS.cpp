/**
Problem link : https://atcoder.jp/contests/dp/tasks/dp_g
*/

#include <bits/stdc++.h>
using namespace std;
#define sz 100005

vector<int>g[sz];
int visited[sz];
int level[sz];
int indegree[sz];

int bfs(int n)
{
    queue<int>q;
    for(int i=1;i<=n;i++)
    {
        if(indegree[i]==0)
        {
            level[i]=0;
            q.push(i);
            visited[i]=1;
        }
    }
    int res=0;
    while(!q.empty())
    {
        int u=q.front();
        q.pop();
        res=level[u];

        for(int v:g[u])
        {
            if(!visited[v])
            {
                indegree[v]--;

                if(indegree[v]==0){
                visited[v]=1;
                level[v]=level[u]+1;
                q.push(v);
                }
            }
        }


    }

    return res;


}

int main()
{
    int n,m;
    cin>>n>>m;
    for(int i=0;i<m;i++){
        int u,v;cin>>u>>v;
        g[u].push_back(v);
        indegree[v]++;
    }
    cout<<bfs(n)<<endl;

    return 0;
}
