#include <bits/stdc++.h>
using namespace std;

class helper
{
private:
    string st1, st2;

public:
    helper(string st1, string st2)
    {
        this->st1 = st1;
        this->st2 = st2;
    }
    void makeResult()
    {
        swap(st1[0], st2[0]);
        cout << st1 << " " << st2 << endl;
    }
};

void solve()
{
    string st1, st2;
    Helper help(st1, st2);
    help.makeResult();
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