#include <bits/stdc++.h>
using namespace std;
#define int long long
struct segTree
{
    int size;
    vector<long long> operations;
    vector<long long> mins;
    void init(int n)
    {
        size = 1;
        while (size < n)
            size *= 2;
        operations.assign(2 * size, 0);
        mins.assign(2 * size, 0);
    }
    void Add(int l, int r, int v, int x, int lx, int rx)
    {
        if (l >= rx || r <= lx)
            return;
        if (lx >= l && rx <= r)
        {
            operations[x] += v;
            mins[x] += v;
            return;
        }
        int mid = (lx + rx) / 2;
        Add(l, r, v, x * 2 + 1, lx, mid);
        Add(l, r, v, x * 2 + 2, mid, rx);
        mins[x] = min(mins[x * 2 + 1], mins[x * 2 + 2]) + operations[x];
    }
    long long Min(int l, int r, int x, int lx, int rx)
    {
        if (l >= rx || r <= lx)
            return LLONG_MAX;
        if (lx >= l && rx <= r)
        {
            return mins[x];
        }
        int mid = (lx + rx) / 2;
        auto m1 = Min(l, r, x * 2 + 1, lx, mid);
        auto m2 = Min(l, r, x * 2 + 2, mid, rx);
        return min(m1, m2) + operations[x];
    }
    long long Min(int l, int r)
    {
        return Min(l, r, 0, 0, size);
    }
    void Add(int l, int r, int v)
    {
        Add(l, r, v, 0, 0, size);
    }
    long long Get(int i, int x, int lx, int rx)
    {
        if (rx - lx == 1)
        {
            return operations[x];
        }
        int mid = (lx + rx) / 2;
        long long res;
        if (i < mid)
        {
            res = Get(i, 2 * x + 1, lx, mid);
        }
        else
        {
            res = Get(i, 2 * x + 2, mid, rx);
        }
        return res + operations[x];
    }
    long long Get(int i)
    {
        return Get(i, 0, 0, size);
    }
};
int32_t main()
{
    int n, q;
    cin >> n >> q;
    segTree ST;
    ST.init(n);
    for (int i = 0; i < q; i++)
    {
        int type;
        cin >> type;
        if (type == 1)
        {
            int l, r, v;
            cin >> l >> r >> v;
            ST.Add(l, r, v);
        }
        else
        {
            int l, r;
            cin >> l >> r;
            cout << ST.Min(l, r) << endl;
        }
    }
    return 0;
}