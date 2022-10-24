#include <bits/stdc++.h>
using namespace std;
#define ll long long int

void printName(int i)
{
    if(i==1)
    {
        printf("Sheldon\n");
    }
    else if(i==2)
    {
        printf("Leonard\n");
    }
    else if(i==3)
    {
        printf("Penny\n");
    }
    else if(i==4)
    {
        printf("Rajesh\n");
    }
    else {
        printf("Howard\n");
    }
}

int main()
{
    ll n;cin>>n;
    ll cur=1;
    while(true)
    {
        for(int i=1;i<=5;i++)
        {
            if(cur>=n)
            {
                printName(i);
                return 0;
            }
            n-=cur;
        }
        cur=cur*2;
    }

    return 0;

}
