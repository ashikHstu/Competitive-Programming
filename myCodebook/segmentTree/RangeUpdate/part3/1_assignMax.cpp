#include <bits/stdc++.h>
using namespace std;
#define ll long long
struct segtree
{
    struct info
    {
        ll seg, pref, suf, sum;
    };
    struct node
    {
        info value;
        ll modify;
    };
    const ll NO_OP = LLONG_MIN;
    int size;
    vector<node> tree;
    void build(int n)
    {
        size = 1;
        while (size < n)
            size *= 2;
        tree.assign(2 * size, {{0, 0, 0, 0}, NO_OP});
    }
    info combine(info a, info b)
    {
        return {
            max(a.suf + b.pref, max(a.seg, b.seg)),
            max(a.pref, a.sum + b.pref),
            max(b.suf, a.suf + b.sum),
            a.sum + b.sum};
    }
    void propagate(int x, int lx, int rx)
    {
        if (tree[x].modify == NO_OP || rx == lx + 1)
            return;
        int m = (lx + rx) / 2;
        tree[2 * x + 1].modify = tree[x].modify;
        if (tree[x].modify < 0)
        {
            tree[2 * x + 1].value.seg = tree[2 * x + 1].value.pref = tree[2 * x + 1].value.suf = 0;
            tree[2 * x + 1].value.sum = (m - lx) * tree[x].modify;
        }
        else
        {
            tree[2 * x + 1].value.seg = tree[2 * x + 1].value.pref = tree[2 * x + 1].value.suf = tree[2 * x + 1].value.sum = (m - lx) * tree[x].modify;
        }
        tree[2 * x + 2].modify = tree[x].modify;
        if (tree[x].modify < 0)
        {
            tree[2 * x + 2].value.seg = tree[2 * x + 2].value.pref = tree[2 * x + 2].value.suf = 0;
            tree[2 * x + 2].value.sum = (rx - m) * tree[x].modify;
        }
        else
        {
            tree[2 * x + 2].value.seg = tree[2 * x + 2].value.pref = tree[2 * x + 2].value.suf = tree[2 * x + 2].value.sum = (rx - m) * tree[x].modify;
        }
        tree[x].modify = NO_OP;
    }
    void update(int l, int r, ll v)
    {
        update(l, r, v, 0, 0, size);
    }
    void update(int l, int r, ll v, int x, int lx, int rx)
    {
        propagate(x, lx, rx);
        if (lx >= r)
            return;
        if (rx <= l)
            return;
        if (lx >= l && rx <= r)
        {
            tree[x].modify = v;
            if (v < 0)
            {
                tree[x].value.seg = tree[x].value.pref = tree[x].value.suf = 0;
                tree[x].value.sum = (rx - lx) * v;
            }
            else
            {
                tree[x].value.seg = tree[x].value.pref = tree[x].value.suf = tree[x].value.sum = (rx - lx) * v;
            }
        }
        else
        {
            int m = (lx + rx) / 2;
            update(l, r, v, 2 * x + 1, lx, m);
            update(l, r, v, 2 * x + 2, m, rx);
            tree[x].value = combine(tree[2 * x + 1].value, tree[2 * x + 2].value);
        }
    }
    ll get()
    {
        propagate(0, 0, size);
        return tree[0].value.seg;
    }
};
int main()
{
    int n, m;
    cin >> n >> m;
    segtree st;
    st.build(n);
    for (int i = 0; i < m; i++)
    {
        int l, r, v;
        cin >> l >> r >> v;
        st.update(l, r, v); // update the value from L to R-1 to V
        cout << st.get() << endl;
    }
    return 0;
}