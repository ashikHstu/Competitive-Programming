#include <bits/stdc++.h>
using namespace std;
mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());
int my_rand(int l, int r) {
    return uniform_int_distribution<int>(l, r) (rng);
}

int main()
{
  int tc=my_rand(1,5);
  cout<<tc<<endl;
  for(int i=1;i<=tc;i++)
  {
      int a=my_rand(1,5);
    cout<<a<<endl;
    vector<int>va,vb;
       for(int j=0;j<a;j++)
       {

           int v=my_rand(1,10);
           va.push_back(v);
       }
       for(int j=0;j<a;j++)
       {
           int v=my_rand(1,10);
           vb.push_back(v);
       }

       sort(va.begin(),va.end());
       sort(vb.begin(),vb.end());
       for(int v:va)cout<<v<<" ";cout<<endl;
       for(int v:vb)cout<<v<<" ";cout<<endl;

  }

    return 0;
}

