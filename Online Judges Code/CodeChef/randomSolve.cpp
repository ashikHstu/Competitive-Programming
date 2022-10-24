#include <bits/stdc++.h>
using namespace std;


#define SIZE 1000
string fact[SIZE+1];

string string_multiply(string st,int n)
{
    reverse(st.begin(),st.end());
    int rem=0,res,v,ch;
        int len=st.size();
        string result;
        for(int j=0;j<len;j++)
        {
            v=st[j]-'0';
            res=(v*n)+rem;
            rem=res/10;
            res=res%10;
            ch=res+'0';
            result.push_back(ch);
        }
        while(rem!=0)
        {
            res=rem%10;
            rem=rem/10;
            ch=res+'0';
            result.push_back(ch);
        }
        reverse(result.begin(),result.end());
        return result;
}

void make_fact()
{

    fact[0]="1";
    fact[1]="1";
    for(int i=2;i<=101;i++)
    {
        fact[i]=string_multiply(fact[i-1],i);
    }

}

void solve()
{

   int n;cin>>n;
  cout<<fact[n]<<"\n";
}

int main()
{
    make_fact();
    int tc=1;
    cin>>tc;
    for(int i=1;i<=tc;i++)
    {
        solve();
    }

    return 0;
}

