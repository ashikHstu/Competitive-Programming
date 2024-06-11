#include <bits/stdc++.h>
using namespace std;

class helper
{
private:
    int n;
    vector<int> vec;

public:
    helper(int n, vector<int> v)
    {
        this->n = n;
        this->vec = v;
    }
    bool isPossible()
    {
        for (int i = 1; i < vec.size(); i++)
        {
            if (vec[i] != vec[i - 1])
                return true;
        }
        return false;
    }
    bool makeAnswer()
    {
        map<int, int> mp;
        int uniq = 0;
        for (int i = 0; i < n; i++)
        {
            mp[vec[i]]++;
            if (mp[vec[i]] == 1)
                uniq++;
        }

        string res;
        int nichi = false;
        for (int i = 0; i < n; i++)
        {
            if (nichi == false && (mp[vec[i]] > 1 || uniq > 2))
            {
                res.push_back('B');
                nichi = true;
            }
            else
            {
                res.push_back('R');
            }
        }
        cout << res << endl;
    }
};

void solve()
{
    int n;
    cin >> n;
    vector<int> vec(n);
    for (int &v : vec)
        cin >> v;
    helper help(n, vec);
    if (help.isPossible())
    {
        cout << "YES\n";
        help.makeAnswer();
    }
    else
    {
        cout << "NO\n";
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