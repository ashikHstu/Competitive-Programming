#include <bits/stdc++.h>
using namespace std;



void solve()
{
    int n;cin>>n;
    string st;
    cin>>st;


    set<char>s;
    for(char ch:st)
        s.insert(ch);


    int len=s.size();
    map<char,int>mp;
    int cur=0,dif=0;
     int mn=n;
    for(int i=0;i<n;i++)
    {
        mp[st[i]]++;
        if(mp[st[i]]==1)dif++;
        while(mp[st[cur]]>1){
            mp[st[cur]]--;
            cur++;
        }

        if(dif==len)
        {
            mn=min(mn,i-cur+1);
        }


    }

   // cout<<"res : ";
    cout<<mn<<endl;



}

int main()
{
    int tc=1;
    //cin>>tc;
    for(int i=0;i<tc;i++)
    {
        solve();
    }
}
