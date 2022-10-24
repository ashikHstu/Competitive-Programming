
///Problem Link : https://www.spoj.com/problems/AMR11E/
#include <bits/stdc++.h>
using namespace std;

vector<int>res;

void precalculate()
{
    res.push_back(0);
    for(int i=2;i<=3000;i++)
    {
        int num=i;
        int ct=0;
        for(int j=2;j<=i;j++)
        {
            if(num%j==0)
            {
                ct++;
                while(num%j==0)num/=j;
            }
        }

        if(ct>=3)res.push_back(i);
    }
}

int main()
{
    precalculate();

    //cout<<res.size()<<endl;
    int tc;cin>>tc;
    for(int i=1;i<=tc;i++)
    {
        int n;cin>>n;
        cout<<res[n]<<endl;
    }

    return 0;
}
