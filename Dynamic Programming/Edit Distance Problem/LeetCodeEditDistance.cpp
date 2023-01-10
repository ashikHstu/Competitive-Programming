class Solution
{
public:
    string st1, st2;
    int dp[505][505];

    int EditDistance(int i, int j)
    {
        if (i == 0)
            return j;
        if (j == 0)
            return i;
        if (dp[i][j] != -1)
            return dp[i][j];
        if (st1[i - 1] == st2[j - 1])
            return dp[i][j] = EditDistance(i - 1, j - 1);
        return dp[i][j] = 1 + min(EditDistance(i - 1, j), min(EditDistance(i, j - 1), EditDistance(i - 1, j - 1)));
    }

    int minDistance(string word1, string word2)
    {
        memset(dp, -1, sizeof(dp));
        st1 = word1;
        st2 = word2;
        return EditDistance(word1.size(), word2.size());
    }
};