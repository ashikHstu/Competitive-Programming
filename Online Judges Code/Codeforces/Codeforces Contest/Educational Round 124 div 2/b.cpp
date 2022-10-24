#include <bits/stdc++.h>
using namespace std;
#define ll long long int
ll mx=1000000000;
void solve()
{
  vector<int>res;
  ll ct=1;
  int n;cin>>n;
  for(int i=1;i<=n;i++)
  {
      if(ct>mx){
        cout<<"NO\n";
        return;
      }
      res.push_back(ct);
      ct=ct*3;

  }
cout<<"YES\n";
  for(int v:res)cout<<v<<" ";cout<<endl;

}

int main()
{
    int tc=1;
    cin>>tc;
    for(int i=1;i<=tc;i++)
    {
        solve();
    }

    return 0;
}


