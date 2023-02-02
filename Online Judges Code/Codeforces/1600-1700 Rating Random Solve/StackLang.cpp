/**        بِسْمِ اللهِ الرَّحْمٰنِ الرَّحِيْمِ (In the name of God, the Most Gracious, the Most Merciful.)       */
/*
      Institution : Hajee Mohammad Danesh Science and Technology University,Dinajpur,Bangladesh.
      Name        : Ashikur Rahman Bhuyain (Asif)
      Email       : ashik.cse.hstu@gmail.com
*/

/*
   Problem link :
   verdict :
*/

#pragma GCC optimize("O3,unroll-loops")
#pragma GCC target("avx2,bmi,bmi2,lzcnt,popcnt")

#include <bits/stdc++.h>
using namespace std;

#define ll long long int

#define FasterIO             \
    ios::sync_with_stdio(0); \
    cin.tie(0);              \
    cout.tie(0)
#define TIME clock() * 1.0 / CLOCKS_PER_SEC
#define pi acos(-1.0)
#define mem(a, b) memset(a, b, sizeof(a))
#define all(a) a.begin(), a.end()
#define Sort(x) sort(x.begin(), x.end())
#define Reverse(x) reverse(x.begin(), x.end())
#define SortA(ar, s) sort(ar, ar + s)
#define SortD(ar, s) sort(ar, ar + s, greater<int>())
#define gcd(a, b) __gcd(a, b)
#define lcm(a, b) (a * (b / gcd(a, b)))
#define sq(x) (x) * (x)
#define CEIL(a, b) ((a / b) + ((a % b) != 0))
#define endl "\n"

#define POSL(x, v) (lower_bound(x.begin(), x.end(), v) - x.begin())
#define POSU(x, v) (upper_bound(x.begin(), x.end(), v) - x.begin())
#define min3(a, b, c) min(a, min(b, c))
#define min4(a, b, c, d) min(a, min(b, min(c, d)))
#define max3(a, b, c) max(a, max(b, c))
#define max4(a, b, c, d) max(a, max(b, max(c, d)))
#define ABS(x) ((x) < 0 ? -(x) : (x))
#define pb push_back
#define nl printf("\n")

/** STL Functions     */
// pbds
#define fbo(ind) find_by_order(ind)
#define ook(val) order_of_key(val)

/**      Extra storing              */
#define UNIQUE(v) (v).erase(unique(all(v)), (v).end())

/**        End of Ex Storing                */

/**------- Char Chk----------*/
inline bool isLower(char ch) { return (ch >= 'a' && ch <= 'z'); }
inline bool isUpper(char ch) { return (ch >= 'A' && ch <= 'Z'); }
inline bool isDigit(char ch) { return (ch >= '0' && ch <= '9'); }
inline bool isVowel(char ch)
{
    ch = tolower(ch);
    return (ch == 'a' || ch == 'e' || ch == 'i' || ch == 'o' || ch == 'u');
}
string to_upper(string a)
{
    for (int i = 0; i < (int)a.size(); ++i)
        if (a[i] >= 'a' && a[i] <= 'z')
            a[i] -= 'a' - 'A';
    return a;
}
string to_lower(string a)
{
    for (int i = 0; i < (int)a.size(); ++i)
        if (a[i] >= 'A' && a[i] <= 'Z')
            a[i] += 'a' - 'A';
    return a;
}
bool prime(ll a)
{
    if (a == 1)
        return 0;
    for (int i = 2; i <= round(sqrt(a)); ++i)
        if (a % i == 0)
            return 0;
    return 1;
}
/* PRINTS */
template <class T>
void print_v(vector<T> &v)
{
    cout << "{";
    for (auto x : v)
        cout << x << ",";
    cout << "\b}";
}

/*----------------------Graph Moves----------------*/
// const int fx[]={+1,-1,+0,+0};
// const int fy[]={+0,+0,+1,-1};
// const int fx[]={+0,+0,+1,-1,-1,+1,-1,+1};   // Kings Move
// const int fy[]={-1,+1,+0,+0,+1,+1,-1,-1};  // Kings Move
// const int fx[]={-2, -2, -1, -1,  1,  1,  2,  2};  // Knights Move
// const int fy[]={-1,  1, -2,  2, -2,  2, -1,  1}; // Knights Move
/*------------------------------------------------*/
ll limit = 1e6;
deque<ll> dq;
bool reversed = false;
ll sum = 0;

void myPush2(ll v)
{

    if (!reversed)
    {
        if (dq.size() == limit)
        {
            sum -= dq.front();
            dq.pop_front();
        }
        dq.push_back(v);
        sum += v;
    }
    else
    {
        if (dq.size() == limit)
        {
            sum -= dq.back();
            dq.pop_back();
        }
        dq.push_front(v);
        sum += v;
    }
}

void myPush()
{
    ll v;
    cin >> v;
    if (!reversed)
    {
        if (dq.size() == limit)
        {
            sum -= dq.front();
            dq.pop_front();
        }
        dq.push_back(v);
        sum += v;
    }
    else
    {
        if (dq.size() == limit)
        {
            sum -= dq.back();
            dq.pop_back();
        }
        dq.push_front(v);
        sum += v;
    }
}

void myPrint()
{
    if (dq.size() == 0)
    {
        cout << "-" << endl;
        return;
    }
    ll v = dq.back();
    if (reversed)
        v = dq.front();
    cout << v << endl;
}

void myReverse()
{
    reversed = (reversed ^ 1);
}

void myPop()
{
    if (dq.size() == 0)
        return;
    if (reversed)
    {
        sum -= dq.front();
        dq.pop_front();
    }
    else
    {
        sum -= dq.back();
        dq.pop_back();
    }
}

void mySize()
{
    cout << dq.size() << endl;
}

void mySum()
{
    cout << sum << endl;
}
void myRepeat()
{

    ll times;
    cin >> times;
    if (dq.size() == 0)
        return;
    ll times2 = times;
    ll sz = dq.size();
    if (sz == limit)
        return;
    ll possible = CEIL(limit, sz);
    times = min(times, possible - 1);

    ll lagbei = limit / sz;
    lagbei = min(lagbei - 1, times2);

    if (lagbei > 0)
    {
        deque<ll> dqnn = dq;

        vector<ll> vec;
        while (dqnn.size() != 0)
        {
            vec.push_back(dqnn.front());
            dqnn.pop_front();
        }
        // if (vec.size() != dq.size())
        // {
        //     cout << "WA please\n";
        //     return;
        // }
        if (reversed)
        {
            // deque<ll> dqn = dqnn;
            for (int i = 1; i <= lagbei; i++)
            {
                for (int j = vec.size() - 1; j >= 0; j--)
                {
                    myPush2(vec[j]);
                }
                // while (dqn.size() != 0)
                // {
                //     myPush2(dqn.back());
                //     dqn.pop_back();
                // }
            }
        }
        else
        {
            // deque<ll> dqn = dqnn;
            for (int i = 1; i <= lagbei; i++)
            {
                for (int j = 0; j < vec.size(); j++)
                {
                    myPush2(vec[j]);
                }
                // while (dqn.size() != 0)
                // {
                //     myPush2(dqn.front());
                //     dqn.pop_front();
                // }
            }
        }
    }
    if (lagbei < times)
    {
        ll ext = limit - dq.size();
        // if (ext > dq.size())
        // {
        //     cout << "Error plz\n";
        //     return;
        // }
        ll dqs = dq.size();
        ext = min(ext, dqs);

        if (reversed)
        {
            vector<ll> vec;
            for (int i = 0; i < ext; i++)
            {
                vec.pb(dq.front());
                dq.pop_front();
            }
            for (int i = vec.size() - 1; i >= 0; i--)
            {
                dq.push_front(vec[i]);
            }

            reversed = reversed ^ 1;
            for (int i = 0; i < vec.size(); i++)
            {
                myPush2(vec[i]);
            }
            reversed = reversed ^ 1;
        }
        else
        {
            vector<ll> vec;
            for (int i = 0; i < ext; i++)
            {
                vec.pb(dq.back());
                dq.pop_back();
            }
            for (int i = vec.size() - 1; i >= 0; i--)
            {
                dq.push_back(vec[i]);
            }

            reversed = reversed ^ 1;
            for (int i = 0; i < vec.size(); i++)
            {
                myPush2(vec[i]);
            }
            reversed = reversed ^ 1;
        }
    }
}

int main()
{
    ll nn = (1 << 14);
    int z = 0;
    for (int i = 0; i < nn; i++)
    {
        for (int j = 0; j < nn; j++)
        {
            if ((i & j) == 0)
                z++;
        }
    }
    cout << z << endl;
    return 0;
    FasterIO;
    string st;
    while (cin >> st)
    {
        if (st == "PUSH")
            myPush();
        else if (st == "POP")
            myPop();
        else if (st == "PRINT")
        {
            myPrint();
        }
        else if (st == "REVERSE")
        {
            myReverse();
        }
        else if (st == "REPEAT")
        {
            myRepeat();
        }
        else if (st == "SUM")
        {
            mySum();
        }
        else if (st == "SIZE")
        {
            mySize();
        }
        else
        {
            cout << "Give error\n";
        }
    }

    return 0;
}

/*"Success isn't permanent, failure isn't fatal,
                                     it's the courage to continue that counts"*/
