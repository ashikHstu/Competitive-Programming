#include <bits/stdc++.h>
using namespace std;
#define pb push_back
int main()
{
    map<string, vector<int>> mp;

    for (int i = 0; i < 10; i++)
    {
        string st;
        cin >> st;
        mp[st].pb(i);
    }
    for (auto it = mp.begin(); it != mp.end(); it++)
    {
        cout << it->first << " : ";
        for (int i = 0; i < it->second.size(); i++)
        {
            cout << it->second[i] << " ";
        }
        cout << endl;
    }
}