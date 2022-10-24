#include <bits/stdc++.h>
using namespace std;
int main()
{
    int n;cin>>n;
    deque<int>q;
    q.push_front(360);

    while(n--)
    {
        int v;cin>>v;
        while(q.front()<v)
        {
            v-=q.front();
            q.push_back(q.front());
            q.pop_front();

        }
        int f=q.front();
        q.pop_front();
        q.push_back(v);
        q.push_front(f-v);

    }

    int mx=0;
    while(!q.empty())
    {
        mx=max(mx,q.front());
        q.pop_front();
    }

    cout<<mx<<endl;

    return 0;
}
