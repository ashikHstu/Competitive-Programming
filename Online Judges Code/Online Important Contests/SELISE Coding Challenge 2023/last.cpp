#include <bits/stdc++.h>
using namespace std;

const int N = 500005, M = 1000005;
int n, q, a[N], cnt[M];
int blk[N], st[N], ed[N], blen, bnum;
vector<int> buckets[N];

// Binary search for the kth minimum excluded value in the range [L, R]
int kth_excluded(int L, int R, int k)
{
    int l = 0, r = M - 1;
    while (l < r)
    {
        int mid = (l + r) / 2;
        int pos = upper_bound(buckets[R].begin(), buckets[R].end(), mid) - buckets[R].begin();
        if (L > 0)
            pos -= upper_bound(buckets[L - 1].begin(), buckets[L - 1].end(), mid) - buckets[L - 1].begin();
        if (pos < k)
            l = mid + 1;
        else
            r = mid;
    }
    return l;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    cin >> n;
    for (int i = 1; i <= n; i++)
        cin >> a[i];
    blen = sqrt(n * log2(n));
    bnum = (n + blen - 1) / blen;
    for (int i = 1; i <= n; i++)
    {
        blk[i] = (i - 1) / blen + 1;
        if (i % blen == 1)
            st[blk[i]] = i;
        if (i % blen == 0 || i == n)
            ed[blk[i]] = i;
        buckets[blk[i]].push_back(a[i]);
        cnt[a[i]]++;
    }
    cin >> q;
    while (q--)
    {
        int l, r, k;
        cin >> l >> r >> k;
        int L = blk[l], R = blk[r];
        if (L == R)
        {
            vector<int> b;
            for (int i = l; i <= r; i++)
                b.push_back(a[i]);
            sort(b.begin(), b.end());
            int cnt = 0;
            for (int i = 0; i < b.size(); i++)
            {
                if (b[i] - cnt > k)
                    return cout << cnt + k << "\n", 0;
                cnt += b[i] - cnt;
            }
            cout << cnt + k << "\n";
        }
        else
        {
            int ans = 0;
            for (int i = L + 1; i <= R - 1; i++)
                ans += ed[i] - st[i] + 1 - cnt[a[st[i]] - 1];
            ans += ed[L] - l + 1 - cnt[a[l] - 1];
            ans += r - st[R] + 1 - cnt[a[r] - 1];
            cout << kth_excluded(L, R, k) + ans << "\n";
        }
    }
    return 0;
}
