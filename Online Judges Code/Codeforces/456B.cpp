#include <bits/stdc++.h>
using namespace std;


bool isDivisible(string st,int n)
{
    int len=st.size();
    int cur=0;
    for(int i=0;i<len;i++)
    {
        cur*=10;
        cur+=(st[i]-'0');
        cur%=4;
    }

    if(cur==0)return true;
    return false;
}

int main()
{
    string st;
    cin>>st;

    if(isDivisible(st,4))
    {
        cout<<"4\n";
    }
    else cout<<"0\n";

    return 0;

}
