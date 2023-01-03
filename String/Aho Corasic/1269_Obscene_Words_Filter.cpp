/**        بِسْمِ اللهِ الرَّحْمٰنِ الرَّحِيْمِ (In the name of God, the Most Gracious, the Most Merciful.)       */
/*
      Institution : Hajee Mohammad Danesh Science and Technology University,Dinajpur,Bangladesh.
      Name        : Ashikur Rahman Bhuyain (Asif)
      Email       : ashik.cse.hstu@gmail.com
*/
/**        بِسْمِ اللهِ الرَّحْمٰنِ الرَّحِيْمِ (In the name of God, the Most Gracious, the Most Merciful.)       */

/** Problem link : https://acm.timus.ru/problem.aspx?space=1&num=1269
 *
 * Status : WA(Runtime error (access violation))
 */
#include <bits/stdc++.h>
using namespace std;
const int mx = 2e5 + 5;
const int mxc = 26; // must set the maximum number of child

struct state
{
    int link;
    vector<int> nxt, leaf;
    state(int p = 0) : leaf(0), link(p), nxt(mxc, 0) {}
};
vector<state> trie; // must clear and emplace back

// Define child value
int get_child(char ch)
{
    return ch - 'a';
}

// Adding patterns which need to search from text
void add(string &word, int idx)
{
    int u = 0;
    for (char &ch : word)
    {
        int c = get_child(ch);
        if (!trie[u].nxt[c])
        {
            trie[u].nxt[c] = trie.size();
            trie.emplace_back();
        }
        u = trie[u].nxt[c];
    }
    trie[u].leaf.push_back(idx);
}

void build()
{
    queue<int> q;
    for (int i = 0; i < mxc; i++)
    {
        int u = trie[0].nxt[i];
        if (u)
        {
            q.push(u);
            trie[u].link = 0;
        }
    }

    while (!q.empty())
    {
        int u = q.front();
        q.pop();
        for (int i = 0; i < mxc; i++)
        {
            if (trie[u].nxt[i])
            {
                int v = trie[u].link;
                while (v && !trie[v].nxt[i])
                    v = trie[v].link;

                v = trie[v].nxt[i];
                trie[trie[u].nxt[i]].link = v;

                for (int &id : trie[v].leaf)
                {
                    trie[trie[u].nxt[i]].leaf.push_back(id);
                }
                q.push(trie[u].nxt[i]);
            }
        }
    }
}

int findNext(int u, int c)
{
    while (u && !trie[u].nxt[c])
    {
        u = trie[u].link;
    }
    return trie[u].nxt[c];
}

int ans[mx];
int resLine, res;
int patLine;
void search(string &text, int lineNo)
{
    int u = 0;
    bool started = false;
    for (int i = 0; i < text.size(); i++)
    {
        char ch = text[i];
        if (ch < 'a' || ch > 'z')
            continue;
        int c = get_child(ch);
        u = findNext(u, c);
        for (int &v : trie[u].leaf)
        {

            if (resLine == 0)
            {
                started = true;
                resLine = lineNo;
                res = i + 1;
                patLine = v;
            }
        }
    }
}

void Main(int kase)
{
    trie.clear();
    trie.emplace_back();

    int n;
    cin >> n;
    cin.ignore();
    string pat[n + 3];
    for (int i = 0; i < n; i++)
    {

        cin >> pat[i];
        cin.ignore();
        add(pat[i], i);
        ans[i] = 0;
    }
    build();

    int totalLine;
    cin >> totalLine;
    cin.ignore();
    for (int i = 0; i < totalLine; i++)
    {
        string text;
        getline(cin, text);
        // cin.ignore();

        // cout << text << endl;
        search(text, i + 1);
    }
    if (resLine == 0)
    {
        cout << "Passed\n";
    }
    else
    {
        cout << resLine << " " << res - pat[patLine].size() + 1 << endl;
    }
}

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(nullptr);
    int tc = 1;
    // cin >> tc;
    for (int i = 1; i <= tc; i++)
    {
        Main(i);
    }
    return 0;
}

/*"Success isn't permanent, failure isn't fatal,
                                     it's the courage to continue that counts"*/
