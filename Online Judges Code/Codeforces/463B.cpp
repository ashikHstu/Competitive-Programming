#include <bits/stdc++.h>
using namespace std;


int main()
{
    int n;
    cin>>n;
    vector<long long int>ar(n+1);
    ar[0]=0;
    for(int i=1; i<=n; i++)
    {
        cin>>ar[i];
    }

    long long int res=0,sum=0;
    for(int i=1;i<=n;i++)
    {
        sum+=(ar[i]-ar[i-1]);
        res=max(res,sum);

    }

    cout<<res<<endl;

    return 0;

}

