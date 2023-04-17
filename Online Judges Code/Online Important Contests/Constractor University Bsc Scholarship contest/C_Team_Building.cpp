#include <bits/stdc++.h>
using namespace std;

void solve()
{
    int n, l, r;
    cin >> n >> l >> r;
    string st;
    cin >> st;

    int tml = n / l;
    int tmr = n / r;
    if (tml == tmr && n % l != 0 && n % r != 0)
    {
        cout << "NO\n";
        return;
    }

    int capt = 0, nonc = 0, gen = 0;
    for (char ch : st)
    {
        if (ch == '1')
            capt++;
        else if (ch == '2')
            nonc++;
        else
            gen++;
    }
    int exP = 0;
    for (int i = 0; i < capt; i++)
    {
        int lagbe = l - 1;
        if (nonc >= lagbe)
            nonc -= lagbe;
        else if (nonc + gen >= lagbe)
        {
            lagbe -= nonc;
            nonc = 0;
            gen -= lagbe;
        }
        else
        {
            cout << "NO\n";
            return;
        }
        exP += (r - l);
    }
    if (nonc <= exP)
    {
        cout << "YES\n";
        return;
    }
    nonc -= exP;
    int bakiAche = nonc + gen;
    int maxTeam = (bakiAche / r) + ((bakiAche % r) != 0);
    if (maxTeam > gen)
    {
        cout << "NO\n";
    }
    else
    {
        cout << "YES\n";
    }
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
