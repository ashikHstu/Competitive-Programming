#include <bits/stdc++.h>
using namespace std;
#define ll long long int
#define pb push_back

#define FasterIO             \
    ios::sync_with_stdio(0); \
    cin.tie(0);              \
    cout.tie(0)
#define TIME clock() * 1.0 / CLOCKS_PER_SEC
#define pi acos(-1.0)
#define mem(a, b) memset(a, b, sizeof(a))
#define all(a) a.begin(), a.end()
#define Sort(x) sort(x.begin(), x.end())
#define Reverse(x) reverse(x.begin(), x.end())
#define SortA(ar, s) sort(ar, ar + s)
#define SortD(ar, s) sort(ar, ar + s, greater<int>())
#define gcd(a, b) __gcd(a, b)
#define lcm(a, b) (a * (b / gcd(a, b)))
#define sq(x) (x) * (x)
#define CEIL(a, b) ((a / b) + ((a % b) != 0))

void solve()
{
    int n, k;
    cin >> n >> k;
    string st;
    cin >> st;

    int firstPos = -1, lastPos = -1;
    int totalOne = 0;

    for (int i = 0; i < n; i++)
    {
        if (st[i] == '1')
        {
            totalOne++;
        }
    }

    if (totalOne == 0)
    {
        cout << "0\n";
        return;
    }

    for (int i = 0; i < n; i++)
    {
        if (st[i] == '1')
        {
            firstPos = i;
            break;
        }
    }

    for (int i = n - 1; i >= 0; i--)
    {
        if (st[i] == '1')
        {
            lastPos = i;
            break;
        }
    }

    if (firstPos == lastPos)
    {

        if (n == 1)
        {
            cout << "1\n";
            return;
        }
        if (n - 1 - lastPos <= k)
        {
            cout << "1\n";
            return;
        }
        else if (firstPos <= k)
        {
            cout << "10\n"
                 << endl;
            return;
        }
        else
        {
            cout << "11\n";
            return;
        }
    }

    int res = totalOne * 11;
    if (n - lastPos - 1 <= k)
    {
        res -= 10;
        k -= (n - lastPos - 1);
    }

    if (firstPos <= k)
    {
        res -= 1;
        k -= firstPos;
    }

    cout << res << endl;
}

int main()
{
    int tc = 1;
    cin >> tc;
    for (int i = 1; i <= tc; i++)
    {
        solve();
    }

    return 0;
}
