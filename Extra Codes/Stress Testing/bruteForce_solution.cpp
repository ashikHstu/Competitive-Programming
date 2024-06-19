#include <bits/stdc++.h>
#define int long long int
using namespace std;

int32_t main()
{

    int t;
    cin >> t;

    while (t--)
    {
        int a, b, c;
        cin >> a >> b >> c;
        int res = a;
        int bM = b % 3;
        if (bM != 0)
            bM = 3 - bM;
        // cout << "bm : " << bM << endl;
        if (bM > c)
        {
            cout << "-1\n";
        }
        else
        {
            int total = b + c;
            res += (total / 3) + (total % 3 != 0);
            cout << res << endl;
        }
    }

    return 0;
}