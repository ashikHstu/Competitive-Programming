#include <bits/stdc++.h>
using namespace std;
void solve()
{

  int n;cin>>n;
  int ar[n+2];
  for(int i=0;i<n;i++)
  {
      cin>>ar[i];
  }

  if(ar[0]!=n && ar[n-1]!=n)
  {
      cout<<"-1\n";
      return;
  }

 list<int>vec;
  int last=n-1,first=0;
  if(ar[0]==n)
  {
      first++;
      vec.push_back(n);
  }
  else if(ar[n-1]==n)
  {
      last--;
      vec.push_back(n);
  }


  while(first<last)
  {
      vec.push_front(ar[first]);
      first++;
      vec.push_back(ar[last]);
      last--;
  }
  if(last==first)
    vec.push_back(ar[last]);


  for(auto it=vec.begin();it!=vec.end();it++)
  {
      cout<<*it<<" ";
  }cout<<endl;
  return;

}


int main()
{
    int tc;cin>>tc;
    while(tc--)solve();

    return 0;
}

