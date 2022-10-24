#include <bits/stdc++.h>
using namespace std;
#define ll long long int
#define pb push_back
map<pair<int,int>,int>mp;
map<pair<int,int>,pair<int,int>>res;
vector<pair<int,int>>vec;
int dx[] = {0, 0, -1, 1};
int dy[] = {-1, 1, 0, 0};



void solve()
{
    int u,v;
    int n;
    cin>>n;
    for(int i=0; i<n; i++)
    {
        cin>>u>>v;
        vec.pb({u,v});
        mp[ {u,v}]=1;
    }


    queue<pair<int,int>>q;

    for(int i=0; i<n; i++)
    {
        int x=vec[i].first, y=vec[i].second;

        for(int j=0; j<4; j++)
        {
            int nx=x+dx[j];
            int ny=y+dy[j];
            if(mp[{nx,ny}]!=0)
            {

                continue;
            }
                q.push({x,y});

                res[{x,y}]= {nx,ny};
                break;
        }
    }






    while(!q.empty())
    {
        pair<int,int>f=q.front();
        q.pop();


        for(int i=0; i<4; i++)
        {
            int nx=f.first+dx[i];
            int ny=f.second+dy[i];
            pair<int,int>np={nx,ny};

            if(mp[np]==0 || res.count(np))
            {

                continue;
            }
               //cout<<"adding to res : "<<f.first<<" "<<f.second<<endl;
                res[np]=res[f];
                q.push(np);
        }

    }


    for(int i=0;i<n;i++)
    {

       // cout<<"res : ";
        cout<<res[vec[i]].first<<" "<<res[vec[i]].second<<endl;
    }

}

int main()
{
    int tc=1;
    //cin>>tc;
    for(int i=1; i<=tc; i++)
    {
        solve();
    }

    return 0;
}
