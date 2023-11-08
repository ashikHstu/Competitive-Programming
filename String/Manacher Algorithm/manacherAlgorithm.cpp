#include <bits/stdc++.h>
using namespace std;

struct manacher
{
    string mainString;
    vector<int> p;
    int longestPalindromeCenter = 0, longestPalindromeLength = 1;
    int numberOfPalindromeSubstring = 0;
    int palindromeMaxSuffixLength = 0;

    void run_manacher(string st)
    {
        int n = st.length();
        p.assign(n, 1);
        int l = 1, r = 1;

        for (int i = 1; i < n; i++)
        {
            p[i] = max(0, min(r - i, p[l + r - i]));

            while (i + p[i] < n && i - p[i] >= 0 && st[i + p[i]] == st[i - p[i]])
            {
                p[i]++;
            }
            if (i + p[i] > r)
            {
                l = i - p[i];
                r = i + p[i];
            }
            if (p[i] - 1 >= longestPalindromeLength)
            {
                longestPalindromeLength = p[i] - 1;
                longestPalindromeCenter = ((i - 1) / 2);
            }

            numberOfPalindromeSubstring += ((p[i] - 1) / 2) + ((p[i] - 1) % 2 == 1);

            /// Finding max Length Suffix Palindrome
            if (palindromeMaxSuffixLength == 0 && p[i] + i >= n)
                palindromeMaxSuffixLength = p[i] - 1;
        }

        // for (auto v : p)
        // {
        //     cout << v << " ";
        // }
        // cout << endl;
    }

    void build(string st)
    {
        mainString = st;
        string t;
        for (char ch : st)
        {
            // t.push_back('#');
            // t.push_back(ch);
            t += string("#") + ch;
        }
        // t.push_back('#');
        run_manacher(t + "#");
    }

    int getLongest(int cen, bool odd)
    {
        int pos = 2 * cen + 1 + (!odd);
        return p[pos] - 1;
    }

    bool checkPalindrome(int l, int r)
    {
        if ((r - l + 1) <= getLongest((l + r) / 2, l % 2 == r % 2))
        {
            return 1;
        }
        else
            return 0;
    }

    int getLengthOfLongestPalindrome()
    {
        return longestPalindromeLength;
    }
    int getCenterOfLongestPalindrome()
    {
        return longestPalindromeCenter;
    }

    int getLongestPalindromeStartIndex()
    {
        int pichabo = (getLengthOfLongestPalindrome() - 1) / 2;
        int startIndex = longestPalindromeCenter - pichabo;
        return startIndex;
    }

    string getLongestPalindrome()
    {
        int si = getLongestPalindromeStartIndex();
        int len = getLengthOfLongestPalindrome();
        return mainString.substr(si, len);
    }

    int getTotalNumberOfPalindromeSubstring()
    {
        return numberOfPalindromeSubstring;
    }
    int getPalindromeMaxSuffixLength()
    {
        return palindromeMaxSuffixLength;
    }
} m;

void solve(int kase)
{
    string st;
    // string st = "babbabbabc";
    cin >> st;
    cout << st << endl;
    m.build(st);
}

int main()
{
    int tc = 1;
    // cin>>tc;
    for (int i = 1; i <= tc; i++)
    {
        solve(i);
    }

    return 0;
}