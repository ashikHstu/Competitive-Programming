#include <bits/stdc++.h>
using namespace std;
#define ll long long int



int main()
{
   int n=50;
   int ct=0;
   for(int i=0;i<=n;i+=3)
   {
       ct++;
       i--;
   }
   cout<<"ct : "<<ct<<endl;
    return 0;
}

