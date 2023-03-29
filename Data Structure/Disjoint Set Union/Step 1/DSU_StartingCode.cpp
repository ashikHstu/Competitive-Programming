#include <bits/stdc++.h>
using namespace std;
#define maxn 100005
int parent[maxn];
vector<int> list[maxn];
void init(int n)
{
    for (int i = 0; i <= n; i++)
        parent[i] = i;
}

int get(int a)
{

    return parent[a];
}

void Union(int a, int b)
{
}

int main()
{
}