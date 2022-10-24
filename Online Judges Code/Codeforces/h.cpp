#include<bits/stdc++.h>
using namespace std;
using ll = long long;
using vi = vector<int>;
using ii = pair<int, int>;

const int md = 1e9 + 7;
const int mx = 1e6 + 5;

string s;
int n, a, b, c;

inline void MAIN(){
    cin >> a >> b >> c;
    if(a <= b){
        cout << "NO\n";
    }else{
        cout << "YES\n";
        cout << (b*2+1) << "\n";
    }
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr); cout.tie(nullptr);

    int tc = 1;
    // cin >> tc;
    for(int cs=1; cs<=tc; ++cs){
        // cout << "Case " << cs << ": ";
        MAIN();
    }

    return 0;
}

