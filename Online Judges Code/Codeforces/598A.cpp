#include <bits/stdc++.h>
using namespace std;


 int lastOnPosition(long long int num)
 {
    int lastOn=-1;
    for(int i=0;i<32;i++)
    {
        if((num&(1<<i)))lastOn=i;
    }
    return lastOn;
 }

void solve()
{
    long long int n;
    cin>>n;

    long long int sum=(n*(n+1))/2;



    int lo= lastOnPosition(n);




     long long int s2=(1<<lo);




    s2*=2;
    s2-=1;

//cout<<"lo : "<<lo<<endl;
//cout<<"sum : "<<sum<<" , s2 : "<<s2<<endl;

    sum=sum-s2;sum-=s2;
    cout<<sum<<endl;
}

int main()
{
    int tc;cin>>tc;
    while(tc--)solve();


    return 0;
}
