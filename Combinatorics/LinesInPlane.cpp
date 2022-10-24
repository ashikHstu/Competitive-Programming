#include <bits/stdc++.h>
using namespace std;

long long int Line(int n)
{
    if(n==0)return 1;

    return n+Line(n-1);

}

int main()
{
    int n;
    cout<<"Enter the number of Lines : ";
    cin>>n;

    cout<<"The number of part in plane : "<<Line(n)<<endl;

    return 0;

}
