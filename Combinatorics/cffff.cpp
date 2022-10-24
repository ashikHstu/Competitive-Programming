#include <bits/stdc++.h>
using namespace std;

int grid[45][45];

int main() {
    int tc;
    cin >> tc;

    for (int test = 0; test < tc; ++test) {
        int n, m;
        cin >> n >> m;

        int max_i = 0, max_j = 0;

        for (int i = 0; i < n; ++i)
            for (int j = 0; j < m; ++j) {
                cin >> grid[i][j];
                if (grid[i][j] > grid[max_i][max_j])
                    max_i = i, max_j = j;
            }

        int h = max(max_i+1, n-max_i);
        int w = max(max_j+1, m-max_j);
        cout << h * w << '\n';
    }
}
