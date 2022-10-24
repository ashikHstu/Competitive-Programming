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

/*----------------------Graph Moves----------------*/
//const int fx[]={+1,-1,+0,+0};
//const int fy[]={+0,+0,+1,-1};
//const int fx[]={+0,+0,+1,-1,-1,+1,-1,+1};   // Kings Move
//const int fy[]={-1,+1,+0,+0,+1,+1,-1,-1};  // Kings Move
//const int fx[]={-2, -2, -1, -1,  1,  1,  2,  2};  // Knights Move
//const int fy[]={-1,  1, -2,  2, -2,  2, -1,  1}; // Knights Move
/*------------------------------------------------*/








int parent[500001];

int findParent(int i)
{
    if(parent[i]==i)return i;
    else return parent[i]=findParent(parent[i]);
}

void makeParent()
{
   for(int i=0;i<=500000;i++)parent[i]=i;
}

int main()
{
   makeParent();

   int q;cin>>q;

   vector<int>ar;

   int k=0;
   int vec[q+1][3];

   for(int i=0;i<q;i++)
   {
      cin>>vec[i][0]>>vec[i][1];

      if(vec[i][0]==2){
       cin>>vec[i][2];
      }
   }


   //reverse(all(vec));

   for(int i=q-1;i>=0;i--)
   {

       if(vec[i][0]==1)
       {
           ar.pb(parent[vec[i][1]]);
       }
       else {
        parent[vec[i][1]]=parent[vec[i][2]];
       }
   }

   reverse(all(ar));

   for(auto value:ar)cout<<value<<" ";cout<<endl;


}



/*"Success isn't permanent, failure isn't fatal,
                                     it's the courage to continue that counts"*/


