#include <bits/stdc++.h>
using namespace std;

void solve()
{
    long long n;
    cin>>n;

    long long dn=n/12;
   // cout<<"preD: "<<dn<<endl;
    long long d=dn*12;
    int ex=n%12;
   // cout<<"ex: "<<ex<<", d: "<<d<<endl;
    if(ex==10){
        if(dn>0){
            d-=12;
            ex+=12;
        }
        else{
            cout<<"-1\n";
            return;
        }
    }
    cout<<ex<<" "<<d<<endl;  
}

int main()
{
    int tc;cin>>tc;
    while(tc--)solve();
}