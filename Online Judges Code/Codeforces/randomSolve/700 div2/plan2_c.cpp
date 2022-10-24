#include <bits/stdc++.h>
using namespace std;
int n;
bool ok;
int ar[2000006];
int totalQ=0;
void confirm(int v)
{
    if(ok)return;
    cout<<"! "<<v<<endl;
    cout.flush();
    ok=true;
}

void findValue(int ind)
{
    if(ok)return;

    if(ar[ind]!=-1)return;
    if(ind==0 || ind==n+1){
        ar[ind]=20000000;
        return;
    }


    cout<<"? "<<ind<<endl;
    cout.flush();
    int v;cin>>v;
    ar[ind]=v;
    if(v==1)
    {
        confirm(ind);
        ok=true;
    }
}



void checkThree(int ind)
{
    if(ok)return;
        findValue(ind);
        findValue(ind-1);
        findValue(ind+1);

        if(ar[ind]<ar[ind-1] && ar[ind]<ar[ind+1])
        {
            confirm(ind);
            return;
        }
    return;
}

void findSolution(int l,int r)
{
    if(ok)return;
    int mid=(l+r)/2;

    checkThree(mid);

     if(ar[mid-1]<ar[mid])
     {
         checkThree(mid-1);
         findSolution(l,mid-1);
     }
     if(ar[mid+1]<ar[mid])findSolution(mid+1,r);


}

int main()
{
    memset(ar,-1,sizeof(ar));
    ok=false;
  cin>>n;
  findSolution(1,n);

  return 0;

}
