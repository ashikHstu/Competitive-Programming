
#include <bits/stdc++.h>
using namespace std;

#define ll long long int

bool Alice(string st)
{
    int ct = 0;
    int n = st.size();
    for (int i = 0; i < n; i++)
    {
        if (st[i] == 'X')
            ct++;
        else
            ct = 0;
        if (ct >= 3)
            return true;
    }
    return false;
}
bool Bob(string st)
{
    int ct = 0;
    int n = st.size();
    for (int i = 0; i < n; i++)
    {
        if (st[i] == 'O')
            ct++;
        else
            ct = 0;
        if (ct >= 3)
            return true;
    }
    return false;
}

bool isBob(string st)
{
    string tmp = st;
    int n = st.size();
    if (Bob(tmp))
    {
        return true;
    }
    for (int i = 1; i < n; i++)
    {
        swap(tmp[i - 1], tmp[i]);
        if (tmp[i] != tmp[i - 1])
        {
            if (i - 3 >= 0)
            {
                if (tmp[i - 1] == 'O' && tmp[i - 2] == 'O' && tmp[i - 3] == 'O')
                    return true;
            }
            if (i + 2 < n)
            {
                if (tmp[i] == 'O' && tmp[i + 1] == 'O' && tmp[i + 2] == 'O')
                    return true;
            }
        }

        swap(tmp[i - 1], tmp[i]);
    }

    return false;
}

void solve()
{
    string st;
    cin >> st;
    string tmp = st;
    int n = st.size();
    int bob = 0;

    for (int i = 1; i < n; i++)
    {
        swap(tmp[i - 1], tmp[i]);
        if (Alice(tmp))
        {
            cout << "Alice\n";
            return;
        }
        else if (isBob(tmp))
        {
            bob++;
        }
        swap(tmp[i - 1], tmp[i]);
    }

    if (bob == n - 1)
    {
        cout << "Bob\n";
        return;
    }
    cout << "Tie\n";
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
