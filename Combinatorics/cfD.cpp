#include <bits/stdc++.h>
using namespace std;
#define ll long long int
void solve()
{
    int x;cin>>x;
    vector<int>res;
    int ct=0;
    while(x>0)
    {
        if(x%2==0)
        {
            res.push_back(ct+1);


        }
        x/=2;
        ct++;
    }

    int sz=res.size();
    cout<<sz<<endl;


    for(int i=sz-1;i>=0;i--)cout<<res[i]<<" ";cout<<endl;


}

int main()
{
    int tc=1;
    //cin>>tc;
    for(int i=0;i<tc;i++)
    {
        solve();
    }

    return 0;
}


/**

Input :
1
21
0 0 3 2 9 6 15 16 17 9 20 10 21 21 21 6 5 4 3 21 1


Output :
0 0 1 0 1 0 1 1 1 0 1 0 1 1 1 0 0 0 0 1 0

*/
