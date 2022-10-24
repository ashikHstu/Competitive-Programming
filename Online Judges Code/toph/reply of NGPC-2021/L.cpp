#include<bits/stdc++.h>
using namespace std;
const int mx5 = 1e5 + 5;

int n, m, p;
int a[mx5][11];

int cal(int i, int j, int x, int y){
    if(i > x) return 1e9;
    return a[x][y] - a[x][j-1] - a[i-1][y] + a[i-1][j-1];
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr); cout.tie(nullptr);

    cin >> n >> m >> p;
    for(int i=1; i<=n; ++i)
        for(int j=1; j<=m; ++j){
            cin >> a[i][j];
            a[i][j] = 1-a[i][j];
        }

    for(int i=1; i<=n; ++i)
        for(int j=1; j<=m; ++j)
            a[i][j] += a[i-1][j] + a[i][j-1] - a[i-1][j-1];
//            a[i][j] += a[i][j-1];

    int ans = 0;
    for(int len=1; len<=m; ++len){
        for(int k=1; k+len-1<=m; ++k){
            int ses = k + len - 1;
            for(int i=1,j=1; i<=n; ++i){
                if(j < i) j = i;
                while(j<=n && cal(i,k,j,ses) <= p) ++j;
//                cout << len << " " << k << " " << i << " " << j << "\n";
                if(cal(i, k, j-1, ses) <= p)
                    ans = max(ans, (j-i)*len);
            }
        }
    }

    cout << ans << "\n";

    return 0;
}
