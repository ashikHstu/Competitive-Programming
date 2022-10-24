#include <bits/stdc++.h>
using namespace std;
int main()
{
    string st[4];
    for(int i=0;i<4;i++)cin>>st[i];

    int ar[4];
    for(int i=0;i<4;i++)
    {
        ar[i]=st[i].size()-2;

    }

    vector<char>res;
    for(int i=0;i<4;i++)
    {
        bool okf=true;
        bool okb=true;
        for(int j=0;j<4;j++)
        {
            if(i==j)continue;
            if(ar[i]*2>ar[j])okf=false;
            if(ar[i]<ar[j]*2)okb=false;
        }
        if(okf || okb)
        {
            res.push_back('A'+i);
        }
    }

    if(res.size()==1)cout<<res[0]<<endl;
    else cout<<"C\n";

}
