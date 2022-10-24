#include<bits/stdc++.h>
using namespace std;
void solve()
{
     long long int i,j,k,l,n,m,s,sum1,sum2,t,csum;

cin>>n>>m>>t;
long long int arr[n];

for(i=1;i<=n-1;i++){
   cin>>arr[i];
}
long long int xx[m+1],yy[m+1];
for(j=1;j<=m;j++){
    cin>>xx[j]>>yy[j];
}
sum1=0,sum2=0,csum=arr[1];
for(j=1;j<=n-1;j++){
    sum1+=arr[j];
}

for(k=1;k<=m;k++){
    sum2+=yy[k];
}

for(k=1;k<=m;k++){
    arr[xx[k]]-=yy[k];
}

for(k=2;k<=n-2;k++){
    csum+=arr[k];

    if(csum>t){cout<<"No"<<endl;return;}
}


if(sum1-sum2<t){cout<<"Yes"<<endl;}
else{cout<<"No"<<endl;}

}


int main()
{

    long long int it,tc;

    for(it=1;it<=1;it++){
        solve();
    }
return 0;

}
