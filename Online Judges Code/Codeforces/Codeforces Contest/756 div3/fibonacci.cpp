#include <bits/stdc++.h>
using namespace std;


#define Reverse(st) reverse(st.begin(),st.end())

#define limit 500005
string fib[limit+1];
string string_sum(string st1,string st2)
{
    string r;
    int s,c;
    c=0;
    int len1=st1.size();
    int len2=st2.size();
    Reverse(st1);
    Reverse(st2);
    if(len2>len1)
    {
        swap(len1,len2);
        swap(st1,st2);
    }
    for(int i=0; i<len1; i++)
    {
        if(i<len2)
        {
            s=st1[i]-48 +st2[i]-48+c;
        }
        else
        {
            s=st1[i]-48 +c;
        }
        c=s/10;
        s=s%10;
        r.push_back(s+48);
    }
    if(c!=0)
        r.push_back(c+48);
    Reverse(r);
    return r;
}

void make_fib(int n)
{
    fib[0]="0";
    fib[1]="1";
    int len1,len2,v1,v2,res,rem;
    char ch;
    for(int i=2; i<=n; i++)
    {
        fib[i]=string_sum(fib[i-1],fib[i-2]);
    }

}


int main()
{
    make_fib(100);

    for(int i=0;i<10;i++)cout<<fib[i]<<" ";
    cout<<endl;

    return 0;
}
