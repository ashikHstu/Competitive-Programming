/**        بِسْمِ اللهِ الرَّحْمٰنِ الرَّحِيْمِ (In the name of God, the Most Gracious, the Most Merciful.)       */
/*
      Institution : Hajee Mohammad Danesh Science and Technology University,Dinajpur,Bangladesh.
      Name        : Ashikur Rahman Bhuyain (Asif)
      Email       : ashik.cse.hstu@gmail.com
*/

/*
   Problem link :
   verdict :
*/

#include <bits/stdc++.h>
using namespace std;

#define ll long long int

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

#define POSL(x, v) (lower_bound(x.begin(), x.end(), v) - x.begin())
#define POSU(x, v) (upper_bound(x.begin(), x.end(), v) - x.begin())
#define min3(a, b, c) min(a, min(b, c))
#define min4(a, b, c, d) min(a, min(b, min(c, d)))
#define max3(a, b, c) max(a, max(b, c))
#define max4(a, b, c, d) max(a, max(b, max(c, d)))
#define ABS(x) ((x) < 0 ? -(x) : (x))
#define pb push_back
#define nl printf("\n")

/** STL Functions     */
// pbds
#define fbo(ind) find_by_order(ind)
#define ook(val) order_of_key(val)

/**      Extra storing              */
#define UNIQUE(v) (v).erase(unique(all(v)), (v).end())

/**        End of Ex Storing                */

/**------- Char Chk----------*/
inline bool isLower(char ch) { return (ch >= 'a' && ch <= 'z'); }
inline bool isUpper(char ch) { return (ch >= 'A' && ch <= 'Z'); }
inline bool isDigit(char ch) { return (ch >= '0' && ch <= '9'); }
inline bool isVowel(char ch)
{
    ch = tolower(ch);
    return (ch == 'a' || ch == 'e' || ch == 'i' || ch == 'o' || ch == 'u');
}
/*----------------------Graph Moves----------------*/
// const int fx[]={+1,-1,+0,+0};
// const int fy[]={+0,+0,+1,-1};
// const int fx[]={+0,+0,+1,-1,-1,+1,-1,+1};   // Kings Move
// const int fy[]={-1,+1,+0,+0,+1,+1,-1,-1};  // Kings Move
// const int fx[]={-2, -2, -1, -1,  1,  1,  2,  2};  // Knights Move
// const int fy[]={-1,  1, -2,  2, -2,  2, -1,  1}; // Knights Move
/*------------------------------------------------*/

int primes[1000006];
vector<int> allPrimes;
void sieve()
{
    int n = 1000004;
    int sqn = sqrt(n + 1);
    primes[1] = 1;
    for (int i = 3; i <= sqn; i += 2)
    {
        if (primes[i] == 0)
        {
            for (int j = i * i; j <= n; j += (i + i))
            {
                primes[j] = 1;
            }
        }
    }
    allPrimes.push_back(2);
    for (int i = 3; i <= 1000003; i += 2)
    {
        if (primes[i] == 0)
            allPrimes.push_back(i);
    }
}

ll powmod(ll base, ll pow, ll mod)
{
    base %= mod;
    ll result = 1;
    while (pow > 0)
    {
        if (pow & 1)
            result = (result * base) % mod;
        base = (base * base) % mod;
        pow >>= 1;
    }
    return result % mod;
}

void solve()
{
    ll n;
    cin >> n;
    ll mod = 1000000007;
    ll ar[n + 2];
    map<ll, ll> mp;
    int totalOne = 0;
    for (int i = 0; i < n; i++)
    {
        cin >> ar[i];
        if (ar[i] == 1)
            totalOne++;

        ll val = ar[i];
        for (int j = 0; allPrimes[j] * allPrimes[j] <= val; j++)
        {
            ll ct = 0;
            while (val % allPrimes[j] == 0)
            {
                ct++;
                val /= allPrimes[j];
            }
            if (ct > 0)
                mp[allPrimes[j]] = mp[allPrimes[j]] + ct;
        }
        if (val > 1)
            mp[val] = mp[val] + 1;
    }

    vector<pair<ll, ll>> vecP;
    for (auto it = mp.begin(); it != mp.end(); it++)
    {
        ll mpv1 = it->first;
        ll mpv2 = it->second;
        vecP.push_back({mpv1, mpv2});
    }

    sort(all(vecP));

    // cout << "Printing the primefact vector : " << vecP.size() << endl;
    // for (int i = 0; i < vecP.size(); i++)
    // {
    //     cout << vecP[i].first << " " << vecP[i].second << endl;
    // }

    ll totalPrime = vecP.size();
    ll badDiteHobe = n - totalPrime;
    badDiteHobe -= totalOne;
    if (badDiteHobe < 0)
        badDiteHobe = 0;

    ll mainRes = 1;
    for (int i = 0; i < vecP.size(); i++)
    {
        ll ache = vecP[i].second;
        ll badDibo = min(badDiteHobe, ache - 1);
        badDiteHobe -= badDibo;
        ache -= badDibo;
        ll tr = powmod(vecP[i].first, ache, mod);
        mainRes *= tr;
        mainRes %= mod;
    }

    cout << mainRes % mod << endl;
    return;
}

int main()
{
    sieve();
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
