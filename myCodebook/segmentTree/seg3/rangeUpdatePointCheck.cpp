#include <bits/stdc++.h>
using namespace std;
#define int long long
typedef long long item;
struct segTree
{
    int size;
    vector<item> values;
    item NEUTRAL_ELEMENT = 0;
    item Single(int v)
    {
        return v;
    }
    item Merge(item a, item b)
    {
        return a + b;
    }
    // O(log(n)
    void init(int n)
    {
        size = 1;
        while (size < n)
            size *= 2;
        values.resize(2 * size, 0);
    }
    // O(nlogn) , although said, O(n), i think O(nlogn)
    void build(vector<int> &a, int x, int lx, int rx)
    {
        if (rx - lx == 1)
        {
            if (lx < a.size())
            {
                values[x] = Single(a[lx]);
            }
            return;
        }
        int mid = (lx + rx) / 2;
        build(a, x * 2 + 1, lx, mid);
        build(a, x * 2 + 2, mid, rx);
        values[x] = Merge(values[2 * x + 1], values[2 * x + 2]);
    }
    void build(vector<int> &a)
    {
        build(a, 0, 0, size);
    }
    /// O(logn)
    void set(int i, int v, int x, int lx, int rx)
    {
        if (rx - lx == 1)
        {
            values[x] = Single(v);
            return;
        }
        int mid = (lx + rx) / 2;
        if (i < mid)
        {
            set(i, v, 2 * x + 1, lx, mid);
        }
        else
        {
            set(i, v, 2 * x + 2, mid, rx);
        }
        values[x] = Merge(values[2 * x + 1], values[2 * x + 2]);
    }
    void set(int i, int v)
    {
        set(i, v, 0, 0, size);
    }
    // O(logn)
    void Add(int i, int v, int x, int lx, int rx)
    {
        if (rx - lx == 1)
        {
            values[x] = values[x] + Single(v);
            return;
        }
        int mid = (lx + rx) / 2;
        if (i < mid)
        {
            Add(i, v, 2 * x + 1, lx, mid);
        }
        else
        {
            Add(i, v, 2 * x + 2, mid, rx);
        }
        values[x] = Merge(values[2 * x + 1], values[2 * x + 2]);
    }
    void Add(int i, int v)
    {
        Add(i, v, 0, 0, size);
    }
    /// O(logn)
    item calc(int l, int r, int x, int lx, int rx)
    {
        if (l >= rx || r <= lx)
            return NEUTRAL_ELEMENT;
        if (lx >= l && rx <= r)
            return values[x];
        int mid = (lx + rx) / 2;
        item s1 = calc(l, r, x * 2 + 1, lx, mid);
        item s2 = calc(l, r, x * 2 + 2, mid, rx);
        return Merge(s1, s2);
    }
    item calc(int l, int r)
    {
        return calc(l, r, 0, 0, size);
    }
    /// O(logn)
    int find(int k, int x, int lx, int rx)
    {
        if (rx - lx == 1)
        {
            return lx;
        }
        int mid = (lx + rx) / 2;
        int daneAche = values[x * 2 + 1];
        // int bameAche=values[x*2+2];
        if (k < daneAche)
        {
            return find(k, x * 2 + 1, lx, mid);
        }
        else
        {
            return find(k - daneAche, x * 2 + 2, mid, rx);
        }
    }
    int find(int k)
    {
        return find(k, 0, 0, size);
    }
    /// O(logn)
    int first_above(int v, int l, int x, int lx, int rx)
    {
        if (values[x] < v)
            return -1;
        if (rx <= l)
            return -1;
        if (rx - lx == 1)
            return lx;
        int mid = (lx + rx) / 2;
        int res = first_above(v, l, 2 * x + 1, lx, mid);
        if (res == -1)
        {
            res = first_above(v, l, 2 * x + 2, mid, rx);
        }
        return res;
    }
    int first_above(int v, int l)
    {
        return first_above(v, l, 0, 0, size);
    }
};
int32_t main()
{
    int n, m;
    cin >> n >> m;
    segTree ST;
    ST.init(n + 1);
    for (int i = 0; i < m; i++)
    {
        int type;
        cin >> type;
        if (type == 1)
        {
            int l, r, v;
            cin >> l >> r >> v;
            ST.Add(l, v);
            ST.Add(r, -v);
        }
        else
        {
            int ind;
            cin >> ind;
            int res = ST.calc(0, ind + 1);
            cout << res << endl;
        }
    }
    return 0;
}