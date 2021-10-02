
#include <bits/stdc++.h>
using namespace std;
int main()
{
    long long int n;
    cin>>n;
    long long int sum=0;
    long long int ar[n+2];
    for(int i=0;i<n;i++)
    {
        cin>>ar[i];
        sum+=ar[i];
    }

    long long int lagbe;cin>>lagbe;
    long long int ghurbe=lagbe/sum;

    long long int res=ghurbe*n;
    long long int geche=ghurbe*sum;



    for(int i=0;i<n;i++)
    {
        geche+=ar[i];
        res++;
        if(geche>lagbe)
        {
           // cout<<"res : ";
            cout<<res<<endl;
            return 0;
        }
    }
}

