#include <bits/stdc++.h>
using namespace std;
#define ll double
#define all(x) x.begin(), x.end()

template <class T>
void print_v(vector<T> &v)
{
    cout << "{";
    for (auto x : v)
        cout << x << ",";
    cout << "\b}";
}

bool isPossible(vector<ll> sutcase, vector<ll> blanket)
{
    sort(all(blanket));
    sort(all(sutcase));
    for (int i = 0; i < 3; i++)
    {
        if (blanket[i] > sutcase[i])
            return false;
    }

    return true;
}

int main()
{
    ll tc, x, y, z, l, w, h;
    cin >> tc;
    vector<ll> sutcase;
    vector<ll> blanket;
    while (tc--)
    {

        ll c = 0;
        cin >> x >> y >> z;
        sutcase.push_back(x);
        sutcase.push_back(y);
        sutcase.push_back(z);
        cin >> l >> w >> h;
        blanket.push_back(l);
        blanket.push_back(w);
        blanket.push_back(h);

        sort(sutcase.begin(), sutcase.end());
        int res = 0;
        bool gunDichi1 = false, gunDichi2 = false;

        for (double i = 0; i <= 32; i++)
        {
            for (double j = 0; j <= 32; j++)
            {
            }
        }

        if (blanket[0] < blanket[1])
        {
            int res = 0;
            while (!isPossible(sutcase, blanket))
            {
                blanket[1] = blanket[1] / 2.0;
                blanket[0] = blanket[0] * 2.0;
                res++;
                if (blanket[0] > blanket[1])
                    break;
            }
            if (isPossible(sutcase, blanket))
            {
                cout << res << endl;
            }
            else
            {
                cout << "-1\n";
            }
        }

        else if (blanket[0] > blanket[1])
        {
            int res = 0;
            while (!isPossible(sutcase, blanket))
            {
                print_v(blanket);
                cout << endl;
                blanket[0] = blanket[0] / 2.0;
                blanket[1] = blanket[1] * 2.0;
                res++;
                if (blanket[0] < blanket[1])
                    break;
            }
            if (isPossible(sutcase, blanket))
            {
                cout << res << endl;
            }
            else
            {
                cout << "-1\n";
            }
        }
        else if (isPossible(sutcase, blanket))
        {
            cout << "0\n";
        }
        else
        {
            cout << "-1\n";
        }
    }
    return 0;
}