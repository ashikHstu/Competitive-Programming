/** Problem : https://atcoder.jp/contests/abc184/tasks/abc184_f

*/

#include <bits/stdc++.h>
using namespace std;
#define ll long long int
#define isOn(S, j) (S & (1 << j))


int main()
{
    ll n,t;
    cin>>n>>t;

    ll ar[n+2];
    for(int i=0; i<n; i++)
        cin>>ar[i];

    ll mid=n/2;
    ll mid2=n-mid;
    ll loop=1<<mid;
    vector<ll>first_part,second_part;
   // cout<<"loop1 : "<<loop<<endl;
    for(int i=0; i<loop; i++)
    {
        ll sum=0;
        for(int j=0; j<mid; j++)
        {
            if(isOn(i,j))
            {
                sum+=ar[j];
            }
        }
        first_part.push_back(sum);
    }

    loop=1<<mid2;

    for(int i=0; i<loop; i++)
    {
        ll sum=0;
        for(int j=0; j<mid2; j++)
        {
            if(isOn(i,j))
            {
                sum+=ar[mid+j];
            }
        }
        second_part.push_back(sum);
    }

//    cout<<"first part : ";
//    for(ll v:first_part)cout<<v<<" ";cout<<endl;
//    cout<<"second part : ";
//    for(ll vv:second_part)cout<<vv<<" ";cout<<endl;

    sort(second_part.begin(),second_part.end());

    ll maxRes=0;
    for(ll v:first_part)
    {
        if(v>t)
            continue;
        ll ex=t-v;
        ll ind=upper_bound(second_part.begin(),second_part.end(),ex)-second_part.begin();
        ind--;
        ll res2=v+second_part[ind];
        maxRes=max(maxRes,res2);
    }

   // cout<<"max res : ";
        cout<<maxRes<<endl;
    return 0;

}
