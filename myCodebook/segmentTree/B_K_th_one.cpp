
#include <bits/stdc++.h>
using namespace std;
typedef int item;
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

    for (int i = 0; i < q; i++)
    {
        int op;
        cin >> op;
        if (op == 1)
        {
            int ind;
            cin >> ind;
            a[ind] = 1 - a[ind];
            ST.set(ind, a[ind]);
        }
        else
        {
            int k;
            cin >> k;
            cout << ST.find(k) << endl;
        }
    }
    return 0;
}