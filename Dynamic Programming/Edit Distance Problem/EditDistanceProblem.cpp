#include <bits/stdc++.h>
using namespace std;
#define min3(a, b, c) min(a, min(b, c))
#define sz 5003
int dp[sz][sz];
string st1, st2;
int findEditDistance(int i, int j)
{
    if (i + 1 == 0 || j + 1 == 0)
        return max(i, j) + 1;
    if (dp[i][j] != -1)
        return dp[i][j];
    int ex = 0;
    if (st1[i] != st2[j])
        ex++;
    return dp[i][j] = min3(findEditDistance(i - 1, j) + 1, findEditDistance(i, j - 1) + 1, findEditDistance(i - 1, j - 1) + ex);
}
int findEditDistance2(int i, int j)
{
    if (i == -1)
        return j + 1;
    if (j == -1)
        return i + 1;

    if (dp[i][j] != -1)
        return dp[i][j];

    if (st1[i] == st2[j])
        return dp[i][j] = findEditDistance2(i - 1, j - 1);
    return dp[i][j] = min3(findEditDistance2(i - 1, j) + 1, findEditDistance2(i, j - 1) + 1, findEditDistance2(i - 1, j - 1) + 1);
}

int findEditDistance3(int i, int j)
{
    if (i == 0)
        return j;
    if (j == 0)
        return i;
    if (dp[i][j] != -1)
        return dp[i][j];
    if (st1[i - 1] == st2[j - 1])
        return dp[i][j] = findEditDistance3(i - 1, j - 1);
    return dp[i][j] = 1 + min3(findEditDistance3(i - 1, j), findEditDistance3(i, j - 1), findEditDistance3(i - 1, j - 1));
}

int editDistance()
{
    int n = st1.size();
    int m = st2.size();
    memset(dp, -1, sizeof(dp));
    return findEditDistance(n, m);
}

int main()
{

    cin >> st1 >> st2;
    cout << editDistance();

    return 0;
}