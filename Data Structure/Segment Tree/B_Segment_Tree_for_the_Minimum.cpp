/**        بِسْمِ اللهِ الرَّحْمٰنِ الرَّحِيْمِ (In the name of God, the Most Gracious, the Most Merciful.)       */
/*
      Institution : Hajee Mohammad Danesh Science and Technology University,Dinajpur,Bangladesh.
      Name        : Ashikur Rahman Bhuyain (Asif)
      Email       : ashik.cse.hstu@gmail.com
*/

/*
   Problem link :https://codeforces.com/edu/course/2/lesson/4/1/practice/contest/273169/problem/B
   verdict :
*/

#include <bits/stdc++.h>
using namespace std;

struct segTree
{
    int size;
    vector<int> values;

    void init(int n)
    {
        size = 1;
        while (size < n)
            size *= 2;
        values.assign(2 * size, 0LL);
    }
    void build(vector<int> &a, int x, int lx, int rx)
    {
        if (rx - lx == 1)
        {
            if (lx < a.size())
            {
                values[x] = a[lx];
            }
            return;
        }
        int mid = (lx + rx) / 2;
        build(a, x * 2 + 1, lx, mid);
        build(a, x * 2 + 2, mid, rx);
        values[x] = min(values[2 * x + 1], values[2 * x + 2]);
    }
    void build(vector<int> &a)
    {
        build(a, 0, 0, size);
    }

    void set(int i, int v, int x, int lx, int rx)
    {
        if (rx - lx == 1)
        {
            values[x] = v;
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
        values[x] = min(values[2 * x + 1], values[2 * x + 2]);
    }
    void set(int i, int v)
    {
        set(i, v, 0, 0, size);
    }

    int Minimum(int l, int r, int x, int lx, int rx)
    {
        if (l >= rx || r <= lx)
            return INT_MAX;
        if (lx >= l && rx <= r)
            return values[x];
        int mid = (lx + rx) / 2;
        int s1 = Minimum(l, r, x * 2 + 1, lx, mid);
        int s2 = Minimum(l, r, x * 2 + 2, mid, rx);
        return min(s1, s2);
    }

    int Minimum(int l, int r)
    {
        return Minimum(l, r, 0, 0, size);
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
        int type;
        cin >> type;
        if (type == 1)
        {
            int ind, val;
            cin >> ind >> val;
            ST.set(ind, val);
        }
        else
        {
            int l, r;
            cin >> l >> r;
            cout << ST.Minimum(l, r) << endl;
        }
    }

    return 0;
}

/*"Success isn't permanent, failure isn't fatal,
                                     it's the courage to continue that counts"*/
