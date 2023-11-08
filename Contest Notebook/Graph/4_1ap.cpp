#define MAXN 10001

vector<int>G[MAXN];
int parent[MAXN];
int low[MAXN];
int d[MAXN];
int visited[MAXN]; /// Color[MAXN]
bool isArticulationPoint[MAXN];
int Time=0;
vector<pair<int,int>>bridge;
void FindArticulationPoint(int u,int root) /// Similar to DFS
{
    Time=Time+1;
    visited[u]=1;
    d[u]=low[u]=Time;
    int numberOfChildren=0;
    for(int i=0;i<(int)G[u].size();i++)
    {
        int v=G[u][i];
        if(parent[u]==v)continue;
        parent[v]=u;
        if(visited[v])
        {
            low[u]=min(low[u],d[v]);

        }
        else {
            numberOfChildren++;
            FindArticulationPoint(v,root);
            low[u]=min(low[u],low[v]);
            if(low[v]>=d[u] and u!=root)isArticulationPoint[u]=true;

            /** to find bridge : */
               if(low[v]>d[u]){
                pair<int,int>b=make_pair(u,v);
                bridge.push_back(b);
               }
        }
    }

    /** not for bridge */
    if(u==root and numberOfChildren>1)
    {
        isArticulationPoint[u]=true;
    }
    Time++; /// For finishing time(not given in blog)

}

