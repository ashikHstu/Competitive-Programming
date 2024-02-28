#include <bits/stdc++.h>
using namespace std;
struct item
{
    long long seg, pref, suf, sum;
};
struct segTree
{
    int size;
    vector<item> values;
    item NEUTRAL_ELEMENT = {0, 0, 0, 0};
    item Single(int v)
    {
        if (v > 0)
            return {v, v, v, v};
        else
            return {0, 0, 0, v};
    }
    item Merge(item a, item b)
    {
        return {
            max(a.seg, max(b.seg, a.suf + b.pref)),
            max(a.pref, a.sum + b.pref),
            max(b.suf, b.sum + a.suf),
            a.sum + b.sum};
    }
    void init(int n)
    {
        size = 1;
        while (size < n)
            size *= 2;
        values.resize(2 * size);
    }
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
};
int main()
{
    int n, q;
    cin >> n >> q;
    vector<int> a(n);
    for (int i = 0; i < n; i++)
        cin >> a[i];
    segTree ST;
    ST.init(n);
    ST.build(a);
    cout << ST.calc(0, n).seg << endl;
    for (int i = 0; i < q; i++)
    {
        int ind, v;
        cin >> ind >> v;
        ST.set(ind, v);
        cout << ST.calc(0, n).seg << endl;
    }
    return 0;
}