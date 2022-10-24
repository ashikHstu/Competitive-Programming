#include <bits/stdc++.h>
using namespace std;

string bigMultiply(string num,int num2)
{
    reverse(num.begin(),num.end());

    int len=num.size();

    string res;
    int carry=0;
    for(int i=0;i<len;i++)
    {
        int lastD=num[i]-'0';
        int mult=lastD*num2;
        mult+=carry;
        lastD=mult%10;
        carry=mult/10;
        res.push_back(lastD+'0');


    }

     reverse(res.begin(),res.end());

    if(carry>0)
    {
        string cc=to_string(carry);
        res=cc+res;
    }

    return res;
}
string fact[102];
void makeFact()
{
    fact[0]="1";
    fact[1]="1";
    for(int i=2;i<=100;i++)
    {
        fact[i]=bigMultiply(fact[i-1],i);
    }
}

int main()
{
    makeFact();
    int tc;cin>>tc;

   while(tc--)
    {
        int n;cin>>n;
        cout<<fact[n]<<endl;
    }

    return 0;
}
