#include <bits/stdc++.h>
using namespace std;
int Forward(int n, int cur, int jabe)
{
    int ekhon = cur + jabe;
    if (ekhon > n)
    {
        ekhon = ekhon % n;
        if (ekhon == 0)
            ekhon = n;
    }
    return ekhon;
}

int Backward(int n, int cur, int jabe)
{
    int ekhon = cur - jabe;
    if (ekhon < 1)
    {
        ekhon = ekhon % n;
        ekhon += n;
    }

    return ekhon;
}

vector<int> uniqueVec(vector<int> vec)
{
    sort(vec.begin(), vec.end());
    auto last = unique(vec.begin(), vec.end());
    vec.resize(distance(vec.begin(), last));
    return vec;
}

void solve()
{
    int n, t, c;
    cin >> n >> t >> c;
    vector<int> cur;
    cur.push_back(c);
    for (int i = 0; i < t; i++)
    {
        int dis;
        char clock;
        vector<int> ekhon;
        cin >> dis >> clock;
        for (int v : cur)
        {
            int fv = Forward(n, v, dis);
            int bv = Backward(n, v, dis);
            if (clock == '0')
            {
                ekhon.push_back(fv);
            }
            else if (clock == '1')
                ekhon.push_back(bv);
            else
            {
                ekhon.push_back(fv);
                ekhon.push_back(bv);
            }
        }

        cur = uniqueVec(ekhon);
        // cout << i + 1 << "th curr prob: ";
        // for (int v : cur)
        //     cout << v << " ";
        // cout << endl;
    }

    cout << cur.size() << endl;
    for (int v : cur)
        cout << v << " ";
    cout << endl;
}

int main()
{
    int tc;
    cin >> tc;
    while (tc--)
        solve();

    return 0;
}