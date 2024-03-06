#include <bits/stdc++.h>
using namespace std;

int main()
{
    int a=66;
    int b=66;
    for(int i=2;i<=700;i++){
        int c=b;
        b=a+b%1000000007;
        a=c;
    }
    cout<<b<<endl;
}
