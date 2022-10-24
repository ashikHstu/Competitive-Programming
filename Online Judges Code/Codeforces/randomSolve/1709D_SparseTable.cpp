#include <bits/stdc++.h>
using namespace std;
#define FasterIO          ios::sync_with_stdio(0);cin.tie(0);cout.tie(0)

#define maxN 200005
#define K 25
int Log[maxN+1];
int sparse_table[maxN][K+1];
int ar[maxN];
int N;

/// precomputing all logarithm
void calLog()
{
    Log[1]=0;
    for(int i=2; i<=maxN; i++)
        Log[i]=Log[i/2]+1;

}

void makeSparseMax()
{
    for(int i=0; i<N; i++)
    {
        sparse_table[i][0]=ar[i];
    }
    for(int j=1; j<=K; j++)
    {
        for(int i=0; i+(1<<j)<=N; i++)
        {
            sparse_table[i][j]=max(sparse_table[i][j-1],sparse_table[i+(1<<(j-1))][j-1]);
        }
    }
}

int findMax(int L,int R)
{
    int j=Log[R-L+1];
    int maximum=max(sparse_table[L][j],sparse_table[R-(1<<j)+1][j]);
    return maximum;
}


int main()
{
    FasterIO;
    calLog();
    int n,m;
    cin>>n>>m;
    N=m;
    for(int i=0; i<m; i++)cin>>ar[i];

    makeSparseMax();



    int q;
    cin>>q;
    for(int i=0; i<q; i++)
    {


        int xs,ys,xd,yd,k;
        cin>>xs>>ys>>xd>>yd>>k;

        if(abs(xd-xs)%k!=0 || abs(yd-ys)%k!=0)
        {

            cout<<"NO\n";
           // cout<<"not div fault"<<endl;
            continue;
        }

        int ex=(n-xs)/k;
        int cur=xs+(ex*k);
        int mx;
        if(ys<yd)
        {
            mx=findMax(ys-1,yd-1);

        }
        else
        {
            mx=findMax(yd-1,ys-1);
        }

        if(mx<cur)
        {
            cout<<"YES\n";
        }
        else
        {
        //    cout<<"mx : cur :: "<<mx<<", "<<cur<<endl;
            cout<<"NO\n";
        }

    }

}
