#include <bits/stdc++.h>
using namespace std;
#define int long long
string intToBinary(int x) {
    if (x == 0) return "0";
    string s;
    while (x > 0) {
        s.push_back((x % 2) + '0');
        x /= 2;
    }
    reverse(s.begin(), s.end());
    return s;
}
int binaryStringToInt(const string& s) {
    return stoi(s, nullptr, 2);  // base = 2
}

int TurnOffSecondTurnOnRest(int x) {
    if (x <= 1) return x;

    string binary = intToBinary(x);
    
    int first = -1, second = -1;


    for (int i=0;i<binary.size();i++) {
        if (binary[i]=='1') {
            if (first == -1)
                first = i;
            else {
                second = i;
                break;
            }
        }
    }
    if (second == -1) return x;
    binary[second] = '0';
    
    for(int i=second+1;i<binary.size();i++) {
        binary[i] = '1';
    }
    int store = binaryStringToInt(binary);
    return store;

}

void solve()
{
    int n,k;cin>>n>>k;
    if(k%2==1)
    {
        for(int i=0;i<k;i++)
        {
            cout<<n<<" ";
        }cout<<endl;
    }
    else{

        int res1=TurnOffSecondTurnOnRest(n);
        int res2=n^res1;
        cout<<res1<<" "<<res2<<" ";
        for(int i=2;i<k;i++)
        {
            cout<<n<<" ";
        }cout<<endl;
    }
}

int32_t main()
{
    int tc;cin>>tc;
    while(tc--)
    {
        solve();
    }

    return 0;
}