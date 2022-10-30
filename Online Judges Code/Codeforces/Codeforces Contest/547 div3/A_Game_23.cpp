/**        بِسْمِ اللهِ الرَّحْمٰنِ الرَّحِيْمِ (In the name of God, the Most Gracious, the Most Merciful.)       */
/*
      Institution : Hajee Mohammad Danesh Science and Technology University,Dinajpur,Bangladesh.
      Name        : Ashikur Rahman Bhuyain (Asif)
      Email       : ashik.cse.hstu@gmail.com
*/

#include <bits/stdc++.h>
using namespace std;

void solve()
{
    int n, m;
    cin >> n >> m;
    if (m % n != 0)
    {
        cout << "-1\n";
        return;
    }
    int vagfol = m / n;
    int op = 0;
    while (vagfol % 2 == 0)
    {
        vagfol /= 2;
        op++;
    }
    while (vagfol % 3 == 0)
    {
        vagfol /= 3;
        op++;
    }
    if (vagfol == 1)
        cout << op << endl;
    else
        cout << "-1\n";
}

int main()
{
    int tc = 1;
    // cin >> tc;
    for (int i = 1; i <= tc; i++)
    {
        solve();
    }

    return 0;
}

/*"Success isn't permanent, failure isn't fatal,
                                     it's the courage to continue that counts"*/
