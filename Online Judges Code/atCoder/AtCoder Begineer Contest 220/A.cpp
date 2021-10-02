#include <bits/stdc++.h>
using namespace std;
int main()
{
    int a,b;cin>>a>>b;
    int c;cin>>c;

    int d=b/c;
    int n=d*c;
    if(n>=a)
    {
        cout<<n<<endl;
    }
    else cout<<"-1\n";

    return 0;
}
