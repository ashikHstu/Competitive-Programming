/**        بِسْمِ اللهِ الرَّحْمٰنِ الرَّحِيْمِ (In the name of God, the Most Gracious, the Most Merciful.)       */
/*
      Institution : Hajee Mohammad Danesh Science and Technology University,Dinajpur,Bangladesh.
      Name        : Ashikur Rahman Bhuyain (Asif)
      Email       : ashik.cse.hstu@gmail.com
*/

/*
   Problem link : https://vjudge.net/problem/UVA-991
   verdict : Accepted
*/

#include <bits/stdc++.h>
using namespace std;
#define ll long long int
ll nCr(ll n, ll r)
{
    if (n == r || r == 0)
        return 1;
    if (r == 1 || r == n - 1)
        return n;

    r = max(r, n - r);
    ll res = 1;
    for (int i = 1; i <= r; i++)
    {
        res = (res * (n - r + i)) / i;
    }
    return res;
}
int main()
{
    int n;
    bool started = false;
    while (cin >> n)
    {
        if (started)
            cout << endl;
        started = true;
        ll temp = nCr(2 * n, n);
        temp = temp / (n + 1);
        cout << temp << endl;
    }
    return 0;
}