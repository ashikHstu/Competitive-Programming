#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define int long long
#define FasterIO             \
    ios::sync_with_stdio(0); \
    cin.tie(0);              \
    cout.tie(0)
#define doshomik(x) cout << fixed << setprecision(x)
#define TIME clock() * 1.0 / CLOCKS_PER_SEC
#define pi acos(-1.0)
#define mem(a, b) memset(a, b, sizeof(a))
#define all(a) a.begin(), a.end()
#define Sort(x) sort(x.begin(), x.end())
#define Reverse(x) reverse(x.begin(), x.end())
#define SortA(ar, s) sort(ar, ar + s)
#define SortD(ar, s) sort(ar, ar + s, greater<int>())
#define gcd(a, b) __gcd(a, b)
#define lcm(a, b) (a * (b / gcd(a, b)))
#define sq(x) (x) * (x)
#define CEIL(a, b) ((a / b) + ((a % b) != 0))

#define POSL(x, v) (lower_bound(x.begin(), x.end(), v) - x.begin())
#define POSU(x, v) (upper_bound(x.begin(), x.end(), v) - x.begin())
#define min3(a, b, c) min(a, min(b, c))
#define min4(a, b, c, d) min(a, min(b, min(c, d)))
#define max3(a, b, c) max(a, max(b, c))
#define max4(a, b, c, d) max(a, max(b, max(c, d)))
#define ABS(x) ((x) < 0 ? -(x) : (x))
#define pb push_back
#define nl printf("\n")


/*----------------------Graph Moves----------------*/
// const int fx[]={+1,-1,+0,+0};
// const int fy[]={+0,+0,+1,-1};
// const int fx[]={+0,+0,+1,-1,-1,+1,-1,+1};   // Kings Move
// const int fy[]={-1,+1,+0,+0,+1,+1,-1,-1};  // Kings Move
// const int fx[]={-2, -2, -1, -1,  1,  1,  2,  2};  // Knights Move
// const int fy[]={-1,  1, -2,  2, -2,  2, -1,  1}; // Knights Move
/*------------------------------------------------*/
#define minHeap priority_queue<int, vector<int>, greater<int>>

int jorNibo(int n)
{
    if (n % 2 == 0)
        return n;
    else
        return n - 1;
}
void solve()
{
    int n;
    cin>>n;
    vector<int>ar(2*n+2);
    for(int i=0;i<2*n;i++)
    {
        cin>>ar[i];
    }
    int cnt[n*2+2]={0};
    for(int i=0;i<2*n;i++)
    {
        cnt[ar[i]]++;
    }

    int evenCount=0,oddCount=0;
    for(int i=1;i<=2*n;i++)
    {
        if(cnt[i]==0)continue;
        if(cnt[i]%2==0)
        {
            evenCount++;
        }
        else
        {
            oddCount++;
        }
    }
    if(oddCount==0 && evenCount%2!=n%2)
    {
        cout<<2*evenCount-2<<endl;
    }
    else
    {
        cout<<oddCount+2*evenCount<<endl;
    }
}

int32_t main()
{
    int tc = 1;
    cin >> tc;
    for (int i = 1; i <= tc; i++)
    {
        solve();
    }
    return 0;
}
