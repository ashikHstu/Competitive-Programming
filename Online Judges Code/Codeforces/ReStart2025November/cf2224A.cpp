#include <bits/stdc++.h>
using namespace std;

void solve()
{
    int n;
    cin>>n;
    vector<int>vec(n);
    for(int &v:vec)cin>>v;

    int res=0;
    int right=n-1;
    long long sum=0;
    for(int i=n-1;i>=0;i--)
    {
        sum+=vec[i];
        while(sum<0)
        {
            sum-=vec[right];
            right--;
        }
        if(sum>0)res++;
    }
    cout<<res<<endl;

}

int main()
{
    int tc;cin>>tc;
    while(tc--)solve();
}