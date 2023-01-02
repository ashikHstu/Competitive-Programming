/** Problem link : https://cses.fi/problemset/task/1753
 * verdict : Accepted
 * Using : KMP
 *
 */

#include <bits/stdc++.h>
using namespace std;

string removeSpaces(string str)
{
    str.erase(remove(str.begin(), str.end(), ' '), str.end());
    return str;
}

#define mx 3000005
int f[mx];

void kmp_precompute(string pat)
{
    int n = pat.size();
    memset(f, 0, sizeof(f));
    int j = 0;
    for (int i = 1; i < n; i++)
    {
        if (pat[i] == pat[j])
        {
            f[i] = j + 1;
            j++;
        }
        else
        {
            while (j != 0)
            {
                j = f[j - 1];
                if (pat[i] == pat[j])
                {
                    f[i] = j + 1;
                    j++;
                    break;
                }
            }
        }
    }
}

int findCount(string mainString, string pat)
{
    //  cout << mainString << endl;
    //  cout << pat << endl;
    int patSize = pat.size();
    pat += "$";
    pat += mainString;
    int ct = 0;
    kmp_precompute(pat);

    for (int i = 0; i < pat.size(); i++)
    {
        if (f[i] == patSize)
            ct++;
    }
    return ct;
}

void solve()
{
    string mainString;

    getline(cin, mainString);

    string pat;

    getline(cin, pat);
    mainString = removeSpaces(mainString);
    pat = removeSpaces(pat);
    // cout << mainString << endl;
    // cout << pat << endl;

    cout << findCount(mainString, pat) << endl;
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
