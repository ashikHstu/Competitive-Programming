#include <bits/stdc++.h>
using namespace std;
#define ll long long int


int bestCandidate(vector<int>vec,int v)
{
    int pos=-1;
    ll minD=1000000000000000000ll;

    for(int i=0;i<vec.size();i++)
    {
        if(abs(vec[i]-v)<minD)
        {
            pos=i;
            minD=abs(vec[i]-v);
        }
    }

    return pos;
}


void solve()
{
   int n;
   cin>>n;
   vector<int>a(n),b(n);

   for(int i=0;i<n;i++)cin>>a[i];
   for(int i=0;i<n;i++)cin>>b[i];


 vector<int>forA0={0,bestCandidate(b,a[0]),n-1};
 vector<int>forNMinusOne={0,bestCandidate(b,a[n-1]),n-1};

 ll res=10000000000000000ll;
 for(int ind1:forA0)
 {
     for(int ind2:forNMinusOne)
     {
         ll temp=abs(a[0]-b[ind1])+abs(a[n-1]-b[ind2]);

         if(ind2>0 and ind1>0)
         {
             temp+=(abs(b[0]-a[bestCandidate(a,b[0])]));
         }
         if(ind1<n-1 && ind2<n-1)
         {
             temp+=(abs(b[n-1]-a[bestCandidate(a,b[n-1])]));
         }

         res=min(res,temp);
     }
 }


 //cout<<"res : ";
 cout<<res<<endl;

}

int main()
{
    int tc=1;
    cin>>tc;
    for(int i=1;i<=tc;i++)
    {
        solve();
    }

    return 0;
}

