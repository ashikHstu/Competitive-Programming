#include <bits/stdc++.h>

using namespace std;

int randomNumberBetwee(int a, int b)
{
    if (a > b)
        swap(a, b);
    return a + rand() % (b - a + 1);
}
int main(int argc, char *argv[])
{
    srand(atoi(argv[1]));
    int tc = randomNumberBetwee(1, 10);
    cout << tc << endl;
    for (int i = 0; i < tc; i++)
    {
        int n = randomNumberBetwee(0, 1000000000);
        int m = randomNumberBetwee(0, 1000000000);
        int a = randomNumberBetwee(0, 1000000000);
        cout << n << " " << m << " " << a << endl;
    }
}