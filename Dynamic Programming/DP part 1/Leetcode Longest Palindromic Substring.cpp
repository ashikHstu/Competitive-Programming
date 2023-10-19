#include <bits/stdc++.h>
using namespace std;

string longestPalindrome(string st)
{
    int n = st.size();
    int dp[n + 2][n + 2];
    for (int i = 0; i <= n; i++)
    {
        dp[0][i] = dp[1][i] = 1;
    }

    int lastInd = -1, lastLength = -1;
    /*
    Here, i is the length of substring, which we ar considering
       j is the end index of a substring
       dp[i][j]=1  if the string which end at index j and have length i is a palindrome
    */
    for (int i = 2; i <= n; i++)
    {
        for (int j = i; j <= n; j++)
        {
            /* if the string with length i-2 ,
             is palindrome and end at index j-1,
             j-1 and j-i th position character are also same
            */
            if (st[j - 1] == st[j - i] && dp[i - 2][j - 1])
                dp[i][j] = 1;
            else
                dp[i][j] = 0;
            if (dp[i][j] == 1)
            {
                lastInd = j - 1;
                lastLength = i;
            }
        }
    }
    string res;
    if (lastInd == -1)
        res = st[0];
    else
        res = st.substr(lastInd - lastLength + 1, lastLength);
    return res;
}

int main()
{
    string st;
    cin >> st;
    cout << longestPalindrome(st) << endl;

    return 0;
}