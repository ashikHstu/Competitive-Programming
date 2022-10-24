#include <bits/stdc++.h>
using namespace std;

string takeOdd(string st[],int n)
{


    for(int i=0;i<n;i++)
    {
        if(st[i].size()%2==1)return st[i];
    }
}

int main()
{
    int n;
    cout<<"Enter the size of Array : "<<endl;
    cin>>n;
    string st[n];
    cout<<"Enter the String Array : "<<endl;
    for(int i=0;i<n;i++)cin>>st[i];


    cout<<"The first odd length string is : ";
    cout<<takeOdd(st,n)<<endl;

    return 0;
}
