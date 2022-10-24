#include <bits/stdc++.h>
using namespace std;
int main()
{
    string st;cin>>st;

    string m=st;
    string mx=st;
    int n=st.size();

    for(int i=1;i<n;i++)
    {
        string temp;
        for(int j=i;j<n;j++)
        {
            temp.push_back(st[j]);
        }
        for(int j=0;j<i;j++)
            temp.push_back(st[j]);

        if(temp<m)m=temp;
        if(temp>mx)mx=temp;
    }

    cout<<m<<endl;
    cout<<mx<<endl;

    return 0;
}
