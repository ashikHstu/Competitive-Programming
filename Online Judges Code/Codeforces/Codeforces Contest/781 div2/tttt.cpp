#include <bits/stdc++.h>
using namespace std;
int main()
{
    int a=50;
    int &b=a;
    a=100;
    b=50;
    cout<<a<<" "<<--b<<endl;

}
