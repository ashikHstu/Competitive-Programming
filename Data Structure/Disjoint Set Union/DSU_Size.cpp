#include <bits/stdc++.h>
using namespace std;
#define maxn 100005
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

int main()
{
    init(10001);

    return 0;
}