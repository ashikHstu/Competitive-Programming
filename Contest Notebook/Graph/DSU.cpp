#include <bits/stdc++.h>
using namespace std;

int par[101];
int Size[101];
int findParent(int cur)
{
    if(par[cur]==cur)return cur;
    return par[cur]=findParent(par[cur]);
}

int main()
{
     for(int i=1;i<=100;i++)
     {
         par[i]=i;
         Size[i]=1;
     }

     int q;cin>>q;
     while(q--)
     {
         int type;cin>>type;
         int a,b;cin>>a>>b;
         if(type==1)
         {
             int parent_a=findParent(a);
             int parent_b=findParent(b);
             if(parent_a!=parent_b){
                par[parent_a]=parent_b;
                Size[parent_a]+=Size[parent_b];
             }
         }
         else{
            int parent_a=findParent(a);
             int parent_b=findParent(b);
             if(parent_a==parent_b)
                cout<<"connected\n";
            else cout<<"not connected\n";
         }
     }

     return 0;

}
