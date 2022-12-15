#include <bits/stdc++.h>
using namespace std;

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

int main()
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

    string temp;
    vector<bool> temp2;
    // t.print(0, temp2, temp);

    return 0;
}