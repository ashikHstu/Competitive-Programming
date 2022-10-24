#include<bits/stdc++.h>
using namespace std;
void solve()
{
    long long int a,b,c,d,e,f,g,h,i,j,k,l,m,n,p,q,r,s,v,x,y,z;
    vector<int>res;
    set<int>st;
//int ld[21]= {0,1,2,3,4,5,6,7,8,9,0,1,2,3,4,5,6,7,8,9,0};
//D=1;
//U=-1;

    cin>>n;
    int arr[n];
    for(i=0; i<n; i++)
    {
        cin>>arr[i];
    } //input

    for(k=0; k<n; k++)
    {
        int numberofmove;
        string moves;

        cin>>numberofmove;
        cin>>moves;


s=arr[k];
        for(j=numberofmove-1; j>=0; j--)
        {




            if(moves[j]=='D')
            {
                //  if(s==0){s=9;}


                s++;

                if (s==10) s=0;

            }

            else
            {
                //if(s==9){s=0;}
                s--;
                if(s==-1) s=9;



            }
        }


        res.push_back(s);

    }

//cout<<endl;
    for(i=0; i<res.size(); i++)
    {
        cout<<res[i]<<" ";
    }
    cout<<endl;
    res.clear();

}


int main()
{

    long long int it,tc;
    cin>>tc;
    for(it=1; it<=tc; it++)
    {
        solve();
    }
    return 0;

}

