#include <bits/stdc++.h>
using namespace std;

class helper
{
private:
    int n;
    vector<int> vec;

public:
    helper(int n, vector<int> vec)
    {
        this->n = n;
        this->vec = vec;
    }
    int giveResult()
    {
        long long mx = 0;
        long long sum = 0;
        int res = 0;
        for (int i = 0; i < n; i++)
        {
            sum += vec[i];

            mx = max(mx, (long long)vec[i]);

            if (mx + mx == sum)
            {
                res++;
                // cout << "mx , sum : " << mx << ", " << sum << endl;
            }
        }
        return res;
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
    cout << help.giveResult() << endl;
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