#include <bits/stdc++.h>
using namespace std;
#define ll long long int

int main()
{
    ll n,a,b,p,q,r,s;cin>>n>>a>>b>>p>>q>>r>>s;


    ll x1,x2,y1,y2;

    ll minK=max(1-a,1-b);

    ll maxK=min(n-a,n-b);

    bool firstOk=false,secondOk=false;
    if(minK<=maxK)firstOk=true;

    x1=a+minK;
    y1=b+minK;

    ll mink2=max(1-a,b-n);
    ll maxk2=min(n-a,b-1);

    if(mink2<=maxk2)secondOk=true;
    x2=a+mink2;
    y2=b-mink2;

    for(ll i=p;i<=q;i++)
    {
        for(ll j=r;j<=s;j++)
        {
            if(firstOk==true && x1-y1==i-j){
                cout<<"#";
            }
            else if(secondOk==true && x2+y2==i+j)
            {
                cout<<"#";
            }
            else {
                cout<<".";
            }
        }

        cout<<endl;
    }


}
