#include <bits/stdc++.h>
using namespace std;
mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());
int my_rand(int l, int r) {
    return uniform_int_distribution<int>(l, r) (rng);
}

int main()
{
  int tc=my_rand(1,3);

  cout<<tc<<endl;
  for(int i=1;i<=tc;i++)
  {
     int n=my_rand(5,10);
     int m=my_rand(1,n);
     cout<<n<<" "<<m<<endl;
     for(int j=0;j<n;j++)
     {
         int v=my_rand(-30,30);
         cout<<v<<" ";
     }
     cout<<endl;


  }

    return 0;
}

