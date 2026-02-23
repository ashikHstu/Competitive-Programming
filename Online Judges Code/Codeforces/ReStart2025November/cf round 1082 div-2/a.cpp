#include <bits/stdc++.h>
using namespace std;

bool zeroPossible(int v)
{
    //cout<<"ki ache: "<<v<<endl;
    if (v % 3 == 0)
        return true;
    return false;
}

void solve()
{
    int a, b;
    cin >> a >> b;
    if (a == 1)
    {
        cout << "NO\n";
        return;
    }
    int req = b * 2;
    if (b < 0)
        req = (b * 4)*(-1);

    if (a == 1 || req > a)
    {
        cout << "NO\n";
        return;
    }
    int makeZero = a - req;

    if (zeroPossible(makeZero))
    {
        cout << "YES\n";
    }
    else
    {
        cout << "NO\n";
    }
}

int main()
{
    int tc;
    cin >> tc;
    while (tc--)
    {
        solve();
    }
}