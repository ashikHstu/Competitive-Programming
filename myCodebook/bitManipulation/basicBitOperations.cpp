#include <bits/stdc++.h>
using namespace std;

#define isOn(S, j) (S & (1 << j))
#define onBit(S, j) (S |= (1 << j))
#define clearBit(S, j) (S &= ~(1 << j)) // turn off j'th bit
#define toggleBit(S, j) (S ^= (1 << j))
#define lowBit(S) (S & (-S)) // if S==20, it will give 4 (16+4==20)
#define setAll(S, n) (S = (1 << n) - 1)
long long int highBit(long long v)
{
    if (v == 0)
        return 0;
    long long ct = 1;
    while (ct * 2 <= v)
    {
        ct *= 2;
    }
    return ct; // if v==20, it will give 16 (16+4==20)
}

int main()
{
    return 0;
}