/**        بِسْمِ اللهِ الرَّحْمٰنِ الرَّحِيْمِ (In the name of God, the Most Gracious, the Most Merciful.)       */
/*
      Institution : Hajee Mohammad Danesh Science and Technology University,Dinajpur,Bangladesh.
      Name        : Ashikur Rahman Bhuyain (Asif)
      Email       : ashik.cse.hstu@gmail.com
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

#define limit 100005
int prime_chek[limit + 5], primes[limit + 5], total_primes;
void sieve_and_store_primes()
{
    int sqn = sqrt(limit) + 1;
    prime_chek[0] = prime_chek[1] = 1;
    primes[total_primes] = 2;
    total_primes++;
    for (int i = 3; i <= sqn; i += 2)
    {
        if (prime_chek[i] == 0)
        {
            primes[total_primes] = i;
            total_primes++;
            for (int j = i * i; j <= limit; j += i + i)
            {
                prime_chek[j] = 1;
            }
        }
    }
    if (sqn % 2 == 0)
    {
        sqn++;
    }
    for (int i = sqn; i < limit; i += 2)
    {
        if (prime_chek[i] == 0)
        {
            primes[total_primes] = i;
            total_primes++;
        }
    }
}

void solve()
{
    ll n;
    cin >> n;
    int ar[n + 3];

    map<ll, ll> mp;
    bool ok = false;
    for (int i = 0; i < n; i++)
    {
        cin >> ar[i];
        int sq = sqrt(ar[i] + 1);
        for (int j = 0; j < total_primes && primes[j] <= sq && !ok; j++)
        {
            if (ar[i] % primes[j] == 0)
            {
                mp[primes[j]]++;
                if (mp[primes[j]] > 1)
                    ok = true;
                while (ar[i] % primes[j] == 0)
                    ar[i] /= primes[j];
            }
        }
        if (ar[i] > 1)
            mp[ar[i]]++;
        if (mp[ar[i]] > 1)
            ok = true;
    }

    if (ok)
        cout << "YES\n";
    else
        cout << "NO\n";
}

int main()
{
    sieve_and_store_primes();
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
