#include <bits/stdc++.h>
using namespace std;
#define ll long long
struct segtree
{
    struct node
    {
        int sum;
        bool inverse;
    };
    int size;
    vector<node> tree;
    void build(int n)
    {
        size = 1;
        while (size < n)
            size *= 2;
        tree.assign(2 * size, {0, false});
    }
    void propagate(int x, int lx, int rx)
    {
        if (tree[x].inverse == false || rx == lx + 1)
            return;
        int m = (lx + rx) / 2;
        tree[2 * x + 1].inverse = !tree[2 * x + 1].inverse;
        tree[2 * x + 1].sum = (m - lx) - tree[2 * x + 1].sum;
        tree[2 * x + 2].inverse = !tree[2 * x + 2].inverse;
        tree[2 * x + 2].sum = (rx - m) - tree[2 * x + 2].sum;
        tree[x].inverse = false;
    }
    void update(int l, int r)
    {
        update(l, r, 0, 0, size);
    }
    void update(int l, int r, int x, int lx, int rx)
    {
        propagate(x, lx, rx);
        if (lx >= r)
            return;
        if (rx <= l)
            return;
        if (lx >= l && rx <= r)
        {
            tree[x].inverse = true;
            tree[x].sum = (rx - lx) - tree[x].sum;
        }
        else
        {
            int m = (lx + rx) / 2;
            update(l, r, 2 * x + 1, lx, m);
            update(l, r, 2 * x + 2, m, rx);
            tree[x].sum = tree[2 * x + 1].sum + tree[2 * x + 2].sum;
        }
    }
    int get(int k)
    {
        return get(k, 0, 0, size);
    }
    int get(int k, int x, int lx, int rx)
    {
        propagate(x, lx, rx);
        if (rx == lx + 1)
        {
            return lx;
        }
        int m = (lx + rx) / 2;
        if (tree[2 * x + 1].sum <= k)
        {
            return get(k - tree[2 * x + 1].sum, 2 * x + 2, m, rx);
        }
        return get(k, 2 * x + 1, lx, m);
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
        int t;
        cin >> t;
        if (t == 1)
        {
            int l, r;
            cin >> l >> r;
            st.update(l, r); // change from L to R-1 , the opposite (0|1 to 1|0)
        }
        else
        {
            int ind;
            cin >> ind;
            cout << st.get(ind) << endl; // get the index of kth one(one is zero base indexed)
        }
    }
    return 0;
}