#include<bits/stdc++.h>
using namespace std;
#define ll long long int
#define ull unsigned long long int
#define inf (1<<28)
#define mem(a,b) memset(a,b,sizeof(a))
#define pb(a) push_back(a)
#define FIO ios_base::sync_with_stdio(0); cin.tie(0)
#define SZ(a) (int)a.size()
#define PI 2*acos(0.0)
const double PIi  =3.141592653589793238463;



/*template<typename T=long long> T multiply(T a, T b, T mod){T res = 0; a %= mod; b %= mod;while(b){if(b & 0x1) res = (res + a)%mod; b >>= 1; if(a < mod-a) a<<=1; else a -= (mod-a);}return res;}
template<typename T=long long> T fastmodexp(T val, T p, T mod) { val %= mod; T res = 1; while (p > 0) { if (p & 0x1) res = (res*val)%mod; val = (val*val)%mod; p >>= 1;} return res;}
template<typename T=long long> T power(T val, T p) {T res = 1;while (p > 0){if (p & 0x1) res = (res*val); val = (val*val); p >>= 1;} return res;}
template<typename T=long long> T powerMul(T val, T p, T mod) { val %= mod; T res = 1; while (p > 0) { if (p & 0x1) res = multiply(res, val, mod);val = multiply(val, val, mod); p >>= 1; } return res;}
template<typename T> T gcd(T a, T b){return b==0?a:gcd(b, a%b);}
template<typename T> T lcm(T a, T b){return a/gcd(a,b) * b;}
template<typename T> string toString(T x){stringstream ss; ss<<x; return ss.str();}
template<typename T> T stringToT(string s){T p; istringstream ss(s); ss>>p; return p;}

#define maxx 10000009
bool isPrime[maxx+1];
vector<ll>primes;
void sieve()
{
    isPrime[0]=isPrime[1]=true; primes.pb(2);
    for(ull i=2;i<=maxx;i+=2)isPrime[i]=true; int rt=sqrt(maxx)+2;
    for(int i=3;i<maxx;i+=2){if(!isPrime[i]){primes.pb(i);if(i<=rt){for(int j=i*i;j<=maxx;j+=i*2)isPrime[j]=true;}}}
    isPrime[2]=false;
}

vector<ll>factorize(ll m,vector<ll>&primes){
vector<ll>factors;
factors.clear();
int i=0;
int p=primes[0];
while(p*p<=m)
    {
        if(m%p==0){
            factors.pb(p);
            while(m%p==0)
            {
                m=m/p;
            }
        }
        i++;
        p=primes[i];
    }
    if(m!=1)
    {
        factors.push_back(m);
    }
    return factors;

}

int ans[10001]={};
void precalculate ()
{
     for(int i = 0; i < 10001; i++) {
        int tmp = 0;
        for(int j = i; j < 10001; j++) {
            tmp += primes[j];
            if(tmp > 10000) break;
            ans[tmp]++;
        }
    }
}
bool issPrime(ll num){ //cout<<"call hocce";
	return 1 - isPrime[num];
}
bool isTPrime(ll num){
    if(num<=3)
    	return false;
	ll sqval = sqrt(num);
    if(sqval*sqval!=num)
		return false;
	return issPrime(sqval);
}
ll NOD(ll n) {

    ll ret=1;
    for(int i=0; i<primes.size(); i++) {
            if(primes[i]*primes[i]*primes[i]>n)break;

            int cnt=1;
            while(n%primes[i]==0) {
                cnt++;
                n/=primes[i];
            }
            ret*=cnt;


    }
    double sqprime=sqrt(n);
      ll flr=floor(sqprime);
       ll cel=ceil(sqprime);

       if(isPrime[n]==false)ret*=2;
       else if(isPrime[cel]==false && cel==flr)ret*=3;
       else if(n!=1) ret*=4;

    return ret;
}
*/



long long bigMod(long long a, long long b, long long m)
{
    a %= m;
    long long res = 1;
    while (b > 0)
    {
        if (b & 1)
            res = res * a % m;
        a = a * a % m;
        b >>= 1;
    }
    return res;
}


long long int findRes(string st,int n)
{
    int md=1000000007;
    int len=st.size();
    long long int res=0;
    for(int i=len-1; i>=0; i--)
    {
        if(st[i]=='1')
        {
            res+=(bigMod(n,(len-i-1),md));
            res%=md;
        }
    }

    return res;
}

string toBinary(long int n)
{
    string r;
    while(n!=0)
    {
        r=(n%2==0 ?"0":"1")+r;
        n/=2;
    }
    return r;
}
int main()
{

    ll n,a,c,ans,t,m,k,k1,k2,w,b,x,y,sum=0;
    string s;
    cin>>t;
    while(t--)
    {

        cin>>n>>k;
        s=toBinary(k);
        cout<<s<<endl;
        a=5;
        k = 64 - __builtin_clzll(a) - 1;
        k = 32 - __builtin_clz(n) - 1;

        // cout <<k;

        cout<<findRes(s,n)<<endl;



    }
    return 0;
}
