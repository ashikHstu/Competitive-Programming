#include <bits/stdc++.h>
using namespace std;

int main()
{
    int tc;
    cin>>tc;
    while(tc--)
    {

    int n;cin>>n;
    string str;
    cin>>str;
    int m=n/2;
    int result=0;
   
   for(int ii=m+1;ii<n;ii++)
    {
        if(str[ii]==str[m])result++;
        else break;
    }
    for(int j=m;j>=0;j--)
    {
        if(str[j]==str[m])result++;
        else break;
    }

    
    cout<<result<<endl;


    }

    return 0;
}


