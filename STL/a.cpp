#include <bits/stdc++.h>
using namespace std;
#define ll long long int
#define yes cout<<"YES\n";
#define no cout<<"NO\n";


void solve()
{
   int n,k;cin>>n>>k;

   int ct[50]={0};
   string st;cin>>st;
   for(int i=0;i<n;i++)
   {
       ct[st[i]-'a']++;
   }

   int oc=0;
   for(int i=0;i<26;i++)
   {
       if(ct[i]%2!=0)oc++;
   }

   if(oc>k)
   {
       int ex=oc-k;
       oc-=ex;
       n-=ex;
   }

//cout<<"res : ";
int res=n/k;
if(res%2==0 && oc>0)res=(n-oc)/k;
   cout<<res<<endl;



}

int main()
{
    int tc;cin>>tc;
    while(tc--)solve();

    return 0;
}
