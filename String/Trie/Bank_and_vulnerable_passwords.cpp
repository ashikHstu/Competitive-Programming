/**        بِسْمِ اللهِ الرَّحْمٰنِ الرَّحِيْمِ (In the name of God, the Most Gracious, the Most Merciful.)       */
/*
      Institution : Hajee Mohammad Danesh Science and Technology University,Dinajpur,Bangladesh.
      Name        : Ashikur Rahman Bhuyain (Asif)
      Email       : ashik.cse.hstu@gmail.com
*/

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
/*----------------------Graph Moves----------------*/
// const int fx[]={+1,-1,+0,+0};
// const int fy[]={+0,+0,+1,-1};
// const int fx[]={+0,+0,+1,-1,-1,+1,-1,+1};   // Kings Move
// const int fy[]={-1,+1,+0,+0,+1,+1,-1,-1};  // Kings Move
// const int fx[]={-2, -2, -1, -1,  1,  1,  2,  2};  // Knights Move
// const int fy[]={-1,  1, -2,  2, -2,  2, -1,  1}; // Knights Move
/*------------------------------------------------*/

class Vertex
{
public:
    int string_ends;
    vector<int> next;
    Vertex(int k)
    {
        string_ends = 0;
        next.resize(k, -1);
    }
};

class Trie
{
public:
    int K;
    vector<Vertex> nodes;
    Trie(int k)
    {
        K = k;
        nodes.push_back(Vertex(k));
    }

    void add(string s)
    {
        int cur = 0;
        for (auto c : s)
        {
            if (nodes[cur].next[c - 'a'] == -1)
            {
                nodes[cur].next[c - 'a'] = nodes.size();
                nodes.push_back(Vertex(K));
            }
            cur = nodes[cur].next[c - 'a'];
        }
        nodes[cur].string_ends++;
    }

    bool bad(int x)
    {
        if (nodes[x].string_ends >= 2)
            return true;

        for (int i = 0; i < K; i++)
        {
            if (nodes[x].next[i] != -1)
            {
                if (nodes[x].string_ends)
                    return true;
                if (bad(nodes[x].next[i]))
                    return true;
            }
        }
        return false;
    }

    void print(int x, vector<bool> &lst, string &s)
    {
        for (int i = 0; i < ((int)lst.size()) - 1; i++)
        {
            if (lst[i])
                cout << " ";
            else
                cout << "| ";
        }
        if (!lst.empty())
            cout << "|--";
        cout << x << " " << s << " " << nodes[x].string_ends << endl;
        int mx = -1;

        for (int i = 0; i < K; i++)
        {
            if (nodes[x].next[i] != -1)
            {
                mx = i;
            }
        }
        lst.push_back(false);
        for (int i = 0; i < K; i++)
        {
            if (nodes[x].next[i] != -1)
            {
                s.push_back('a' + i);
                if (i == mx)
                    lst.back() = true;
                print(nodes[x].next[i], lst, s);
                s.pop_back();
            }
        }
        lst.pop_back();
        return;
    }
};

void solve()
{
    Trie t(26);
    int n;
    cin >> n;
    for (int i = 0; i < n; i++)
    {
        string st;
        cin >> st;
        t.add(st);
    }
    if (t.bad(0))
        cout << "vulnerable\n";
    else
        cout << "non vulnerable\n";
}

int main()
{
    int tc = 1;
    // cin >> tc;
    for (int i = 1; i <= tc; i++)
    {
        solve();
    }

    return 0;
}

/*"Success isn't permanent, failure isn't fatal,
                                     it's the courage to continue that counts"*/
