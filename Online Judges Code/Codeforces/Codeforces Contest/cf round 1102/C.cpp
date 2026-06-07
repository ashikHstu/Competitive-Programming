#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t; cin >> t;
    while (t--) {
        int n; cin >> n;
        vector<long long> h(n);
        for (int i = 0; i < n; i++) cin >> h[i];

        vector<long long> ans(n);

        for (int empty = 0; empty < n; empty++) {
            vector<long long> w(n, 0);
            // expand to the right
            long long cur = 0;
            for (int j = (empty+1)%n; j != empty; j = (j+1)%n) {
                cur = min(h[(j-1+n)%n], cur+1);
                w[j] = cur;
            }
            // expand to the left
            cur = 0;
            for (int j = (empty-1+n)%n; j != empty; j = (j-1+n)%n) {
                cur = min(h[j], cur+1);
                w[j] = max(w[j], cur);
            }
            ans[empty] = accumulate(w.begin(), w.end(), 0LL);
        }

        for (int i = 0; i < n; i++) cout << ans[i] << " ";
        cout << "\n";
    }
    return 0;
}
