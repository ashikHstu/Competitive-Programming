#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define int long long
#define FasterIO             \
    ios::sync_with_stdio(0); \
    cin.tie(0);              \
    cout.tie(0)
#define doshomik(x) cout << fixed << setprecision(x)
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

#define POSL(x, v) (lower_bound(x.begin(), x.end(), v) - x.begin())
#define POSU(x, v) (upper_bound(x.begin(), x.end(), v) - x.begin())
#define min3(a, b, c) min(a, min(b, c))
#define min4(a, b, c, d) min(a, min(b, min(c, d)))
#define max3(a, b, c) max(a, max(b, c))
#define max4(a, b, c, d) max(a, max(b, max(c, d)))
#define ABS(x) ((x) < 0 ? -(x) : (x))
#define pb push_back


int mxSubArraySum(vector<int> &ar) {
    int curr = ar[0];
    int best = ar[0];

    for (int i = 1; i < ar.size(); i++) {
        curr = max(ar[i], curr + ar[i]); 
        best = max(best, curr);
    }

    return best;
}


void solve()
{
    int n,k;
    cin>>n>>k;
    vector<int>ar(n),br(n);
    for(int i=0;i<n;i++)
    {
        cin>>ar[i];
    }
    for(int i=0;i<n;i++)
    {
        cin>>br[i];
    }

    if(k%2==0)
    {
        cout<<mxSubArraySum(ar)<<endl;
        return;
    }
 vector<int> dp0(n), dp1(n);

    dp0[0] = ar[0];
    dp1[0] = ar[0] + br[0];

    long long res = max(dp0[0], dp1[0]);

    for(int i = 1; i < n; i++) {
        dp0[i] = max(dp0[i-1] + ar[i], ar[i]);

        dp1[i] = dp1[i-1] + ar[i]; 
        dp1[i] = max(dp1[i], dp0[i-1] + ar[i] + br[i]); 
        dp1[i] = max(dp1[i], ar[i] + br[i]); 

        res = max({res, dp0[i], dp1[i]});
    }
    cout<<res<<endl;


}

int32_t main()
{
    FasterIO;
    int tc = 1;
    cin >> tc;
    for (int i = 1; i <= tc; i++)
    {
        solve();
    }
    return 0;
}
