#include <bits/stdc++.h>
using namespace std;

struct manacher
{
    vector<int> p;
    void run_manacher(string st)
    {
        int n = st.length();
        p.assign(n, 1);
        int l = 1, r = 1;
        for (int i = 1; i < n; i++)
        {
            p[i] = max(0, min(r - i, p[l + r - 1]));

            while (i + p[i] < n && i - p[i] >= 0 && st[i + p[i]] == st[i - p[i]])
            {
                p[i]++;
            }
            if (i + p[i] > r)
            {
                l = i - p[i];
                r = i + p[i];
            }
        }

        for (auto v : p)
        {
            cout << v << " ";
        }
        cout << endl;
    }

    void build(string st)
    {
        string t;
        for (auto ch : st)
        {
            t += string("#") + ch;
        }
        run_manacher(t + "#");
    }

    int getLongest(int cen, bool odd)
    {
        int pos = 2 * cen + 1 + (!odd);
        return p[pos] - 1;
    }

    bool checkPalindrome(int l, int r)
    {
        if ((r - l + 1) <= getLongest((l + r) / 2, l % 2 == r % 2))
        {
            return 1;
        }
        else
            return 0;
    }

} m;

void solve(int kase)
{
    string st = "babbabbabc";
    // cin>>st;
    cout << st << endl;
    m.build(st);
}

int main()
{
    int tc = 1;
    // cin>>tc;
    for (int i = 1; i <= tc; i++)
    {
        solve(i);
    }

    return 0;
}