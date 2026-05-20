#include <bits/stdc++.h>
using namespace std;
#define int long long 

int KoitaPossible(int nibo, int K,int M)
{
    int possible=(M+1)/(K+1);
   // cout<<"possible, nibo: "<<nibo<<", "<<possible<<endl;
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
    //priority_queue<int>pq;
    vector<int>vec;
    for(int i=0;i<N;i++)
    {
        int a;
        cin>>a;
        vec.push_back(a);
       // pq.push(a);
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
           // cout<<"nibo, koita possible: "<<nibo<<", "<<koitaPossible<<endl;
            res+=(koitaPossible*K);
            M-=(koitaPossible*(K+1));
            vec[i]-=(koitaPossible*K);
        }
    }
   // cout<<"M, res: "<<M<<", "<<res<<endl;
    sort(vec.begin(),vec.end());
    reverse(vec.begin(),vec.end());

    for(int i=0;i<N;i++)
    {
        if(M<=0)break;
        int ex1=min3(vec[i],M,K);
        M-=(ex1+1);
        res+=ex1;

    }

    // while(true)
    // {
    //     int rose=pq.top();
    //     //cout<<"rose: "<<rose<<endl;
    //     pq.pop();

    //     int take=min(K,rose);
    //     take=min(take,M);
    //     if(take<=0)break;
    //     //cout<<"rose, take: "<<rose<<", "<<take<<endl;
    //     rose-=take;
    //     res+=take;
    //     M-=take;
    //     M-=1;
        
    //     pq.push(rose);
    // }
    cout<<res<<endl;
    
}

int32_t main()
{
    int tc;cin>>tc;
    while(tc--)solve();
}