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

void solve()
{
    ll a, b, x, y;
    cin >> x >> y >> a >> b;
    if (a > b)
        swap(a, b);
    if (x > y)
        swap(x, y);
    ll iDif = b - a;
    ll allDif = y - x;
    int exMove = 0;
    if (iDif != 0)
    {
        exMove = (allDif / iDif);
        if (exMove * a >= x)
        {
            ll upai = x / a;
            cout << upai << endl;
            return;
        }
        ///  cout << "x, y : " << x << ", " << y << endl;
        //  cout << "value of exMove : " << exMove << endl;
        x -= (exMove * a);
        y -= (exMove * b);
    }
    int total = (a + b);
    ll aroBad = (x / total);
    x -= (aroBad * total);
    y -= (aroBad * total);
    exMove += (aroBad * 2);
    if (y >= b && x >= a)
        exMove++;

    cout << exMove << endl;
}

int main()
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

/*"Success isn't permanent, failure isn't fatal,
                                     it's the courage to continue that counts"*/
