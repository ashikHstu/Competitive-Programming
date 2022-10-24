#include <bits/stdc++.h>
using namespace std;


int main()
{
    int tc=1;
    cin>>tc;
    for(int i=0;i<tc;i++)
    {
    int n;cin>>n;
     map<int,int>mp;
     int result=0;
      int value;
     for(int i=0;i<n;i++)
     {
        
         cin>>value;
         mp[value]++;
         if(mp[value]<3)result++;
     }

    result=(result/2)+(result%2);
    cout<<result<<endl;
    }

    return 0;
}


