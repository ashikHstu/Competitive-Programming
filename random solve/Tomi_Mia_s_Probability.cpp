#include <bits/stdc++.h>
using namespace std;

#define optimize()                \
    ios_base::sync_with_stdio(0); \
    cin, tie(0);                  \
    cout.tie(0)
#define endl '\n'

int main()
{
    long long fact[20];
    fact[0] = fact[1] = 1;
    for (int i = 2; i <= 20; i++)
    {
        fact[i] = fact[i - 1] * i;
    }
    int t;
    cin >> t;
    cin.ignore();
    while (t--)
    {
        string s;
        getline(cin, s);
        map<string, int> m;
        string word;
        int tw = 0;
        for (auto u : s)
        {
            if (u != ' ')
            {
                word += u;
            }
            else
            {
                if (!word.empty())
                {
                    tw++;
                    m[word]++;
                    word.clear();
                }
            }
        }
        if (!word.empty())
        {
            m[word]++;
            tw++;
        }
        long long res = fact[tw];

        for (auto u : m)
        {

            if (u.second > 1)
            {
                res /= (fact[u.second]);
            }
        }
        cout << "1/" << res << endl;
        // cout << total << " " << many << endl;
    }
}