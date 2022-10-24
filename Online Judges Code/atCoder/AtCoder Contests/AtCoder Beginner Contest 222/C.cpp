#include <bits/stdc++.h>
using namespace std;

struct d
{
    int v,ind;
    d(int _v,int _ind)
    {
        v=_v;
        ind=_ind;
    }

    bool operator<(const d &p)const
    {
       if(v==p.v)return ind<=p.ind;
       return v>p.v;
    }

};


int whoWin(char ch1,char ch2)
{
    if(ch1==ch2)return 2;

    if(ch1=='G' && ch2=='C')return 1;
    else if(ch1=='C' && ch2=='G')return 0;
    else if(ch1=='C' && ch2=='P')return 1;
    else if(ch2=='C' && ch1=='P')return 0;
    else if(ch1=='P' && ch2=='G')return 1;
    else if(ch2=='P' && ch1=='G')return 0;
    return 2;
}


int main()
{



   int n,m;
cin>>n>>m;
   string st[2*n];
   for(int i=0;i<2*n;i++)
   {
       cin>>st[i];
   }


   int points[2*n+3]={0};

   for(int r=0;r<m;r++)
   {
       vector<d>v;
       for(int i=0;i<2*n;i++)
       {
           v.push_back(d(points[i],i));
       }
       sort(v.begin(),v.end());



       for(int i=0;i<2*n;i+=2)
       {
           int val=whoWin(st[v[i].ind][r],st[v[i+1].ind][r]);

           //cout<<"playing "<<v[i].ind<<" with : "<<v[i+1].ind<<endl;

          // cout<<"val : "<<val<<endl;
           if(val==1)points[v[i].ind]++;
           else if(val==0)points[v[i+1].ind]++;
       }




       v.clear();



   }

    vector<d>v;
       for(int i=0;i<2*n;i++)
       {
          // cout<<points[i]<<" , ind "<<i<<endl;
           v.push_back(d(points[i],i));
       }
       sort(v.begin(),v.end());
   for(int i=0;i<2*n;i++)cout<<v[i].ind+1<<"\n";


     return 0;
}

