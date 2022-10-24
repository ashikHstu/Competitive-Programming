#include <bits/stdc++.h>
using namespace std;
#define ll long long int
#define pb push_back

#define FasterIO          ios::sync_with_stdio(0);cin.tie(0);cout.tie(0)
#define TIME              clock()*1.0/CLOCKS_PER_SEC
#define pi                acos(-1.0)
#define mem(a,b)           memset(a,b,sizeof(a))
#define all(a)             a.begin(),a.end()
#define Sort(x)            sort(x.begin(),x.end())
#define Reverse(x)         reverse(x.begin(),x.end())
#define SortA(ar,s)        sort(ar,ar+s)
#define SortD(ar,s)        sort(ar,ar+s,greater<int>())
#define gcd(a,b)           __gcd(a,b)
#define lcm(a,b)           (a*(b/gcd(a,b)))
#define sq(x)              (x)*(x)
#define CEIL(a,b)          ((a/b)+((a%b)!=0))

struct stt
{
    int value,curInd,occ;
      stt(int _value,int _curInd,int _occ)
    {
        value=_value;
        curInd=_curInd;
        occ=_occ;
    }
};

void solve()
{
    int n;cin>>n;
    int ar[n+2];
    int ind=0;
    map<int,int>mp,mpr;
    int ct[n+2]={0};
    for(int i=0;i<n;i++)
    {
        int v;cin>>v;
        if(mp[v]==0)
        {
            ind++;
            mp[v]=ind;
            mpr[ind]=v;
            ar[i]=ind;
            ct[ind]++;

        }
        else {
            ar[i]=mp[v];
            ct[ar[i]]++;
        }
    }
    int done[ind+2]={0};
    ind++;


   vector<stt>vec[ind+2];
   int ctt=1;

   for(int i=1;i<n;i++)
   {
    if(ar[i-1]!=ar[i])
    {
        vec[ar[i-1]].push_back(stt(ar[i-1],i-ctt,ctt));
        ctt=1;
    }
    else ctt++;

   }

//    cout<<"ar[1] : "<<ar[1]<<endl;
//    cout<<"ar[0] : "<<ar[0]<<endl;

   if(ctt>=1)
   {
    vec[ar[n-1]].push_back(stt(ar[n-1],n-ctt,ctt));
   }


//  cout<<"the value of ind : "<<ind<<endl;
//    for(int i=1;i<ind;i++)
//    {
//     int len=vec[i].size();
//     cout<<"into ind?"<<endl;
//     for(int j=0;j<len;j++)
//     {
//         cout<<"into len?"<<endl;

//         cout<<vec[i][j].value<<" "<<vec[i][j].curInd<<" "<<vec[i][j].occ<<endl;
//     }cout<<endl;
//    }cout<<endl<<endl;



    int res=-10;
  int mainL=-1,mainR=-1,mainV=-1;

    for(int i=1;i<ind;i++)
    {
          int cur=0;
        int len=vec[i].size();
    int rv,rl,rr;
        int res1=0;
        for(int j=0;j<len;j++)
        {
            int curV=vec[i][j].value;
             int curInd=vec[i][j].curInd;
            int curOcc=vec[i][j].occ;
             if(j==0){

               rl=curInd;
               rr=curInd+curOcc-1;
               rv=curV;
               cur=rr;
              res1=curOcc;

             }
             else {
               // cout<<"curInd , rr, res1 : "<<curInd<<", "<<rr<<", "<<res1<<endl;
                 if(curInd-rr-1<=res1)
                 {
                    res1-=(curInd-rr-1);
                    res1+=curOcc;
                    rr=curInd+curOcc-1;

                 }
                 else {
                       rl=curInd;
               rr=curInd+curOcc-1;
               rv=curV;
               cur=rr;
              res1=curOcc;

                 }
             }

             if(res<res1)
             {
                res=res1;
                mainL=rl;
                mainR=rr;
                mainV=rv;
             }


        }
    }

//cout<<"res : ";
     cout<<mpr[mainV]<<" "<<mainL+1<<" "<<mainR+1;
     cout<<endl;








}

int main()
{
    int tc=1;
    cin>>tc;
    for(int i=1;i<=tc;i++)
    {
        solve();
    }

    return 0;
}



