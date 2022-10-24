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

void solve()
{
   double angleA,angleB,angleC;
   double ab,bc,ca;
   double change=pi/180.0;

   cin>>angleB>>angleC>>bc;

   angleA=180-angleB-angleC;

  ca=(sin((change*angleB))*bc)/(sin(change*angleA));
  ab=(sin((change*angleC))*bc)/(sin(change*angleA));

  cout<<"ab bc ca : "<<ab<<" "<<bc<<" "<<ca<<endl;

   double s=(ab+bc+ca)/2.0;


   cout<<"value of s : "<<s<<endl;

   double forsq=s*(s-ab)*(s-bc)*(s-ca);

   cout<<"for sq : "<<forsq<<endl;
   double area=sqrt(forsq);

 /// double area=(0.5)*(ab*bc*cos(change*angleB));

   cout<<"value of area : "<<area<<endl;

   double r=area/s;



cout<<"the res is : ";
   cout<<r<<endl;

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


