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

void solve(int kase)
{
    int n;
    cin >> n;
    int ar[n + 2][n + 2];
    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= n; j++)
        {
            cin >> ar[i][j];
        }
    }

    int res = 0;

    for (int r = 1; r <= n; r++)
    {
        for (int c = 1; c <= n; c++)
        {
            int possible[11] = {0};
            int t = 0;
            for (int i = r; i <= n && i <= i + 9; i++)
            {
                for (int j = c; j <= c; j++)
                {
                    int cv = ar[i][j];
                    possible[cv]++;
                    if (possible[cv] == 1)
                        t++;
                }
            }
            if (t == 10)
                res++;
            mem(possible, 0);
            t = 0;

            for (int i = r; i <= r; i++)
            {
                for (int j = c; j <= min(c + 9, n); j++)
                {
                    int cv = ar[i][j];
                    possible[cv]++;
                    if (possible[cv] == 1)
                        t++;
                }
            }
            if (t == 10)
                res++;

            mem(possible, 0);
            t = 0;

            for (int i = r; i <= min(n,r+1); i++)
            {
                for (int j = c; j <= min(c +4, n); j++)
                {
                    int cv = ar[i][j];
                    possible[cv]++;
                    if (possible[cv] == 1)
                        t++;
                }
            }

          //  cout<<"cr : "<<r<<" , cc : "<<c<<endl;
           // cout<<"cur t : "<<t<<endl;
            if (t == 10)
                res++;


                 mem(possible, 0);
            t = 0;

            for (int i = r; i <= min(n,r+4); i++)
            {
                for (int j = c; j <= min(c +1, n); j++)
                {
                    int cv = ar[i][j];
                    possible[cv]++;
                    if (possible[cv] == 1)
                        t++;
                }
            }
            if (t == 10)
                res++;
        }
    }

   /// cout<<res<<endl;
   printf("Case %d: %d\n",kase,res);
}

int main()
{
    int tc = 1;
    cin >> tc;
    for (int i = 1; i <= tc; i++)
    {
        solve(i);
    }

    return 0;
}

/*"Success isn't permanent, failure isn't fatal,
                                     it's the courage to continue that counts"*/
