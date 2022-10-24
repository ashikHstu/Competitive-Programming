#include <bits/stdc++.h>
using namespace std;
#define ll long long int
int main()
{
    ll range,need;cin>>range>>need;

    ll left=1,right=range;

    ll res=0;

    while(left<=right)
    {
        if(left==right)
        {
            cout<<res<<endl;
            return 0;
        }

        ll mid=left+((right-left)/2);

        if(need>mid)
        {
            left=mid+1;
        }
        else {
            right=mid;
        }
        res++;

    }

}
