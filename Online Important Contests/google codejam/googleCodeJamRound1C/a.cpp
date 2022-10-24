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

bool isValid(string st)
{
    int l = st.size();

    vector<int> vec[30];
    for (int i = 0; i < l; i++)
    {
        vec[st[i] - 'A'].push_back(i);
    }

    for (int i = 0; i < 26; i++)
    {
        for (int j = 1; j < vec[i].size(); j++)
        {
            if (vec[i][j - 1] + 1 != vec[i][j])
                return false;
        }
    }

    return true;
}

bool onlyOne(char ch, string st)
{
    for (char chh : st)
    {
        if (chh != ch)
            return false;
    }
    return true;
}

void solve(int kase)
{

    vector<int> onlyChar[27];
    vector<int> starting[27], ending[27];
    int n;
    cin >> n;
    string st[n + 2];
    bool ok = true;
    for (int i = 0; i < n; i++)
    {
        cin >> st[i];
        if (!isValid(st[i]))
            ok = false;
        bool onlyOk = false;
        for (int j = 0; j < 26; j++)
        {
            if (onlyOne('A' + j, st[i]))
            {
                onlyChar[j].push_back(i);
                onlyOk = true;
                break;
            }
        }
        if (!onlyOk)
        {
            int wl = st[i].size();
            starting[st[i][0] - 'A'].push_back(i);
            ending[st[i][wl - 1] - 'A'].push_back(i);
            if (starting[st[i][0] - 'A'].size() > 1)
                ok = false;
            if (ending[st[i][wl - 1] - 'A'].size() > 1)
                ok = false;
        }
    }
    if (!ok)
    {
        cout << "Case #" << kase << ": IMPOSSIBLE\n";
        return;
    }



    // cout<<"came here ? "<<endl;

    string res;

    for(int needOne=0; needOne<26; needOne++)
    {

        if (ending[needOne].size() != 0)
        {
            res = st[ending[needOne][0]];
            starting[res[0]-'A'].clear();
            ending[needOne].clear();
        }

        for (int i = 0; i < onlyChar[needOne].size(); i++)
        {
            res += st[onlyChar[needOne][i]];
        }
        int l22 = onlyChar[needOne].size();
        for (int i = 0; i < l22; i++)
        {
            onlyChar[needOne].clear();
        }

        if (starting[needOne].size() != 0)
        {
            res += (st[starting[needOne][0]]);
            ending[res[res.size()-1]-'A'].clear();
            starting[needOne].clear();
        }

        if(res.size()!=0)break;
    }
    //cout<<"came here? 2"<<endl;

    while (true)
    {
        bool done = false;
        int curStart = res[0] - 'A';
        int l22 = onlyChar[curStart].size();
        for (int i = 0; i < l22; i++)
        {
            res = st[onlyChar[curStart][i]] + res;
        }



            onlyChar[curStart].clear();


        if (ending[curStart].size() != 0)
        {
            res = st[ending[curStart][0]] + res;
            string tis=st[ending[curStart][0]];
            starting[tis[0]-'A'].clear();
            ending[curStart].clear();
            done = true;
        }

        if (!done)
            break;
    }


   // cout<<"came here 3 "<<endl;


    while (true)
    {
        bool done = false;
        int len_r = res.size();
        int curStart = res[len_r-1] - 'A';

        int l22 = onlyChar[curStart].size();

        for (int i = 0; i < l22; i++)
        {
            res = res + st[onlyChar[curStart][i]];
        }


            onlyChar[curStart].clear();


        if (starting[curStart].size() != 0)
        {
            res =res+ (st[starting[curStart][0]]);
            int resL=res.size();
            ending[res[resL-1]-'A'].clear();
            starting[curStart].clear();
            done = true;
        }

        if (!done)
            break;
    }

    //  cout<<"came here 4"<<endl;



    for(int i=0; i<26; i++)
    {
        if(starting[i].size()!=0){
                res+=(st[starting[i][0]]);

                int cL=res.size();
                   ending[res[cL-1]-'A'].clear();
        }
        starting[i].clear();
    }

    for(int i=0; i<26; i++)
    {
        if(ending[i].size()!=0)res+=(st[ending[i][0]]);
        ending[i].clear();
    }

    for(int i=0; i<26; i++)
    {
        if(onlyChar[i].size()!=0)
        {
            for(int j=0; j<onlyChar[i].size(); j++)
            {
                res+=(st[onlyChar[i][j]]);
            }
            onlyChar[i].clear();

        }

    }

    if(isValid(res))
    {
        cout<<"Case #"<<kase<<": "<<res<<endl;
        return;
    }
    cout << "Case #" << kase << ": IMPOSSIBLE\n";
    //cout<<"the res is : "<<res<<endl;



}

int main()
{
    int tc = 1;
    cin >> tc;
    for (int i = 1; i <= tc; i++)
    {
        solve(i);
    }

    return 0;
}
