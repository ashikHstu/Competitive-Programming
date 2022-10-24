#include <bits/stdc++.h>
using namespace std;
int main()
{
    double s1,s2,s3;cin>>s1>>s2>>s3;
    double res1=(sqrt((s1*s2)/s3))+(sqrt((s2*s3)/s1))+(sqrt((s1*s3)/s2))+0.1;
    long long int res=res1;
    cout<<res*4<<endl;
    return 0;
}
