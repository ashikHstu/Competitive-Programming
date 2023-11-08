int kmp(string s)
{
    vector<int> lps(s.size(), 0);

    for (int i = 1; i < (int)lps.size(); ++i)
    {
        int prev_idx = lps[i - 1];

        while (prev_idx > 0 && s[i] != s[prev_idx])
        {
            prev_idx = lps[prev_idx - 1];
        }

        lps[i] = prev_idx + (s[i] == s[prev_idx] ? 1 : 0);
    }

    return lps[lps.size() - 1];
}

