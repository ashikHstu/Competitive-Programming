#include <bits/stdc++.h>
using namespace std;
#define int long long
const long long MOD = 1000000007;
struct segTree
{
    int size;
    vector<long long> operations;
    vector<long long> values;
    long long NEUTRAL_ELEMENT = 0;
    long long modify_op(long long a, long long b)
    {
        return (a * b) % MOD;
    }
    long long calc_op(long long a, long long b)
    {
        return (a + b) % MOD;
    }
    void apply_mod_op(long long &a, long long b)
    {
        a = modify_op(a, b);
    }
    void build(int x, int lx, int rx)
    {
        if (rx == lx + 1)
        {
            values[x] = 1;
            return;
        }
        int mid = (lx + rx) / 2;
        build(2 * x + 1, lx, mid);
        build(2 * x + 2, mid, rx);
        values[x] = calc_op(values[x * 2 + 1], values[2 * x + 2]);
    }
    void init(int n)
    {
        size = 1;
        while (size < n)
            size *= 2;
        operations.assign(2 * size, 1LL);
        values.assign(2 * size, 0);
        build(0, 0, size);
    }
    void Modify(int l, int r, int v, int x, int lx, int rx)
    {
        if (l >= rx || r <= lx)
            return;
        if (lx >= l && rx <= r)
        {
            apply_mod_op(operations[x], v);
            apply_mod_op(values[x], v);
            return;
        }
        int mid = (lx + rx) / 2;
        Modify(l, r, v, x * 2 + 1, lx, mid);
        Modify(l, r, v, x * 2 + 2, mid, rx);
        values[x] = calc_op(values[x * 2 + 1], values[x * 2 + 2]);
        apply_mod_op(values[x], operations[x]);
    }
    void Modify(int l, int r, int v)
    {
        Modify(l, r, v, 0, 0, size);
    }
    long long calc(int l, int r, int x, int lx, int rx)
    {
        if (l >= rx || r <= lx)
            return NEUTRAL_ELEMENT;
        if (lx >= l && rx <= r)
        {
            return values[x];
        }
        int mid = (lx + rx) / 2;
        auto m1 = calc(l, r, x * 2 + 1, lx, mid);
        auto m2 = calc(l, r, x * 2 + 2, mid, rx);
        auto res = calc_op(m1, m2);
        apply_mod_op(res, operations[x]);
        return res;
    }
    long long calc(int l, int r)
    {
        return calc(l, r, 0, 0, size);
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
            ST.Modify(l, r, v);
        }
        else
        {
            int l, r;
            cin >> l >> r;
            cout << ST.calc(l, r) << endl;
        }
    }
    return 0;
}