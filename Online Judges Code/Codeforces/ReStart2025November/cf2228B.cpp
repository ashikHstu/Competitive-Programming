#include <bits/stdc++.h>
using namespace std;

void solve()
{
    int n;
    cin>>n;
    int x1,x2,k;
    cin>>x2>>x1>>k;
    if(n<4){
        cout<<"1\n";
        return;
    }
    int op1=abs(x1-x2);
    int op2=n-op1;
    cout<<min(op1,op2)+k<<endl;
}

int main()
{
    int tc;cin>>tc;
    while(tc--)solve();
}