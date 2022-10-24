#include <bits/stdc++.h>
using namespace std;
int main()
{
    int n;cin>>n;
    set<int>s;
    int res=0;
    for(int i=0;i<n*2;i++)
    {
        int v;cin>>v;
        if(s.count(v))
        {
            s.erase(v);
        }
        else s.insert(v);
        int ache=s.size();

        res=max(res,ache);
    }

    cout<<res<<endl;
    return 0;

}
