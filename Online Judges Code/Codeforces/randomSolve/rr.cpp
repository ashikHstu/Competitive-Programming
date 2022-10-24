#include<bits/stdc++.h>
using namespace std;
void solve()
{
    long long int a,b,c,d,e,f,g,h,i,j,k,len,m,n,p,q,r,s,v,x,y,z;

    string str;

    cin>>str;

    len=str.size();

    cout<<len<<endl;

    long long int arr[len]= {0};


    arr[0]=1;

    for(i=1; i<len; i++)
    {

        if(str[i]==str[i-1])
        {
            arr[i]=arr[i-1]+1;
        }
        else
        {
            arr[i]=1;
        }
    }


    s=0;
    for(i=0; i<len; i++)
    {
        s=max(s,arr[i]);
    }
    cout<<s<<endl;






}


int main()
{

    long long int it,tc;
    // cin>>tc;
    for(it=1; it<=1; it++)
    {
        solve();
    }
    return 0;

}

