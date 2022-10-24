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

/** Mod - Int **/
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

/// vector
#define Lower_bound(vec, value) lower_bound(vec.begin(), vec.end(), value)
#define Upper_bound(vec, value) upper_bound(vec.begin(), vec.end(), value)
#define mnv(v) *min_element(all(v))
#define mxv(v) *max_element(all(v))

const int mod = 1e9 + 7;
const int maxn = 100005;
using Modint = modint<mod>;
struct mainMatrixrix
{
    vector<vector<int>> mainMatrix;
    int mainMatrixrixSize;
    mainMatrixrix(int k)
    {
        mainMatrixrixSize = k;
        mainMatrix.resize(k, vector<int>(k, 0));
    }
};

mainMatrixrix init(int k)
{
    mainMatrixrix res(k);
    for (int i = 0; i < k; i++)
        res.mainMatrix[i][i] = 1;
    return move(res);
}

mainMatrixrix mainMatrixrixMultiply(const mainMatrixrix &a, const mainMatrixrix &b)
{
    int mainMatrixrixSize = a.mainMatrixrixSize;
    mainMatrixrix res(mainMatrixrixSize);
    for (int i = 0; i < mainMatrixrixSize; i++)
        for (int j = 0; j < mainMatrixrixSize; j++)
            for (int k = 0; k < mainMatrixrixSize; k++)
            {
                res.mainMatrix[i][j] += a.mainMatrix[i][k] * 1LL * b.mainMatrix[k][j] % mod;
                if (res.mainMatrix[i][j] >= mod)
                    res.mainMatrix[i][j] -= mod;
            }
    return move(res);
}

long long mainMatrixrixMultiplyArray(const mainMatrixrix &m, int *a, int r)
{
    long long res = 0;
    int mainMatrixrixSize = m.mainMatrixrixSize;
    for (int i = 0; i < mainMatrixrixSize; i++)
    {
        res += m.mainMatrix[r][i] * 1LL * a[i] % mod;
        if (res >= mod)
            res -= mod;
    }
    return res;
}

mainMatrixrix mainMatrixrixPower(mainMatrixrix m, long long p)
{
    mainMatrixrix res = init(m.mainMatrixrixSize);
    while (p > 0)
    {
        if (p & 1)
            res = mainMatrixrixMultiply(res, m);
        m = mainMatrixrixMultiply(m, m);
        p >>= 1;
    }
    return res;
}

void add_val(mainMatrixrix &m, int i, int j, int v)
{
    m.mainMatrix[i][j] = v;
}

void solve(int kase)
{
    ll n, m;
    cin >> n >> m;
    n++;
    cout << "Case #" << kase << ": ";
    vector<Modint> dp(m, Modint(0));

    dp[0] = 1;
    for (int i = 1; i < m; i++)
    {
        for (int j = 0; j < i; j++)
        {
            dp[i] = dp[i] + dp[j];
        }
    }

    if (n < m)
    {
        cout << dp[n].value << endl;
        return;
    }
    // cout << "ever here?" << endl;

    mainMatrixrix mymainMatrix(m);
    for (int i = 0; i < m; i++)
        add_val(mymainMatrix, 0, i, 1);
    for (int i = 1; i < m; ++i)
        add_val(mymainMatrix, i, i - 1, 1);

    mainMatrixrix res = mainMatrixrixPower(mymainMatrix, n - m + 1);

    Modint ans = 0;
    for (int i = 0; i < m; i++)
    {
        ans += dp[m - i - 1] * res.mainMatrix[0][i];
    }

    cout << ans.value << endl;
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
