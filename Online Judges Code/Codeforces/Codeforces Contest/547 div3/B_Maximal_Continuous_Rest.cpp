/**        بِسْمِ اللهِ الرَّحْمٰنِ الرَّحِيْمِ (In the name of God, the Most Gracious, the Most Merciful.)       */
/*
      Institution : Hajee Mohammad Danesh Science and Technology University,Dinajpur,Bangladesh.
      Name        : Ashikur Rahman Bhuyain (Asif)
      Email       : ashik.cse.hstu@gmail.com
*/

#include <bits/stdc++.h>
using namespace std;
#define pb push_back

int main()
{
    int n;
    cin >> n;
    vector<int> ar;
    for (int i = 0; i < n; i++)
    {
        int v;
        cin >> v;
        ar.pb(v);
    }
    for (int i = 0; i < n; i++)
    {
        ar.pb(ar[i]);
    }
    int cz = 0;
    int res = 0;
    for (int i = 0; i < ar.size(); i++)
    {
        if (ar[i] == 1)
            cz++;
        else
            cz = 0;
        res = max(res, cz);
    }

    cout << res << endl;

    return 0;
}

/*"Success isn't permanent, failure isn't fatal,
                                     it's the courage to continue that counts"*/
