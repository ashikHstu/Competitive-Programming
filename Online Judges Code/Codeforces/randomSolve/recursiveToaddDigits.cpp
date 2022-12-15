#include <bits/stdc++.h>
using namespace std;

int sumOfDigits(int n)
{
    if (n < 10)
        return n;
    return n % 10 + sumOfDigits(n / 10);
}

int findIndex(int ar[], int n)
{
    for (int i = 1; i < n; i++)
    {
        if (ar[i] < ar[i - 1])
            return i;
    }
}

void printNeed()
{
    for (int i = 1; i <= 500; i++)
    {
        if (i % 7 == 0 && i % 13 == 0)
        {
            cout << "Dhaka, Bangladesh\n";
        }
        else if (i % 7 == 0)
            cout << "Dhaka\n";
        else if (i % 13 == 0)
            cout << "Bangladesh\n";
        else
            cout << i << endl;
    }
}

void findCount()
{
    float sum = 0.0, j = 1.0, i = 2.0;
    while (i / j > 0.001)
    {
        j = j + j;
        sum = sum + i / j;
        printf("%f\n", sum);
    }
}

int main()
{
    findCount();
    int n;
    // cin >> n;
    // int r = sumOfDigits(n);
    // cout << r << endl;
    int ar[] = {2, 3, 1, 5, 6};
    // cout << findIndex(ar, 5) << endl;
    // printNeed();
}