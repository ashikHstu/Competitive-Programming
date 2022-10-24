#include <bits/stdc++.h>
using namespace std;
#define ll long long int
#define pb push_back

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

void solve()
{
    string st;
    cin >> st;
    int n;
    cin >> n;
    string p[n + 2];
    vector<pair<int, int>> is;
    for (int i = 0; i < n; i++)
    {
        cin >> p[i];
        is.pb({p[i].size(), i});
    }

    sort(all(is));
    reverse(all(is));
    // cout << "pair : " << endl;
    // for (int i = 0; i < n; i++)
    // {
    //     cout << p[is[i].second] << " ";
    // }
    // cout << endl;

    vector<pair<int, int>> res;
    int cur = 0;

        bool hoiche = false;
        pair<int, int> rr = {-1, -1}, frr = {-1, -1};
        ll newCur = 0, tCur = 0;
    for (int j = 0; j < st.size(); j++)
    {
        for (int i = 0; i < n; i++)
        {
            int ln = p[is[i].second].size();
            // cout << "c chek : " << st.substr(j, ln) << ", " << p[is[i].second] << endl;
            if (j + ln <= st.size() && st.substr(j, ln) == p[is[i].second] && j + ln > cur)
            {

                rr = {j + 1, is[i].second};
                tCur = j + ln;

                hoiche = true;
                break;
            }
        }

      //  cout<<"cur at "<<j<<" : "<<cur<<endl;

        if (!hoiche && j >= cur)
        {
          
           // cout << "discarded At : " << j << endl;
            cout << "-1\n";
            return;
        }


        if (frr.first == -1 && hoiche)
        {
           // cout<<"koitte vai?"<<endl;
            frr = rr;
            newCur = tCur;
        }
        else if (newCur < tCur)
        {
          //  if(j==2)cout<<"new cur : t cur : :"<<newCur<<", "<<tCur<<endl;
            frr = rr;
            newCur = tCur;
        }

  

        if (j == cur )
        {
            res.pb(frr);
            cur = newCur;
            hoiche=false;
           rr= frr={-1,-1};
           newCur=tCur=0;
            
        }

     
        
    }

    if (cur < st.size())
    {
        cout << "NO\n";
       // cout << "kahini bujhcho?'\n";
    }

    cout << res.size() << endl;
    for (int i = 0; i < res.size(); i++)
    {
        cout << res[i].second + 1 << " " << res[i].first << endl;
    }
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
