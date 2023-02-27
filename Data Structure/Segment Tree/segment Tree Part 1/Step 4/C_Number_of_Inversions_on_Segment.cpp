/**        بِسْمِ اللهِ الرَّحْمٰنِ الرَّحِيْمِ (In the name of Allah, the Most Gracious, the Most Merciful.)       */
/*
      Institution : Hajee Mohammad Danesh Science and Technology University,Dinajpur,Bangladesh.
      Name        : Ashikur Rahman Bhuyain (Asif)
      Email       : ashik.cse.hstu@gmail.com
*/

/*
   Problem link : https://codeforces.com/edu/course/2/lesson/4/4/practice/contest/274684/problem/C
   verdict :  Accepted
*/
#include <bits/stdc++.h>
using namespace std;
#define ll long long
struct item
{
    ll cnt;
    int freq[41];
};
// typedef long long item;
struct segTree
{
    int size;
    vector<item> values;
    item NEUTRAL_ELEMENT = Single(41);
    item Single(int vv)
    {
        item res;
        res.cnt = 0;
        memset(res.freq, 0, sizeof(res.freq));
        res.freq[vv]++;
        return res;
    }
    item Merge(item a, item b)
    {
        item res;
        memset(res.freq, 0, sizeof(res.freq));
        ll allcnt = a.cnt + b.cnt;
        for (int i = 0; i < 41; i++)
        {

            res.freq[i] = a.freq[i] + b.freq[i];
        }
        /*
            if any element from a is greater than any element from b, it will also added
            to the result (by multiplying the occurences)
        */
        for (int i = 0; i < 41; i++)
        {

            for (int j = i + 1; j < 41; j++)
            {
                allcnt += (a.freq[j] * b.freq[i]);
            }
        }

        res.cnt = allcnt;
        return res;
    }
    // O(log(n))
    void init(int n)
    {
        //        NEUTRAL_ELEMENT.cnt = 0;
        //        memset(NEUTRAL_ELEMENT.freq, 0, sizeof(NEUTRAL_ELEMENT.freq));
        size = 1;
        while (size < n)
            size *= 2;
        values.resize(2 * size, NEUTRAL_ELEMENT);
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
};

int32_t main()
{
    int n, q, m;
    cin >> n >> q;
    // cout << "The value of n , m : " << n << ", " << q << endl;
    m = q;
    segTree ST;
    ST.init(n + 2);

    vector<int> ar(n);
    //  cout<<"the value of q : "<<q<<endl;
    for (int i = 0; i < n; i++)
        cin >> ar[i];
    ST.build(ar);

    while (m--)
    {
        int type;
        cin >> type;
        if (type == 1)
        {
            int l, r;
            cin >> l >> r;
            l--;
            item res = ST.calc(l, r);
            cout << res.cnt << endl;
        }
        else
        {
            int ind, v;
            cin >> ind >> v;
            ind--;
            ST.set(ind, v);
        }
    }

    return 0;
}

/*"Success isn't permanent, failure isn't fatal,
                                     it's the courage to continue that counts"*/
