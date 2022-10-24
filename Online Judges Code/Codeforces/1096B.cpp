#include <bits/stdc++.h>
using namespace std;
#define int long long int
int32_t main()
{
    int n;
    cin>>n;
    string st;
    cin>>st;
    string fromFirst,fromLast;
    for(int i=0;i<n-1;i++)
    {
        if(st[i]==st[i+1])fromFirst.push_back(st[i]);

        else {
            fromFirst.push_back(st[i]);
            break;
        }
    }

    for(int i=n-1;i>0;i--)
    {
        if(st[i]==st[i-1])fromLast.push_back(st[i]);

        else {
            fromLast.push_back(st[i]);
            break;
        }
    }


    int ff=fromFirst.size();
    int fl=fromLast.size();




    if(fromFirst[0]==fromLast[0])
    {
        cout<<((ff+1)*(fl+1))%998244353<<endl;
    }
    else {
        cout<<(ff+fl+1)<<endl;
    }


}
