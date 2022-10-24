#include <bits/stdc++.h>
using namespace std;
int main()
{
    int n,p;cin>>n>>p;
int res=0;
     for(int i=0;i<n;i++)
     {
         int v;
         cin>>v;
         if(v<p)res++;
     }

     cout<<res<<endl;
     return 0;
}

