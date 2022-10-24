#include <bits/stdc++.h>
using namespace std;
#define ll long long int
#define sz 1000006
int ct[sz];
int isgcd[sz];

int main()
{
    int n;
    cin>>n;
    for(int i=0;i<n;i++)
    {
        int x;cin>>x;
        ct[x]++;
    }
    int res=0;
    for(int i=1;i<=1000000;i++)
    {
        for(int j=i;j<=1000000;j+=i)
        {
            if(ct[j])
            {
                isgcd[i]=__gcd(isgcd[i],j);
            }
        }

        if(isgcd[i]==i)res++;
    }

    cout<<res-n<<endl;
    return 0;
}
