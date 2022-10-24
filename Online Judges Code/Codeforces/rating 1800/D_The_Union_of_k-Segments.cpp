/**        بِسْمِ اللهِ الرَّحْمٰنِ الرَّحِيْمِ (In the name of God, the Most Gracious, the Most Merciful.)       */
/*
      Institution : Hajee Mohammad Danesh Science and Technology University,Dinajpur,Bangladesh.
      Name        : Ashikur Rahman Bhuyain (Asif)
      Email       : asifurr087@gmail.com
*/

#include <bits/stdc++.h>
using namespace std;



#define ll long long int


#define FasterIO          ios::sync_with_stdio(0);cin.tie(0);cout.tie(0)

#define mem(a,b)           memset(a,b,sizeof(a))
#define all(a)             a.begin(),a.end()

#define pb                 push_back

bool pairC(const pair<int,int> &a,
              const pair<int,int> &b)
{
    if(a.first==b.first)return a.second>b.second;
    return (a.first < b.first);
}



int main()
{
    FasterIO;
    int n,k;cin>>n>>k;
    map<int,int>mp,startAt,already;
    vector<int>starter;
    vector<pair<int,int>>vec,res;
   for(int i=0;i<n;i++)
   {
    int l,r;cin>>l>>r;
    vec.pb({l,+1});
    vec.pb({r,-1});
   }

   sort(vec.begin(),vec.end(),pairC);
   int cur=0;
   int left,right;
   for(int i=0;i<vec.size();i++)
   {
    int prev=cur;
    cur+=(vec[i].second);
    if(prev==k-1 && cur==k){
        left=vec[i].first;
    }
    if(prev==k && cur==k-1)
    {
        res.pb({left,vec[i].first});
    }
   }

   cout<<res.size()<<endl;
   for(pair<int,int>p:res)
   {
    cout<<p.first<<" "<<p.second<<endl;
   }


}



 
 /*"Success isn't permanent, failure isn't fatal,
                                      it's the courage to continue that counts"*/
