#include <bits/stdc++.h>
using namespace std;

int check(int a,int b)
{

    if(a==0 and b==0)
        return 1;

    if(a==1 and b==1)
        return 0;
    else
        return 2;
}

void solve()
{
    int n;
    cin>>n;
    string st1,st2;
    cin>>st1>>st2;
    int res=0;
    for(int i=0; i<n; i++)
    {
        int a=st1[i]-'0';
        int b=st2[i]-'0';

        int ns;

        if(i+1<n)
        {
            ns=check(st1[i+1]-'0',st2[i+1]-'0');
        }
        int status=check(a,b);
        if(status==2)
            res+=status;
        else if(status==1)
        {
            if(i+1<n && ns==0)
            {
                res+=2;
                i++;
            }
            else
            {
                res+=1;
            }
        }
        else if(status==0)
        {
            if(i+1<n && ns==1)
            {
                res+=2;
                i++;
            }
            else
            {
                res+=0;
            }
        }
    }

    cout<<res<<endl;

}



int main()
{
    int tc;
    cin>>tc;
    while(tc--)
        solve();

    return 0;
}
