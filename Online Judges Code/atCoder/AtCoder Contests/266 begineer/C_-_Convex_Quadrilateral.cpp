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
#define PI acos(-1.0)
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

int lengthSquare(pair<int, int> X, pair<int, int> Y)
{
    int xDiff = X.first - Y.first;
    int yDiff = X.second - Y.second;
    return xDiff * xDiff + yDiff * yDiff;
}
double total = 0;
bool isOk(pair<int, int> A, pair<int, int> B,
          pair<int, int> C)
{

    int a2 = lengthSquare(B, C);
    int b2 = lengthSquare(A, C);
    int c2 = lengthSquare(A, B);

    float a = sqrt(a2);
    float b = sqrt(b2);
    float c = sqrt(c2);

    float alpha = acos((b2 + c2 - a2) / (2 * b * c));
    float beta = acos((a2 + c2 - b2) / (2 * a * c));
    float gamma = acos((a2 + b2 - c2) / (2 * a * b));

    alpha = alpha * 180 / PI;
    beta = beta * 180 / PI;
    gamma = gamma * 180 / PI;

    // cout << "alpha is : " << alpha << endl;
    total += alpha;
    if (alpha >= 180)
        return false;
    return true;
}

void solve(int kase)
{
    vector<pair<int, int>> vec;
    for (int i = 0; i < 4; i++)
    {
        int a, b;
        cin >> a >> b;
        vec.pb({a, b});
    }

    if (isOk(vec[0], vec[1], vec[3]) && isOk(vec[1], vec[2], vec[0]) && isOk(vec[2], vec[3], vec[1]) && isOk(vec[3], vec[0], vec[2]))
    {
        if (total < 359)
            cout << "No\n";
        else
            cout << "Yes\n";
    }
    else
    {
        cout << "No\n";
    }
}

int main()
{
    int tc = 1;
    // cin >> tc;
    for (int i = 1; i <= tc; i++)
    {
        solve(i);
    }

    return 0;
}

/*"Success isn't permanent, failure isn't fatal,
                                     it's the courage to continue that counts"*/
