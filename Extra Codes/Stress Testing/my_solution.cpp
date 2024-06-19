#include <bits/stdc++.h>
using namespace std;

int main()
{
    int a, b, c, t, tent;
    cin >> t;
    while (t--)
    {
        tent = 0;
        cin >> a >> b >> c;
        if ((b % 3 + c) / 3 > 0 || b % 3 == 0)
        {
            tent = a + b / 3 + (b % 3 + c) / 3;
            if ((b % 3 + c) % 3 != 0)
                tent++;
        }
        else
            tent = -1;
        cout << tent << endl;
    }
}
