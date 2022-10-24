#include <bits/stdc++.h>
using namespace std;
#define yes cout<<"Yes\n"
#define no cout<<"No\n"


bool isMatched(string s,string t)
{
    int sl=s.size();
    int tl=t.size();

    for(int i=0;i<sl-tl-1;i++)
    {
        for(int j=0;j<tl;j++)
        {
            if(s[i+j]!=t[j]){

                    // cout<<"mismatched at : "<<j<<" , : "<<t[j]<<endl;
                    break;

            }
            if(j==tl-1)return true;
        }
    }

    return false;
}
int main()
{
    string s,t;cin>>t;
    for(int i=0;i<100;i++)
    {
        s+="oxx";
    }

    (isMatched(s,t))?yes:no;

    return 0;
}
