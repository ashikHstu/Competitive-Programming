#include<bits/stdc++.h>
using namespace std;
void solve()
{
    long long int a,b,c,d,e,f,g,h,i,j,k,l,m,n,p,q,r,s,v,x,y,z;
    vector<int>vc;
    set<int>st;

    cin>>n>>m>>x>>y>>d;
    if((x-d)<=1 && (x+d>=n))
    {
        cout<<"-1"<<endl;
    }
    else if((y-d)<=1 && (y+d>=m))
    {
        cout<<"-1"<<endl;
    }
    else if((x-d)<=1 && (y+d>=m))
    {
        cout<<"-1"<<endl;
    }
    else if((x+d)>=n && (y+d>=m))
    {
        cout<<"-1"<<endl;
    }
    else
    {
        cout<<m+n-2<<endl;
    }
}



int main()
{

    long long int it,tc;
    cin>>tc;
    for(it=1; it<=tc; it++)
    {
        solve();
    }
    return 0;

}
