#include <bits/stdc++.h>

using namespace std;

#ifdef LOCAL
#include "algo/debug.h"
#else
#define debug(...) 42
#endif

int Solve(vector<int> a) {
  long long sum = 0;
  multiset<int> s;
  int ret = 0;
  for (int x : a) {
    sum += x;
    s.insert(x);
    while (sum < 0) {
      sum -= 2 * (*s.begin());
      ret += 1;
      s.erase(s.begin());
    }
  }
  return ret;
}

int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  int tt;
  cin >> tt;
  while (tt--) {
    int n, k;
    cin >> n >> k;
    vector<int> a(n);
    for (int i = 0; i < n; i++) {
      cin >> a[i];
    }
    vector<int> b;
    for (int i = k; i < n; i++) {
      b.push_back(a[i]);
    }
    vector<int> c;
    for (int i = k - 1; i > 0; i--) {
      c.push_back(-a[i]);
    }
    cout << Solve(b) + Solve(c) << '\n';
  }
  return 0;
}
