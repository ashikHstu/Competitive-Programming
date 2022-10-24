#include <bits/stdc++.h>
using namespace std;
#define ll long long int

//struct data
//{
//    int u,v,w;
//    data(int _u,int _v,int _w)
//    {
//        u=_u;
//        v=_v;
//        w=_w;
//    }
//
//
//};
//
//
//
//int parent[100005];
//void assignParent(int n)
//{
//    for(int i=0;i<=n;i++)parent[i]=i;
//}
//
//int findParent(int n)
//{
//    if(parent[n]==n)return n;
//    else return parent[n]=findParent(parent[n]);
//}
//
//
//vector<data>vec;
//
//
//
//void solve()
//{
//    ll n,m;cin>>n>>m;
//    vec.clear();
//
//
//    for(int i=0;i<m;i++)
//    {
//        int u,v,w;
//        cin>>u>>v>>w;
//        vec.push_back(data(u,v,w));
//    }
//    ll res=1;
//    res=res<<30;
//    res--;
//
//   // cout<<"initial res : "<<endl;
//    for(int i=30;i>=0;i--)
//    {
//        int connect=0;
//        assignParent(n);
//        for(int j=0;j<m;j++)
//        {
//            int v=vec[j].v;
//            int u=vec[j].u;
//            int w=vec[j].w;
//
//            if(w&(1<<i))
//            {
//
//                continue;
//            }
//            int p1=findParent(u);
//            int p2=findParent(v);
//            if(p1!=p2)
//            {
//                parent[p1]=p2;
//                connect++;
//            }
//
//        }
//        if(connect==n-1)
//        {
//            res=res^(1<<i);
//            cout<<"ever connected?, updated res : "<<res<<endl;
//        }
//        else {
//           // cout<<"not connected at : "<<i<<endl;
//        }
//
//
//
//    }
//
//    cout<<res<<endl;
//
//
//
//
//}

int main()
{
    int tc;cin>>tc;

    while(tc--)
    {
        //solve();
    }

    return 0;
}
