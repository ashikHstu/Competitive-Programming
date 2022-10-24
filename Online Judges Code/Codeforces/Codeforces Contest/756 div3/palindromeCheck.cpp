#include <bits/stdc++.h>
using namespace std;
#define ll long long int

bool isPalindrome(string st)
{
    int len=st.size();

    for(int i=0;i<len;i++)
    {
        if(st[i]!=st[len-i-1])return false;
    }

    return true;
}


int main()
{
    int ct=3;
    while(ct--)
    {
        string st;cin>>st;
        if(isPalindrome(st))
        {
            cout<<"string is a palindrome."<<endl;
        }
        else {
            cout<<"string is not a palindrome."<<endl;
        }
    }


    return 0;
}

