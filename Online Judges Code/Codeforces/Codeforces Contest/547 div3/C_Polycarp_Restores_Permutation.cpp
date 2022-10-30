/**        بِسْمِ اللهِ الرَّحْمٰنِ الرَّحِيْمِ (In the name of God, the Most Gracious, the Most Merciful.)       */
/*
      Institution : Hajee Mohammad Danesh Science and Technology University,Dinajpur,Bangladesh.
      Name        : Ashikur Rahman Bhuyain (Asif)
      Email       : ashik.cse.hstu@gmail.com
*/

#include <bits/stdc++.h>
using namespace std;

#define ll long long int
#define pb push_back
#define FasterIO             \
    ios::sync_with_stdio(0); \
    cin.tie(0);              \
    cout.tie(0)

int main()
{
    FasterIO;
    ll n;
    cin >> n;
    ll sum = (n * (n + 1));
    sum /= 2;
    ll ar[n + 3];
    for (int i = 0; i < n - 1; i++)
    {
        cin >> ar[i];
        sum += (ar[i] * (i + 1));
    }
    sum /= n;
    vector<int> res;
    res.pb(sum);
    for (int i = n - 2; i >= 0; i--)
    {
        sum = sum - ar[i];
        res.pb(sum);
    }
    reverse(res.begin(), res.end());

    vector<int> test(res.begin(), res.end());
    sort(test.begin(), test.end());
    for (int i = 0; i < n; i++)
    {
        if (test[i] != i + 1)
        {
            cout << "-1\n";
            return 0;
        }
    }

    for (int v : res)
        cout << v << " ";
    cout << endl;

    return 0;
}

/*"Success isn't permanent, failure isn't fatal,
                                     it's the courage to continue that counts"*/
