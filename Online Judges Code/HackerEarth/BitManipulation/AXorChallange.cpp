#include <bits/stdc++.h>
using namespace std;

#define isOn(S, j) (S & (1 << j))
#define setBit(S, j) (S |= (1 << j))
#define clearBit(S, j) (S &= ~(1 << j))
#define int long long int
int32_t main()
{
    int n;
    cin>>n;
    if(n==0)
    {
        cout<<"0\n";
        return 0;
    }
    int a=0,b=0;
    int lastOn=-1;
    for(int i=0;(1<<i)<=n;i++)
    {
        if(isOn(n,i))
        {
            setBit(b,i);
            lastOn=i;
        }
        else {
            setBit(a,i);
            setBit(b,i);
        }
    }
    if(lastOn!=-1)
    {
        clearBit(b,lastOn);
        setBit(a,lastOn);
    }


    cout<<(a*b)<<endl;
}
