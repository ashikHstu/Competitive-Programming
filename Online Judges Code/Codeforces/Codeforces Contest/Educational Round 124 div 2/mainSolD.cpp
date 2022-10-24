#include <bits/stdc++.h>

using namespace std;

int dx[] = {0, 0, -1, 1};
int dy[] = {-1, 1, 0, 0};

int main()
{

    int n;
    scanf("%d", &n);
    vector<pair<int, int>> a(n);
    for(int i=0; i<n; i++)
    {
        cin>>a[i].first;
        cin>>a[i].second;
    }
    // for (auto &[x, y] : a) scanf("%d %d", &x, &y);

    set<pair<int, int>> st(a.begin(), a.end());
    map<pair<int, int>, pair<int, int>> ans;
    queue<pair<int, int>> q;
    for (int jj=0; jj<n; jj++)
    {
        int x=a[jj].first;
        int y=a[jj].second;

        for (int i = 0; i < 4; ++i)
        {
            int nx = x + dx[i], ny = y + dy[i];
            if (st.count({nx, ny}))
            {
                continue;
            }
           // cout<<"adding to queue"<<endl;
            cout<<x<<" , "<<y<<" : "<<nx<<" , "<<ny<<endl;
            ans[ {x, y}] = {nx, ny};
            q.push({x, y});
            break;
        }
    }

    while (!q.empty())
    {
        int x = q.front().first, y = q.front().second;
        q.pop();
        for (int i = 0; i < 4; ++i)
        {
            int nx = x + dx[i], ny = y + dy[i];
            cout<<"cheking : "<<nx<<" , "<<ny<<endl;
            if (!st.count({nx, ny}) || ans.count({nx, ny}))
            {
                continue;
            }

            cout<<"adding exra?"<<endl;
            ans[ {nx, ny}] = ans[ {x, y}];
            q.push({nx, ny});
        }
    }
    for (int jj=0; jj<n; jj++)
    {
        int x=a[jj].first;
        int y=a[jj].second;
        auto it = ans[ {x, y}];
        printf("%d %d\n", it.first, it.second);
    }

    return 0;
}
