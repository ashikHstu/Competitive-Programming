/**        بِسْمِ اللهِ الرَّحْمٰنِ الرَّحِيْمِ (In the name of God, the Most Gracious, the Most Merciful.)       */
/*
      Institution : Hajee Mohammad Danesh Science and Technology University,Dinajpur,Bangladesh.
      Name        : Ashikur Rahman Bhuyain (Asif)
      Email       : ashik.cse.hstu@gmail.com
*/
/*
   Problem link : https://codeforces.com/edu/course/2/lesson/5/1/practice/contest/279634/problem/C
   Status : Accepted

*/

#include <bits/stdc++.h>
using namespace std;
#define int long long
struct segTree
{
    int size;
    vector<long long> operations;
    long long NO_OPERATION = LLONG_MAX;

    long long operation(long long a, long long b)
    {
        if (b == NO_OPERATION)
            return a;
        return b;
    }

    void apply_operation(long long &a, long long b)
    {
        a = operation(a, b);
    }

    void init(int n)
    {
        size = 1;
        while (size < n)
            size *= 2;
        operations.assign(2 * size, 0);
    }

    void propagate(int x, int lx, int rx)
    {
        if (rx - lx == 1)
            return;
        apply_operation(operations[2 * x + 1], operations[x]);
        apply_operation(operations[2 * x + 2], operations[x]);
        operations[x] = NO_OPERATION;
    }

    void Modify(int l, int r, int v, int x, int lx, int rx)
    {
        propagate(x, lx, rx);
        if (l >= rx || r <= lx)
            return;
        if (lx >= l && rx <= r)
        {
            apply_operation(operations[x], v);
            return;
        }
        int mid = (lx + rx) / 2;
        Modify(l, r, v, x * 2 + 1, lx, mid);
        Modify(l, r, v, x * 2 + 2, mid, rx);
    }

    void Modify(int l, int r, int v)
    {
        Modify(l, r, v, 0, 0, size);
    }

    long long Get(int i, int x, int lx, int rx)
    {
        propagate(x, lx, rx);
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
        return res;
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
            int ind;
            cin >> ind;
            cout << ST.Get(ind) << endl;
        }
    }

    return 0;
}
