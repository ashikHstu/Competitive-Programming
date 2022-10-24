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
char ch[28+2];
int k;
bool isSpecial(char cch)
{
    for(int i=0;i<k;i++)
    {
        if(ch[i]==cch)return true;

    }

    return false;
}

void solve()
{
    int n;cin>>n;
    string st;
    cin>>st;
    cin>>k;
    
    for(int i=0;i<k;i++)cin>>ch[i];

    vector<int>vec;
    int curSp=0;
    bool spStarted=false;
    for(int i=n-1;i>=0;i--)
    {
        curSp++;
        if(isSpecial(st[i]))
        {
            if(spStarted)
            {
                vec.push_back(curSp);
            }
            else {
                spStarted=true;
            }
            curSp=0;
        }
    }

    if(spStarted==false)
    {
        cout<<"0\n";
        return;
    }
    vec.push_back(curSp);

   sort(all(vec));

   cout<<vec[vec.size()-1]<<endl;

//    ll removed=0;
//    ll totalRemoved=0;
//    ll szz=vec.size();
//    for(int i=0;i<vec.size();i++)
//    {
//        ll curr=vec[i];
//         totalRemoved+=((curr-removed)*(szz-i));
//         removed+=(curr-removed);
//    }



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


