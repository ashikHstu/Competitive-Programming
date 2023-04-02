#include <bits/stdc++.h>
using namespace std;
#define maxn 100005

struct DSU
{
    int totalConnectedComponent;
    vector<int> parent, setSize, setMin, setMax;

    void init(int n)
    {
        parent = setSize = setMin = setMax = vector<int>(n + 1, 0);
        for (int i = 1; i <= n; i++)
        {
            parent[i] = setMin[i] = setMax[i] = i, setSize[i] = 1;
        }
        totalConnectedComponent = n;
    }

    int findParent(int u)
    {
        if (parent[u] == u)
            return u;
        return parent[u] = findParent(parent[u]);
    }

    /*
    int findParent(int u)
      {
          while (u != parent[u])
          {
              parent[u] = parent[parent[u]];
              u = parent[u];
          }
          return u;
      }
    */

    int getSetSize(int u)
    {
        return setSize[findParent(u)];
    }
    int getSetMin(int u)
    {
        return setMin[findParent(u)];
    }
    int getSetMax(int u)
    {
        return setMax[findParent(u)];
    }

    void Union(int u, int v)
    {
        int parent1 = findParent(u), parent2 = findParent(v);

        if (parent1 == parent2)
            return;

        totalConnectedComponent--;

        if (setSize[parent1] > setSize[parent2])
            swap(parent1, parent2);

        setSize[parent2] += setSize[parent1];
        setMin[parent2] = min(setMin[parent1], setMin[parent2]);
        setMax[parent2] = max(setMax[parent1], setMax[parent2]);
        setSize[parent1] = 0;
        parent[parent1] = parent[parent2];
    }

    bool isSameSet(int i, int j) { return findParent(i) == findParent(j); }
};

/*
int parent[maxn];
int dsize[maxn];
void init(int n)
{
    for (int i = 0; i <= n; i++)
    {
        parent[i] = i;
        dsize[i] = 1;
    }
}

int findParent(int v)
{

    if (v == parent[v])
        return v;
    return parent[v] = findParent(parent[v]);
}

void union_sets(int a, int b)
{
    a = findParent(a);
    b = findParent(b);
    if (a != b)
    {
        if (dsize[a] < dsize[b])
            swap(a, b);
        parent[b] = a;
        dsize[a] += dsize[b];
    }
}
*/

int main()
{

    return 0;
}