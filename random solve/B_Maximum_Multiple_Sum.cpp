#include <bits/stdc++.h>
using namespace std;

class helper
{
private:
    int n;

public:
    helper(int n)
    {
        this->n = n;
    }
    void calculate()
    {
        int res = -1;
        int maxSum = 0;
        for (int i = 2; i <= n; i++)
        {
            int sum = 0;
            for (int j = i; j <= n; j += i)
            {
                sum += j;
            }
            if (maxSum < sum)
            {
                maxSum = sum;
                res = i;
            }
        }
        cout << res << endl;
    }
};

void solve()
{
    int n;
    cin >> n;
    helper help(n);
    help.calculate();
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