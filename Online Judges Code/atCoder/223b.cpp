#include <bits/stdc++.h>
using namespace std;
int main()
{
    string st;cin>>st;



    string newS;
    int len=st.size();
    int cur=len-1;
    while(cur>0 and st[0]==st[cur])
    {
        newS.push_back(st[cur]);
        cur--;
    }
    for(int i=0;i<=cur;i++)
    {
        newS.push_back(st[i]);
    }

   vector<pair<int,char>>vec;

   int ct=1;
   char ch=newS[0];
   for(int i=1;i<len;i++)
   {
       if(ch==newS[i])
        ct++;
       else {
        vec.push_back({ct,ch});
        ct=1;
        ch=newS[i];
       }
   }
   if(ct>0)
   {
       vec.push_back({ct,ch});
   }


   int minP=vec[0].first;
   char minC=vec[0].second;
   int mp=0;

    int mxP=vec[0].first;
   char mxC=vec[0].second;
   int mxp=0;

   int vecSize=vec.size();

   for(int i=0;i<vecSize;i++)
   {
       if(vec[i].second <minC)
       {
           minC=vec[i].second;
           minP=vec[i].first;
           mp=i;
       }
       else if(vec[i].second == minC && vec[i].first>minP)
       {

           minC=vec[i].second;
           minP=vec[i].first;
           mp=i;
       }

         if(vec[i].second >mxC)
       {
           mxC=vec[i].second;
           mxP=vec[i].first;
           mxp=i;
       }
       else if(vec[i].second == mxC && vec[i].first<mxP)
       {

           mxC=vec[i].second;
           mxP=vec[i].first;
           mxp=i;
       }

   }





   for(int i=mp;i<vecSize;i++)
   {
       for(int j=0;j<vec[i].first;j++)
        cout<<vec[i].second;
   }
   for(int i=0;i<mp;i++)
   {
       for(int j=0;j<vec[i].first;j++)
      cout<<vec[i].second;
   }

   cout<<endl;

     for(int i=mxp;i<vecSize;i++)
   {
       for(int j=0;j<vec[i].first;j++)
        cout<<vec[i].second;
   }
   for(int i=0;i<mxp;i++)
   {
       for(int j=0;j<vec[i].first;j++)
      cout<<vec[i].second;
   }



}
