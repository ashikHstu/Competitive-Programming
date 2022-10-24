#include <bits/stdc++.h>
using namespace std;
#define ll long long int


int main()
{
    ll n;
cin>>n;
    ll res=0;
    if(n==1)
    {
        cout<<"1\n";
        return 0;
    }
//
//    ll left=1,right=n;
//
//    ll sq=sqrt(n)+1;
//
//    for(ll i=2;i<=sq && left<right;i++)
//    {
//        if(n%i==0)
//        {
//            ll d2=n/i;
//
//            if(i==d2)
//            {
//                cout<<"eq found \n";
//
//
//                res+=(i-left-1)*(i-1);
//                res+=(right-i)*i;
//                 left=right;
//                 left++;right--;
//            }
//            else {
//                res+=(i-left-1)*(d2-1);
//                res+=(d2);
//                left=i;
//                res+=(right-d2)*(i);
//                right=d2;
//
//            }
//        }
//    }
//
//    cout<<"pre res : "<<res<<endl;
//    if(left<right)
//    {
//        res+=(right-left-1)*(n/left);
//    }
//
//    cout<<"res : ";

ll sq=(double)sqrt(n)+0.011;

ll limit=sq;

for(ll i=1;i<=limit;i++)
{
    res+=((n/i)-(n/(i+1)))*i;
}

for(ll i=1;i<=(n/(limit+1));i++)res+=(n/i);


//cout<<"res : ";
    cout<<res<<endl;

    return 0;
}
