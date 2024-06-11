#include <bits/stdc++.h>
using namespace std;
#define doshomik(x) cout << fixed << setprecision(x)
#define pi acos(-1.0)
#define mem(a, b) memset(a, b, sizeof(a))
#define all(a) a.begin(), a.end()
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
#define isOn(S, j) (S & (1 << j))
#define onBit(S, j) (S |= (1 << j))
#define clearBit(S, j) (S &= ~(1 << j)) // turn off j'th bit
#define toggleBit(S, j) (S ^= (1 << j))
#define lowBit(S) (S & (-S)) // if S==20, it will give 4 (16+4==20)
#define isPowerOfTwo(S) (!(S & (S - 1)))

#define blz(a) __builtin_clz(a)              // Number of leading zero
#define btz(a) __builtin_ctz(a)              // number of trailing zero
#define totalSetBit(a) __builtin_popcount(a) // number of set bit
#define parity(a) __builtin_parity(a)        // if odd number of set bit > 1, if even > 0

class helper
{
private:
    int n;

public:
    void setN(int n)
    {
        this->n = n;
    }
    void getN()
    {
        return this->n;
    }
}

void
solve()
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