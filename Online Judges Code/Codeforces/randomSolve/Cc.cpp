#include <bits/stdc++.h>
using namespace std;

#define pb push_back

void solve(int kase)
{

    int n;
    cin>>n;
    string st;
    cin>>st;
    map<char,char>mp;
    int totalGroup=0;
    string res;
    char groupFirst[30],groupLast[30];
    int groupSize[30];
     int firstOfGroup[30];
     for(int i=0;i<30;i++)firstOfGroup[i]=-1;
    int inGroup[30]={0};
    int assigned[30]={0};

    for(int i=0; i<n; i++)
    {

        if(mp.find(st[i])!=mp.end())
        {
            char cc=mp[st[i]];
            res.pb(cc);

        }
        else
        {
            bool done=false;
             for(int j=0;j<totalGroup;j++)
             {
                 if(groupSize[j]==26)
                 {
                     mp[groupLast[j]]=groupFirst[j];
                     done=true;
                 }
                 else if(groupLast[j]==st[i])
                 {
                     for(int k=0;k<26;k++)
                     {
                         if(assigned[k]==0 && groupFirst[j]!=k+'a')
                         {
                             mp[st[i]]=k+'a';
                             groupSize[j]++;
                             assigned[k]++;
                             groupLast[j]=j+'a';
                             done=true;
                             if(firstOfGroup[k]!=-1)
                             {
                                 groupFirst[firstOfGroup[k]]=groupFirst[j];
                                 groupLast[j]=groupLast[firstOfGroup[k]];

                             }
                         }
                         if(done)break;
                     }
                 }
             }
             if(done)
             {
                 res.pb(mp[st[i]]);
                 continue;

             }

        cout<<"before "<<i<<"th step : "<<res<<endl;

             for(int j=0;j<26;j++)
             {
                 if(assigned[j]==0 && st[i]-'a'!=j)
                 {
                     groupFirst[totalGroup]=st[i];
                     groupLast[totalGroup]='a'+j;
                     firstOfGroup[st[i]-'a']=totalGroup;
                     inGroup[st[i]-'a']++;
                     inGroup[j]++;
                     assigned[j]++;
                     mp[st[i]]=j+'a';
                     res.pb('a'+j);
                     groupSize[totalGroup]++;
                     groupSize[totalGroup]++;
                     totalGroup++;
                     break;
                 }
             }
        }
    }

    cout<<res<<endl;
}

int main()
{
    int tc;
    cin>>tc;
    for(int i=1; i<=tc; i++)
    {

        solve(i);
    }
}
