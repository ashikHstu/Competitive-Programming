#include <bits/stdc++.h>
using namespace std;

int productDigit(int n)
{
    int d=n%10;
    n/=10;
    if(n>0)d=d*(productDigit(n));

    return d;


}

int fun(int n)
{
    if(n==4)return 2;
    else return 2*fun(n+1);

}



main()
{

    cout<<fun(2)<<endl;

  //  float sum=0.0,j=1.0,i=2.0;

//    while(i/j>0.001)
//    {
//
//        j=j+j;
//        sum=sum+i/j;
//        printf("%f\n",sum);
//    }

    //printf("product : %d\n",productDigit(4521));
}
