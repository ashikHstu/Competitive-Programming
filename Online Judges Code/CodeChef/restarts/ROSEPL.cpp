#include <bits/stdc++.h>
using namespace std;
#define int long long 

int KoitaPossible(int nibo, int K,int M)
{
    int possible=(M+1)/(K+1);
    return min(possible,nibo);
}

int min3(int a,int b,int c)
{
    return min(a,min(b,c));
}

void solve()
{
    int N,M,K;
    cin>>N>>M>>K;
    vector<int>vec;
    for(int i=0;i<N;i++)
    {
        int a;
        cin>>a;
        vec.push_back(a);
    }

    sort(vec.begin(),vec.end());
    reverse(vec.begin(),vec.end());
    int res=0;

    for(int i=0;i<N;i++)
    {
        if(M<=0)break;
        if(vec[i]>K)
        {
            int nibo=vec[i]/K;
            int koitaPossible=KoitaPossible(nibo,K,M);
            res+=(koitaPossible*K);
            M-=(koitaPossible*(K+1));
            vec[i]-=(koitaPossible*K);
        }
    }

    sort(vec.begin(),vec.end());
    reverse(vec.begin(),vec.end());

    for(int i=0;i<N;i++)
    {
        if(M<=0)break;
        int ex1=min3(vec[i],M,K);
        M-=(ex1+1);
        res+=ex1;

    }

    cout<<res<<endl;
}

int32_t main()
{
    int tc;cin>>tc;
    while(tc--)solve();

    return 0;
}