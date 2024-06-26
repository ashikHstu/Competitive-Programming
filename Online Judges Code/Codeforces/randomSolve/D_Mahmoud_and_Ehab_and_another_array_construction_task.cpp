/**        بِسْمِ اللهِ الرَّحْمٰنِ الرَّحِيْمِ (In the name of God, the Most Gracious, the Most Merciful.)       */
/*
      Institution : Hajee Mohammad Danesh Science and Technology University,Dinajpur,Bangladesh.
      Name        : Ashikur Rahman Bhuyain (Asif)
      Email       : asifurr087@gmail.com
*/

#include <bits/stdc++.h>
using namespace std;

/*
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
using namespace __gnu_pbds;



typedef tree<
int,
null_type,
less_equal<int>,
rb_tree_tag,
tree_order_statistics_node_update> ordered_set;

(will make comment from here)
 ordered_set X;

  *X.find_by_order(k) --> The first returns an iterator to the k-th largest element (counting from zero)
    X.order_of_key(-5)  --> the number of items in a set that are strictly smaller than our item(here -5)
         (find_by_order return pointer
            order_of_key return integer)

*/

#define AT find_by_order
#define POS order_of_key
#define ERASE(ache, v) ache.erase(ache.AT(ache.POS(v)))

#define int long long int

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

/*  ..................... Bit Manipulation...................................*/

#define isOn(S, j) (S & (1 << j))
#define setBit(S, j) (S |= (1 << j))
#define clearBit(S, j) (S &= ~(1 << j)) // turn off j'th bit
#define toggleBit(S, j) (S ^= (1 << j))
#define lowBit(S) (S & (-S))
#define setAll(S, n) (S = (1 << n) - 1)

#define modulo(S, N) ((S) & (N - 1)) // returns S % N, where N is a power of 2
#define isPowerOfTwo(S) (!(S & (S - 1)))
#define nearestPowerOfTwo(S) ((int)pow(2.0, (int)((log((double)S) / log(2.0)) + 0.5)))
#define turnOffLastBit(S) ((S) & (S - 1)) // turn off the last on bit
#define turnOnLastZero(S) ((S) | (S + 1))
#define turnOffLastConsecutiveBits(S) ((S) & (S + 1))
#define turnOnLastConsecutiveZeroes(S) ((S) | (S - 1))

#define blz(a) __builtin_clz(a)              // Number of leading zero
#define btz(a) __builtin_ctz(a)              // number of trailing zero
#define totalSetBit(a) __builtin_popcount(a) // number of set bit
#define parity(a) __builtin_parity(a)        // if odd number of set bit > 1, if even > 0

/// Finding or adding part
#define BinaryToGray(k) (k ^ (k >> 1))

void printSet(int vS)
{ // in binary representation
    printf("S = %2d = ", vS);
    stack<int> st;
    while (vS)
        st.push(vS % 2), vS /= 2;
    while (!st.empty()) // to reverse the print order
        printf("%d", st.top()), st.pop();
    printf("\n");
}

/*............................ End of Bit Manipulation Part .................... */

/// vector
#define Lower_bound(vec, value) lower_bound(vec.begin(), vec.end(), value)
#define Upper_bound(vec, value) upper_bound(vec.begin(), vec.end(), value)
#define mnv(v) *min_element(all(v))
#define mxv(v) *max_element(all(v))

/// File In
#define READ(f) freopen(f, "r", stdin)
#define WRITE(f) freopen(f, "w", stdout)

const int mod = 1e9 + 7;


const int N = 1e7 + 5;
int lp[N];
vector<int> primes;

void sieveN()
{
    for (int i = 2; i <= N; i++)
    {
        if (lp[i] == 0)
        {

            lp[i] = i;
            primes.push_back(i);
        }

        for (int j = 0; j < (int)primes.size() && primes[j] <= lp[i] && i * primes[j] <= N; j++)
        {
            lp[i * primes[j]] = primes[j];
        }
    }
}

void solve()
{
    int n;
    cin >> n;
    int ar[n + 2];
    for (int i = 0; i < n; i++)
    {
        cin >> ar[i];
    }

    map<int, int> mp;
    int res[n + 2];
    int ind = -1;
    int corrupted = 0;
    int firstTime = -1;
    int vForFirstTime = -1;
    int nextE=0;
    for (int i = 0; i < n; i++)
    {

        if (i > firstTime && firstTime!=-1)
        {

            while(mp[primes[nextE]]!=0)nextE++;

            res[i] = primes[nextE];
            mp[primes[nextE]]++;
            nextE++;

            continue;
        }
        int cur = ar[i];
        vector<int> fact;

        for (int j = 0; primes[j] <= cur * cur && cur > 1; j++)
        {

            if (cur % primes[j] == 0)
            {
                fact.push_back(primes[j]);

                while (cur % primes[j] == 0 && cur>1)
                {
                    cur /= primes[j];
                }
                if(cur>1)fact.push_back(cur);
            }
        }

           // cout<<"fact of "<<ar[i]<<" : ";
        for (int j = 0; j < fact.size(); j++)
        {
           // cout<<fact[j]<<" ";
            if (mp[fact[j]] != 0)
            {
                if (firstTime == -1)
                    firstTime = i;
                   // cout<<"ever?"<<endl;
                corrupted = 1;
                break;
            }
        }

        if (corrupted)
        {
           // cout << "curropted?";
            ar[i]++;
            i--;
            corrupted=0;
            continue;
        }

        for (int j = 0; j < fact.size(); j++)
        {
            mp[fact[j]]++;
        }

        res[i] = ar[i];
        ind = i;
    }



    for (int i = 0; i < n; i++)
        cout << res[i] << " ";
    cout << endl;
}

int32_t main()
{
    sieveN();
    int tc = 1;
    // cin>>tc;
    for (int i = 1; i <= tc; i++)
    {
        solve();
    }

    return 0;
}

/*"Success isn't permanent, failure isn't fatal,
                                     it's the courage to continue that counts"*/
