#include <bits/stdc++.h>
using namespace std;

void solve()
{
    int n;
    cin>>n;
    vector<int>vec(n);
    for(int &v:vec)cin>>v;
    sort(vec.rbegin(),vec.rend());

   for(int i=2;i<n;i++)
   {
    if(vec[i-2]%vec[i-1]!=vec[i]){
        cout<<"-1\n";
        return;
    }
   }
   cout<<vec[0]<<" "<<vec[1]<<endl;
   

}

int main()
{
    int tc;cin>>tc;
    while(tc--)solve();
}