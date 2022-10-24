#include <bits/stdc++.h>
using namespace std;
#define  ll long long int


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
#define SQrt(x)              (x)*(x)
#define CEIL(a,b)          ((a/b)+((a%b)!=0))

ll qube(ll a)
{
    return a*a*a;
}

//ll SQrt(ll a)
//{
//    return a*a;
//}

ll binarySearch(ll n,ll first)
{
    ll left=0,right=n-(first*first*first);

    right=pow(right,1/3.0);
    right+=1;
    ll res=right;
    while(left<=right)
    {
        ll mid=(left+right)/2;


        ll cal=qube(first)+(first*first)*mid+first*(mid*mid)+qube(mid);

        if(cal<n)
        {
            left=mid+1;
        }
        else {
            res=mid;
            right=mid-1;
        }
    }

    return res;

}


void solve(int kase)
{
   ll n=kase;
   cout<<"res "<<n<<" : ";
   //cin>>n;

   if(n==0){
    cout<<"0\n";
    return;
   }
   if(n==1)
   {
       cout<<"1\n";
       return;
   }
    if(n<=4)
   {
       cout<<"4\n";
       return;
   }
   if(n<=8)
   {
       cout<<"8\n";
       return;
   }
   if(n==27)
   {
       cout<<"27\n";
       return;
   }
   if(n>27 && n<=32){
    cout<<"32\n";
    return;
   }

   if(n>32 && n<=40)
   {
       cout<<"40\n";
       return;
   }
   if(n>40 && n<=59)
   {
       cout<<"59\n";
       return;
   }
   if(n<=64)
   {
       cout<<"64\n";
       return;
   }

   double ch=n;
   ch=pow(ch,1/3.0);
   ll lim=ch+1;
   vector<ll>res;


   for(ll i=0;i<=lim;i++)
   {
       ll j=binarySearch(n,i);

       ll cal=qube(i)+(i*i)*j+i*(j*j)+qube(j);
       if(cal<=4611686018427387904LL)
       res.push_back(cal);

   }
   sort(all(res));
   //cout<<"Mx is : "<<res[res.size()-1]<<endl;
   //ll ub=upper_bound(res.begin(),res.end(),n)-res.begin();



   cout<<res[0]<<endl;
}

int32_t main()
{
    int tc=1;
    cin>>tc;
    for(int i=1;i<=tc;i++)
    {
        solve(i);
    }


    return 0;
}



