#include <bits/stdc++.h>
using namespace std;
string st;

void fun(string ans, int index, bool last)
{
    if (index == st.size())
    {
        cout << ans << endl;
        return;
    }

    int till = (last ? (st[index] - '0') : 9);
    for (int i = 0; i <= till; i++)
    {
        fun(ans + to_string(i), index + 1, (last && (i == till)));
    }
}

int main()
{
    cin >> st;
    fun("", 0, true);
    return 0;
}