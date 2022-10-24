#include <bits/stdc++.h>
using namespace std;
int ct[1000006];
long long int a[1000006];
long long int exact[1000006];
int main()
{
    int n;
    cin>>n;
    map<int,int>mp;
    for(int i=0;i<n;i++)
    {
        int v;cin>>v;
        mp[v]++;
        ct[v]++;
    }

    for(int i=1;i<=1000000;i++)
    {
        for(int j=i;j<=1000000;j+=i){
            a[i]+=ct[j];
        }

        a[i]=(a[i]*(a[i]-1))/2;
    }
int res=0;
    for(int i=1000000;i>=1;i--)
    {
        exact[i]=a[i];

        for(int j=i+i;j<=1000000;j+=i)
        {
            exact[i]-=exact[j];
        }

        if(exact[i]>0 && mp[i]==0)
        {
            mp[i]++;
            res++;
        }
    }

    cout<<res<<endl;

    return 0;


}
