#include <bits/stdc++.h>
using namespace std;

int main()
{
    double a,b,c;
    while(cin>>a>>b>>c)
    {
        double s=(a+b+c)/2;
        double area=sqrt(s*(s-a)*(s-b)*(s-c));

        double res=0;
        if(s>0)res=area/s;
       printf("The radius of the round table is: %.3lf\n",res);
    }

    return 0;
}
