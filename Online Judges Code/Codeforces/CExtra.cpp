/** Success is not a destination, success is a journey */

#include <bits/stdc++.h>
using namespace std;

/*
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
using namespace __gnu_pbds;

typedef tree<
int,
null_type,
less_equal<int>,
rb_tree_tag,
tree_order_statistics_node_update> ordered_set;
*/




#define FasterIO          ios::sync_with_stdio(0);cin.tie(0);cout.tie(0)
#define TIME              clock()*1.0/CLOCKS_PER_SEC
#define pi                acos(-1.0)
///Library
#define mem(a,b)           memset(a,b,sizeof(a))
#define all(a)             a.begin(),a.end()

#define pb                 push_back
#define ll long long int

/*----------------------Graph Moves----------------*/
//const int fx[]={+1,-1,+0,+0};
//const int fy[]={+0,+0,+1,-1};
//const int fx[]={+0,+0,+1,-1,-1,+1,-1,+1};   // Kings Move
//const int fy[]={-1,+1,+0,+0,+1,+1,-1,-1};  // Kings Move
//const int fx[]={-2, -2, -1, -1,  1,  1,  2,  2};  // Knights Move
//const int fy[]={-1,  1, -2,  2, -2,  2, -1,  1}; // Knights Move
/*------------------------------------------------*/

vector<int>allElement;

void makeRes()
{
   allElement.pb(1);
   ll sq=sqrt(1000000000+1);
    map<ll,ll>mp;
   for(ll i=2;i<=sq;i++)
   {
       ll v=i*i;
       if(v<=1000000000 && mp[v]==0)
       allElement.pb(v);
       v*=i;
       if(v<=1000000000 && mp[v]==0)
        allElement.pb(v);

        mp[v]++;



   }

   sort(all(allElement));

}


void solve()
{
    int n;cin>>n;

    int r=upper_bound(allElement.begin(),allElement.end(),n)-allElement.begin();

    //cout<<"res : ";
    cout<<r<<endl;
}


int main()
{
    makeRes();
    int tc;cin>>tc;
    while(tc--)solve();
}






/*"Success isn't permanent, failure isn't fatal,
                                     it's the courage to continue that counts"*/


