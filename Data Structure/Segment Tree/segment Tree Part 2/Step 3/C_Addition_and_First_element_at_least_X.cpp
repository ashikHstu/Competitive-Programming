/**        بِسْمِ اللهِ الرَّحْمٰنِ الرَّحِيْمِ (In the name of God, the Most Gracious, the Most Merciful.)       */
/*
      Institution : Hajee Mohammad Danesh Science and Technology University,Dinajpur,Bangladesh.
      Name        : Ashikur Rahman Bhuyain (Asif)
      Email       : ashik.cse.hstu@gmail.com
*/

/*
   Problem link : https://codeforces.com/edu/course/2/lesson/5/3/practice/contest/280799/problem/C
   verdict : Accepted
*/

#pragma GCC optimize("O3,unroll-loops")
#pragma GCC target("avx2,bmi,bmi2,lzcnt,popcnt")

#include <bits/stdc++.h>
using namespace std;

#define ll long long

struct segtree
{
    struct node
    {
        int max;
        int modify;
    };

    const int NO_OP = INT_MAX;

    int size;
    vector<node> tree;

    void build(int n)
    {
        size = 1;
        while (size < n)
            size *= 2;
        tree.assign(2 * size, {0, NO_OP});
    }

    int _modify(int a, int b)
    {
        if (a == NO_OP)
            return b;
        return a + b;
    }

    void propagate(int x, int lx, int rx)
    {
        if (tree[x].modify == NO_OP || rx == lx + 1)
            return;
        tree[2 * x + 1].modify = _modify(tree[2 * x + 1].modify, tree[x].modify);
        tree[2 * x + 1].max = tree[2 * x + 1].max + tree[x].modify;
        tree[2 * x + 2].modify = _modify(tree[2 * x + 2].modify, tree[x].modify);
        tree[2 * x + 2].max = tree[2 * x + 2].max + tree[x].modify;
        tree[x].modify = NO_OP;
    }

    void update(int l, int r, int v)
    {
        update(l, r, v, 0, 0, size);
    }

    void update(int l, int r, int v, int x, int lx, int rx)
    {
        propagate(x, lx, rx);
        if (lx >= r)
            return;
        if (rx <= l)
            return;
        if (lx >= l && rx <= r)
        {
            tree[x].modify = v;
            tree[x].max += v;
        }
        else
        {
            int m = (lx + rx) / 2;
            update(l, r, v, 2 * x + 1, lx, m);
            update(l, r, v, 2 * x + 2, m, rx);
            tree[x].max = max(tree[2 * x + 1].max, tree[2 * x + 2].max);
        }
    }

    int get(int v, int l)
    {
        return get(v, l, 0, 0, size);
    }

    int get(int v, int l, int x, int lx, int rx)
    {
        propagate(x, lx, rx);

        if (rx <= l)
            return -1;
        if (tree[x].max < v)
            return -1;
        if (rx == lx + 1)
            return lx;

        int m = (lx + rx) / 2;
        int res = get(v, l, 2 * x + 1, lx, m);
        if (res == -1)
            res = get(v, l, 2 * x + 2, m, rx);
        return res;
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
        int type;
        cin >> type;
        if (type == 1)
        {
            int l, r, v;
            cin >> l >> r >> v;
            st.update(l, r, v); // add v to all the elements from L to R-1
        }
        else if (type == 2)
        {
            int x, l;
            cin >> x >> l;
            cout << st.get(x, l) << endl; // find miminum index from L(0 based index) to end, whose value is >=x
        }
    }

    return 0;
}

/*"Success isn't permanent, failure isn't fatal,
                                     it's the courage to continue that counts"*/
