#include <bits/stdc++.h>
using namespace std;


int main()
{

   int tc;cin>>tc;
   while(tc--)
   {
           int n;cin>>n;
   int ar[n+5];
   int result=-1;
   for(int i=0;i<n;i++)
   {
       cin>>ar[i];
       if(ar[i]!=i)
        {
            if(result==-1)result=ar[i];
            else result=(ar[i]&result);
        }
   }

    

cout<<result<<endl;

   }


    return 0;
}


