#include <bits/stdc++.h>
using namespace std;
#define int long long
#define all(a) a.begin(), a.end()
#define pb push_back
#define nl printf("\n")
void solve()
{
    int na, n, q;
    cin >> na >> n >> q;
    int res = 0;
    vector<int> ar, dis;
    ar.push_back(0);
    for (int i = 0; i < n; i++)
    {
        int v;
        cin >> v;
        ar.push_back(v);
    }
    // print_v(ar);
    dis.push_back(0);
    for (int i = 0; i < n; i++)
    {
        int v;
        cin >> v;
        dis.push_back(v);
    }

    vector<pair<int, int>> vec;
    for (int i = 0; i < q; i++)
    {
        int v;
        cin >> v;
        vec.push_back({v, i});
    }
    int allRes[q + 2];
    sort(all(vec));
    int soFar = 0;
    int cur = 0;
    for (int i = 0; i < n && cur < q; i++)
    {
        if (soFar + (ar[i + 1] - ar[i]) < vec[cur].first)
        {
            soFar += (ar[i + 1] - ar[i]);
            res += (dis[i + 1] - dis[i]);
        }
        else
        {
            int lagbe = vec[cur].first - soFar;
            int rng = ar[i + 1] - ar[i];
            int timeLage = dis[i + 1] - dis[i];
            int hobe = (timeLage * lagbe) / rng;
            allRes[vec[cur].second] = res + hobe;
            i--;
            cur++;
        }
    }
    for (int i = 0; i < q; i++)
    {
        cout << allRes[i] << " ";
    }
    cout << endl;
}

int32_t main()
{
    int tc = 1;
    cin >> tc;
    for (int i = 1; i <= tc; i++)
    {
        solve();
    }
    return 0;
}
