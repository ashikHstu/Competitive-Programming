#include <bits/stdc++.h>
using namespace std;
int main()
{
    string st;cin>>st;
    int len=st.size();
    int res=(len+1)*26;
    res-=len;
    cout<<res<<endl;
    return 0;
}
