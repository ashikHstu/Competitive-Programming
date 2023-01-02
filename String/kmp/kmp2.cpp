/**        بِسْمِ اللهِ الرَّحْمٰنِ الرَّحِيْمِ (In the name of God, the Most Gracious, the Most Merciful.)       */
/*
      Institution : Hajee Mohammad Danesh Science and Technology University,Dinajpur,Bangladesh.
      Name        : Ashikur Rahman Bhuyain (Asif)
      Email       : ashik.cse.hstu@gmail.com
*/

#include <bits/stdc++.h>
using namespace std;

#define MX 500000

int f[MX];

void kmp_preprocess(string st)
{
    int m = st.size();
    memset(f, 0, sizeof(f));
    int j = 0;
    for (int i = 1; i < m; i++)
    {
        if (st[i] == st[j])
        {
            f[i] = j + 1;
            j++;
        }
        else
        {

            while (j != 0)
            {
                j = f[j - 1];
                if (st[i] == st[j])
                {
                    f[i] = j + 1;
                    j++;
                    break;
                }
            }
        }
    }
}

bool kmp(string mainString, string pattern)
{
    int m = pattern.size();
    int n = mainString.size();
    int j = 0;
    for (int i = 0; i < n; i++)
    {
        if (pattern[j] == mainString[i])
        {
            if (j == m - 1)
            {
                return true;
            }
            j++;
        }
        else
        {
            while (j != 0)
            {
                j = f[j - 1];
                if (pattern[j] == mainString[i])
                {
                    j++;
                    break;
                }
            }
        }
    }
    return false;
}

void solve()
{
    string mainString;
    cin >> mainString;

    int n;
    cin >> n;
    for (int i = 0; i < n; i++)
    {
        string pat;
        cin >> pat;
        kmp_preprocess(pat);
        if (kmp(mainString, pat))
        {
            cout << "y\n";
        }
        else
        {
            cout << "n\n";
        }
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

/*"Success isn't permanent, failure isn't fatal,
                                     it's the courage to continue that counts"*/
