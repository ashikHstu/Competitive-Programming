#include <bits/stdc++.h>
using namespace std;
#define mod 1000000007
int main()
{
    string st;cin>>st;

    reverse(st.begin(),st.end());
    long long int a=0,b=0,c=0;
    long long int sum=0;
    int len=st.size();
    for(int i=0;i<len;i++)
    {

        if(st[i]=='C')c++;
        else if(st[i]=='B')b++;
        else if(st[i]=='A')
        {
            sum+=(b*c);
        }
        else if(st[i]=='?'){
            sum+=(b*c);
            b++;c++;
        }

        sum%=mod;
    }

    cout<<"sum : "<<sum<<endl;

    return 0;


}
