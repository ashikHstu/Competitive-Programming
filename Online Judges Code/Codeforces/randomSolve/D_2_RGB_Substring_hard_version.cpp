/**        بِسْمِ اللهِ الرَّحْمٰنِ الرَّحِيْمِ (In the name of God, the Most Gracious, the Most Merciful.)       */
/*
      Institution : Hajee Mohammad Danesh Science and Technology University,Dinajpur,Bangladesh.
      Name        : Ashikur Rahman Bhuyain (Asif)
      Email       : ashik.cse.hstu@gmail.com
*/

#include <bits/stdc++.h>
using namespace std;
#define ll long long int

#define MinHeap priority_queue<int, vector<int>, greater<int>>
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
#define NUMLEN(Num) to_string(Num).size()

#define POSL(x, v) (lower_bound(x.begin(), x.end(), v) - x.begin())
#define POSU(x, v) (upper_bound(x.begin(), x.end(), v) - x.begin())
#define min3(a, b, c) min(a, min(b, c))
#define min4(a, b, c, d) min(a, min(b, min(c, d)))
#define max3(a, b, c) max(a, max(b, c))
#define max4(a, b, c, d) max(a, max(b, max(c, d)))
#define ABS(x) ((x) < 0 ? -(x) : (x))
#define pb push_back
#define nl printf("\n")

/// vector
#define Lower_bound(vec, value) lower_bound(vec.begin(), vec.end(), value)
#define Upper_bound(vec, value) upper_bound(vec.begin(), vec.end(), value)
#define mnv(v) *min_element(all(v))
#define mxv(v) *max_element(all(v))

const int mod = 1e9 + 7;
const int maxn = 100005;
int n, k;

string findKS(int pos, int k)
{
    string pat = "RGB";
    string res;

    for (int i = 0; i < k; i++)
    {
        res.pb(pat[pos]);
        pos++;
        pos %= 3;
    }
    return res;
}

void solve()
{
    cin >> n >> k;
    string st;
    cin >> st;

    string ks, ks2, ks3;
    ks = findKS(0, k);
    ks2 = findKS(1, k);
    ks3 = findKS(2, k);
    int mv[3][n + 1];
    mem(mv, 0);

    int res = n;
    for (int i = 0; i + k <= n; i++)
    {
        if (i != 0)
        {
            int pls = 0;
            if (st[i - 1] == 'B')
                pls--;
            int md = (k - 1) % 3;
            if (st[i+k-1]==ks[k-1])
                pls++;

            mv[0][i] = mv[2][i - 1] - pls;
            res = min(res, mv[0][i]);

            pls = 0;
            if (st[i - 1] == 'R')
                pls--;
            md = (k - 1) % 3;
           if (st[i+k-1]==ks2[k-1])
                pls++;

            mv[1][i] = mv[0][i - 1] - pls;
            res = min(res, mv[1][i]);

           pls = 0;
            if (st[i - 1] == 'G')
                pls--;
            md = (k - 1) % 3;
             if (st[i+k-1]==ks3[k-1])
                pls++;

            mv[2][i] = mv[1][i - 1] - pls;
            res = min(res, mv[2][i]);

            continue;
        }

        for (int j = i; j < i + k; j++)
        {
            if (st[j] != ks[j - i])
                mv[0][i]++;
        }
        //   cout<<"mv : "<<mv<<endl;
        res = min(res, mv[0][i]);

        for (int j = i; j < i + k; j++)
        {
            if (st[j] != ks2[j - i])
                mv[1][i]++;
        }

        res = min(res, mv[1][i]);

        for (int j = i; j < i + k; j++)
        {
            //  cout<<"here at : "<<i<<endl;
            if (st[j] != ks3[j - i])
                mv[2][i]++;
        }
        res = min(res, mv[2][i]);
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

/*"Success isn't permanent, failure isn't fatal,
                                     it's the courage to continue that counts"*/
