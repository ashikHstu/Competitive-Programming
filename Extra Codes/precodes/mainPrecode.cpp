/**        بِسْمِ اللهِ الرَّحْمٰنِ الرَّحِيْمِ (In the name of Allah, the Most Gracious, the Most Merciful.)       */
/*
      Institution : Hajee Mohammad Danesh Science and Technology University,Dinajpur,Bangladesh.
      Name        : Ashikur Rahman Bhuyain (Asif)
      Email       : ashik.cse.hstu@gmail.com
*/
#pragma GCC optimize("O3,unroll-loops")
#pragma GCC target("avx2,bmi,bmi2,lzcnt,popcnt")
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

// #define ERASE(ache,v) ache.erase(ache.AT(ache.POS(v)))
#define AT find_by_order                              // return iterator of index
#define POS order_of_key                              // return position of value
#define ERS(st, x) (st).erase((st).AT((st).POS((x)))) // Erase x value
template <class T>
struct pbds_cmp
{
  bool operator()(const T &a, const T &b) const { return a < b; }
};

#define ll long long int

#define FasterIO           \
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
// #define priority_queue <int, vector<int>, greater<int>> minHeap

/** STL Functions     */
// pbds
#define fbo(ind) find_by_order(ind)
#define ook(val) order_of_key(val)

/**      Extra storing              */
#define UNIQUE(v) (v).erase(unique(all(v)), (v).end())

/**        End of Ex Storing                */

/**------- Char Chk, other functions----------*/
inline bool isLower(char ch) { return (ch >= 'a' && ch <= 'z'); }
inline bool isUpper(char ch) { return (ch >= 'A' && ch <= 'Z'); }
inline bool isDigit(char ch) { return (ch >= '0' && ch <= '9'); }
inline bool isVowel(char ch)
{
  ch = tolower(ch);
  return (ch == 'a' || ch == 'e' || ch == 'i' || ch == 'o' || ch == 'u');
}
string to_upper(string a)
{
  for (int i = 0; i < (int)a.size(); ++i)
    if (a[i] >= 'a' && a[i] <= 'z')
      a[i] -= 'a' - 'A';
  return a;
}
string to_lower(string a)
{
  for (int i = 0; i < (int)a.size(); ++i)
    if (a[i] >= 'A' && a[i] <= 'Z')
      a[i] += 'a' - 'A';
  return a;
}
bool prime(ll a)
{
  if (a == 1)
    return 0;
  for (int i = 2; i <= round(sqrt(a)); ++i)
    if (a % i == 0)
      return 0;
  return 1;
}

/* PRINTS */
template <class T>
void print_v(vector<T> &v)
{
  cout << "{";
  for (auto x : v)
    cout << x << ",";
  cout << "\b}";
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
#define onBit(S, j) (S |= (1 << j))
#define clearBit(S, j) (S &= ~(1 << j)) // turn off j'th bit
#define toggleBit(S, j) (S ^= (1 << j))
#define lowBit(S) (S & (-S)) // if S==20, it will give 4 (16+4==20)
#define setAll(S, n) (S = (1 << n) - 1)
long long int highBit(long long v)
{
  if (v == 0)
    return 0;
  long long ct = 1;
  while (ct * 2 <= v)
  {
    ct *= 2;
  }
  return ct; // if v==20, it will give 16 (16+4==20)
}

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

/// vector and STL
#define Lower_bound(vec, value) lower_bound(vec.begin(), vec.end(), value)
#define Upper_bound(vec, value) upper_bound(vec.begin(), vec.end(), value)
#define mnv(v) *min_element(all(v))
#define mxv(v) *max_element(all(v))
#define minHeap priority_queue<int, vector<int>, greater<int>>

/// File In
#define READ(f) freopen(f, "r", stdin)
#define WRITE(f) freopen(f, "w", stdout)

const int mod = 1e9 + 7;

inline ll modMul(ll a, ll b, ll mod)
{
  ll ans = 0;
  a = a % mod;
  while (b > 0)
  {
    if (b % 2)
      ans = (ans % mod + a % mod) % mod;
    a = (a % mod * 2 % mod) % mod;
    b /= 2;
  }
  return ans % mod;
}

inline ll bigMod(ll a, ll b, ll mod)
{
  if (b == 0)
    return 1 % mod;
  ll ans = 1;
  while (b)
  {
    if (b & 1)
      ans = (1ll * ans * a) % mod;
    a = (1ll * a * a) % mod;
    b /= 2;
  }
  return ans;
}
/**     Condition for Sorting pair    */
bool pairC(const pair<int, int> &a,
           const pair<int, int> &b)
{
  if (a.first == b.first)
    return a.second > b.second;
  return (a.first < b.first);
}

/// MOD INT LIBRARY

const int md = 1e9 + 7;
const int mx = 1e6 + 5;
template <const int32_t MOD>
struct modint
{
#define IM inline modint<MOD>
#define TPT template <typename T>

  int32_t value;
  modint() = default;
  TPT modint(T value_) : value(value_ % MOD) {}
  IM operator+(modint<MOD> other) const
  {
    int32_t c = this->value + other.value;
    return modint<MOD>(c >= MOD ? c - MOD : c);
  }
  IM operator-(modint<MOD> other) const
  {
    int32_t c = this->value - other.value;
    return modint<MOD>(c < 0 ? c + MOD : c);
  }
  IM operator*(modint<MOD> other) const
  {
    int32_t c = (int64_t)this->value * other.value % MOD;
    return modint<MOD>(c < 0 ? c + MOD : c);
  }
  IM &operator+=(modint<MOD> other)
  {
    this->value += other.value;
    if (this->value >= MOD)
      this->value -= MOD;
    return *this;
  }
  IM &operator-=(modint<MOD> other)
  {
    this->value -= other.value;
    if (this->value < 0)
      this->value += MOD;
    return *this;
  }
  IM &operator*=(modint<MOD> other)
  {
    this->value = (int64_t)this->value * other.value % MOD;
    if (this->value < 0)
      this->value += MOD;
    return *this;
  }
  IM operator-() const { return modint<MOD>(this->value ? MOD - this->value : 0); }
  modint<MOD> pow(uint64_t k) const
  {
    modint<MOD> x = *this, y = 1;
    for (; k; k >>= 1)
    {
      if (k & 1)
        y *= x;
      x *= x;
    }
    return y;
  }
  modint<MOD> inv() const { return pow(MOD - 2); } // MOD must be a prime
  IM operator/(modint<MOD> other) const { return *this * other.inv(); }
  IM operator/=(modint<MOD> other) { return *this *= other.inv(); }
  inline bool operator==(modint<MOD> other) const { return value == other.value; }
  inline bool operator!=(modint<MOD> other) const { return value != other.value; }
  inline bool operator<(modint<MOD> other) const { return value < other.value; }
  inline bool operator>(modint<MOD> other) const { return value > other.value; }

  TPT IM &operator+=(T ot) { return *this += modint<MOD>(ot); }
  TPT IM &operator-=(T ot) { return *this -= modint<MOD>(ot); }
  TPT IM &operator*=(T ot) { return *this *= modint<MOD>(ot); }
  TPT IM &operator/=(T ot) { return *this *= modint<MOD>(ot).inv(); }

  TPT IM operator+(T ot) const { return *this + modint<MOD>(ot); }
  TPT IM operator-(T ot) const { return *this - modint<MOD>(ot); }
  TPT IM operator*(T ot) const { return *this * modint<MOD>(ot); }
  TPT IM operator/(T ot) const { return *this / modint<MOD>(ot); }
};
using mint = modint<md>;

void solve()
{
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
