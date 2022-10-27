/**        بِسْمِ اللهِ الرَّحْمٰنِ الرَّحِيْمِ (In the name of Allah, the Most Gracious, the Most Merciful.)              */

#include <bits/stdc++.h>
using namespace std;

#define FasterIO             \
    ios::sync_with_stdio(0); \
    cin.tie(0);              \
    cout.tie(0)
#define TIME clock() * 1.0 / CLOCKS_PER_SEC
#define pi acos(-1.0)
/// Library
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
#define for0(i, n) for (int i = 0; i < n; i++)
#define for1(i, n) for (int i = 1; i <= n; i++)

#define POSL(x, v) (lower_bound(x.begin(), x.end(), v) - x.begin())
#define POSU(x, v) (upper_bound(x.begin(), x.end(), v) - x.begin())
#define min3(a, b, c) min(a, min(b, c))
#define min4(a, b, c, d) min(a, min(b, min(c, d)))
#define max3(a, b, c) max(a, max(b, c))
#define max4(a, b, c, d) max(a, max(b, max(c, d)))
#define ABS(x) ((x) < 0 ? -(x) : (x))
#define pb push_back
//#define nl                 printf("\n")
#define endl '\n'

/*----------------------Graph Moves----------------*/
// const int fx[]={+1,-1,+0,+0};
// const int fy[]={+0,+0,+1,-1};
// const int fx[]={+0,+0,+1,-1,-1,+1,-1,+1};   // Kings Move
// const int fy[]={-1,+1,+0,+0,+1,+1,-1,-1};  // Kings Move
// const int fx[]={-2, -2, -1, -1,  1,  1,  2,  2};  // Knights Move
// const int fy[]={-1,  1, -2,  2, -2,  2, -1,  1}; // Knights Move
/*------------------------------------------------*/

/// vector
#define Lower_bound(vec, value) lower_bound(vec.begin(), vec.end(), value)
#define Upper_bound(vec, value) upper_bound(vec.begin(), vec.end(), value)

/// File In
#define READ(f) freopen(f ".in", "r", stdin)
#define WRITE(f) freopen(f ".out", "w", stdout)

#define mod 1000000007
#define ll long long int
#define SIZ 1000005

void solve()
{

    int a, b, k;
    cin >> a >> b >> k;

    if (a == 1 and b == 1)
    {
        cout << "NO\n";
        return;
    }

    if (a == 1 || b == 1)
    {

        int aRemove = max(a, b);

        int aMove = 0;
        for (int i = 2; i * i <= aRemove; i++)
        {
            while (aRemove % i == 0)
            {
                aRemove /= i;
                aMove++;
            }
        }

        if (aRemove != 1)
            aMove++;

        if (k <= aMove)
            cout << "YES\n";
        else
            cout << "NO\n";
        return;
    }

    if (k == 1 && (a % b == 0 || b % a == 0) && a != b)
    {
        cout << "YES\n";
        return;
    }
    if (k == 1)
    {
        cout << "NO\n";
        return;
    }

    if (k == 2)
    {
        cout << "YES\n";
        return;
    }

    int Gcd = gcd(a, b);

    int aRemove = a / Gcd;
    int bRemove = b / Gcd;

    int aMove = 0, bMove = 0;
    for (int i = 2; i * i <= aRemove; i++)
    {
        while (aRemove % i == 0)
        {
            aRemove /= i;
            aMove++;
        }
    }

    if (aRemove != 1)
        aMove++;

    for (int i = 2; i * i <= bRemove; i++)
    {
        while (bRemove % i == 0)
        {
            bRemove /= i;
            bMove++;
        }
    }

    if (bRemove != 1)
        bMove++;

    if (k <= aMove + bMove)
    {
        cout << "YES\n";
        return;
    }

    int newK = k - aMove - bMove;

    // cout<<"newK : "<<newK<<endl;

    //   if(newK%2!=0){
    //    if(aMove>1 || bMove>1)newK++;
    //    else {
    //        cout<<"NO\n";
    //        return;
    //    }
    //   }

    int gcdMove = 0;

    for (int i = 2; i * i <= Gcd; i++)
    {
        while (Gcd % i == 0)
        {
            Gcd /= i;
            gcdMove += 2;
        }
    }

    // cout<<"total move : "<<gcdMove+aMove+bMove<<endl;

    if (Gcd != 1)
        gcdMove += 2;

    if (newK <= gcdMove)
    {
        cout << "YES\n";
        return;
    }

    cout << "NO\n";
}

int main()
{
    // FasterIO;

    int tc = 1;
    scanf("%d", &tc);
    for1(i, tc) solve();
    return 0;
}
