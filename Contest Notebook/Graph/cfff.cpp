#include<bits/stdc++.h>
using namespace std;
#define fast ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
#define nl '\n'
typedef long long ll;
typedef vector<int> vi;
typedef vector<ll> vl;
typedef vector<vi> vvi;
typedef vector<vl> vvl;
typedef pair<int,int> pii;
typedef pair<double,double> pdd;
typedef pair<ll,ll> pll;
typedef vector<pii> vii;
typedef vector<pll> vll;
#define pb push_back
#define F first
#define S second
#define all(a) (a).begin(),(a).end()
#define rall(a) (a).rbegin(),(a).rend()
int dx[] = {0, 0, +1, -1}; // {-1,+1,+2,+2,-2,-2,+1,-1};
int dy[] = {+1, -1, 0, 0}; // {+2,+2,+1,-1,-1,+1,-2,-2};
const int inf = 2000000000;
const ll infll = 1000000000000000000+123;
const int N = 2e5+123;
#define mod 1000000007

void solve( )
{
    ll n,m,k;
    cin >> n >> m >> k;

    vector<ll> a(n), b(m);
    map<ll,ll> cnt;
    set<ll> st, tmp;
    ll s1 = 0, n1 = 0, n2 = 0;

    for(ll i=0; i<n; i++)
    {
        cin >> a[i];
        if(cnt[a[i]] != 1 and a[i] <= k)
            cnt[a[i]] = 1, st.insert(a[i]), n1++;
    }
    s1 = st.size();

    ll s2 = 0, to = 0, one = 0;
    for(ll i = 0; i < m; i++)
    {
        cin >> b[i];

        if(b[i] <= k)
        {
            if(cnt[ b[i] ] == 1) to++, s2++, cnt[b[i]]++;
            st.insert(b[i]);
            tmp.insert(b[i]);
        }
    }
    s2 = tmp.size();

    if(s1 < k/2 or s2 < k/2)
    {
        cout << "NO" <<nl;
        return;
    }

    for(ll i=1; i<=k; i++)
    {
        if(st.find(i) == st.end() )
        {
            cout << "NO" <<nl;
            return;
        }
    }

    cout << "YES" <<nl;

}

int main()
{
    fast

    //freopen("x.txt","r",stdin);
    //freopen("y.txt","w",stdout);

    ll T;
    cin>>T;
    for(ll t=1; t<=T; t++)
    {   //cout<<"Case "<<t<<": ";
        solve();
    }
    return 0;
}
